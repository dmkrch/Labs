using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;
using System.Text.RegularExpressions;
using System.Globalization;
using System.Net;

namespace myLib
{ 
    /* class that tracks some changes in directory and process them in needed way  */
    public class Logger
    {
        FileSystemWatcher watcher;
        FileWatcherOptions options = new FileWatcherOptions();
        bool enabled = true;

        public Logger()
        {
            /* here we need to set our configuration options */
            
            string baseDirectoryName = AppDomain.CurrentDomain.BaseDirectory;
            string xmlConfigurationFileName = baseDirectoryName + "xmlConfig.xml";
            string jsonConfigurationFileName = baseDirectoryName + "jsonConfig.xml";

            if (File.Exists(xmlConfigurationFileName))
            {
                XmlParser parser = new XmlParser();
                
                /* adding xml parser to configuration manager */
                ConfigurationManager configurationManager = new ConfigurationManager(parser);

                options.EncryptingOptions = configurationManager.GetOptions<EncryptingOptions>(xmlConfigurationFileName);
                options.PathsOptions = configurationManager.GetOptions<PathsOptions>(xmlConfigurationFileName);
                options.CompressOptions = configurationManager.GetOptions<CompressOptions>(xmlConfigurationFileName);
            }
            else if (File.Exists(jsonConfigurationFileName))
            {
                /* code for json parser */
                JsonParser parser = new JsonParser();

                /* adding json parser to confiuration manager */
                ConfigurationManager configurationManager = new ConfigurationManager(parser);

                options.EncryptingOptions = configurationManager.GetOptions<EncryptingOptions>(jsonConfigurationFileName);
                options.PathsOptions = configurationManager.GetOptions<PathsOptions>(jsonConfigurationFileName);
                options.CompressOptions = configurationManager.GetOptions<CompressOptions>(jsonConfigurationFileName);
            }
            else
            {
                throw new IOException("Configuration file with incorrect extension");
            }


            watcher = new FileSystemWatcher(options.PathsOptions.ClientDirectory);
            watcher.Created += Watcher_Created;
        }

        public void Start()
        {
            watcher.EnableRaisingEvents = true;
            while (enabled)
            {
                Thread.Sleep(1000);
            }
        }

        public void Stop()
        {
            watcher.EnableRaisingEvents = false;
            enabled = false;
        }


        // добавление файлов
        private void Watcher_Created(object sender, FileSystemEventArgs e)
        {
            Thread.Sleep(1000);

            string fileName = e.Name;
            string filePath = e.FullPath;

            Regex filePattern = new Regex(@"Sales_[0-9]{4}_((0[1-9])|(1[0-2]))_((0[1-9])|(1[0-9])|(2[0-9])|(3[0-1]))_((0[0-9])|(1[0-9])|(2[0-3]))_[0-5][0-9]_[0-5][0-9].txt");
            //                                      year         month                       day                           hour                   minutes     seconds

            if (filePattern.IsMatch(fileName))
            {
                /* we need to encrypt the data of file */
                EncryptFile(fileName, filePath);

                /* now we need to compress this file and move this archieve to target directory */
                CompressAndMoveToTargetDir(fileName, filePath);

                /* now we need to decompress archieve(compressed file) by its name ( so we do search in function as well ) */
                DecompressFileToTargetDir(fileName, filePath);

                /* now we need to decrypt the data of file decompressed file */
                string newPath = GetPathOfFileInTargetDir(fileName);
                newPath += fileName;

                DecryptFile(fileName, newPath);
            }
        }

        private string GetGzFormat(string initFormat)
        {
            StringBuilder newPathString = new StringBuilder();

            for (int i = 0; i < initFormat.Length; ++i)
            {
                if (initFormat[i] != '.')
                {
                    newPathString.Append(initFormat[i]);
                }
                else
                {
                    /* here we use compress format from options that we set in constructor of logger */
                    string compressFormat = options.CompressOptions.CompressFormat;
                    newPathString.Append(compressFormat);
                    break;
                }
            }
            initFormat = newPathString.ToString();

            return initFormat;
        }

        private void EncryptFile(string fileName, string filePath)
        {
            /* here we use key from options that we set in constructor of logger */
            var key = options.EncryptingOptions.Key;
            string data;
            string encryptedData;

            using (StreamReader reader = new StreamReader(filePath))
            {
                data = reader.ReadToEnd();

                encryptedData = AesOperation.EncryptString(key, data);
            }

            using (StreamWriter writer = new StreamWriter(filePath, false))
            {
                writer.WriteLine(encryptedData);
            }
        }

        private void DecryptFile(string fileName, string filePath)
        {
            /* here we use key from options that we set in constructor of logger */
            var key = options.EncryptingOptions.Key;
            string data;
            string decryptedData;

            using (StreamReader reader = new StreamReader(filePath))
            {
                data = reader.ReadToEnd();
                decryptedData = AesOperation.DecryptString(key, data);
            }

            using (StreamWriter writer = new StreamWriter(filePath, false))
            {
                writer.WriteLine(decryptedData);
            }
        }

        private void CompressAndMoveToTargetDir(string fileName, string filePath)
        {
            string currPath = options.PathsOptions.TargetDirectory;
            currPath += @"\";

            string year = fileName.Substring(6, 4);
            string month = fileName.Substring(11, 2);
            string day = fileName.Substring(14, 2);
            string hour = fileName.Substring(17, 2);
            string minute = fileName.Substring(20, 2);
            string second = fileName.Substring(23, 2);

            string[] data = { year, month, day, hour, minute, second };

            foreach (string period in data)
            {
                currPath += period;

                DirectoryInfo dirInfo = new DirectoryInfo(currPath);

                if (!dirInfo.Exists)
                    dirInfo.Create();


                currPath += @"\";
            }

            currPath += fileName;

            // now currPath looks: D:\Git\Labs\third_sem\CSharp\lab2\TargetDirectory\...\blablabla.txt
            // we need to change it so that the end of path will have .gz format

            currPath = GetGzFormat(currPath);

            // now currPath is (...)\blablabla.gz

            FileOperations.CompressFile(filePath, currPath);
        }

        /* function searchs for directory that contains file in target directory */
        private string GetPathOfFileInTargetDir(string fileName)
        {
            string targetPathOfFile = options.PathsOptions.TargetDirectory;
            targetPathOfFile += @"\";

            string year = fileName.Substring(6, 4);
            string month = fileName.Substring(11, 2);
            string day = fileName.Substring(14, 2);
            string hour = fileName.Substring(17, 2);
            string minute = fileName.Substring(20, 2);
            string second = fileName.Substring(23, 2);

            string[] data = { year, month, day, hour, minute, second };

            foreach (string period in data)
            {
                targetPathOfFile += period;

                DirectoryInfo dirInfo = new DirectoryInfo(targetPathOfFile);

                if (!dirInfo.Exists)
                {
                    return "error";
                }

                targetPathOfFile += @"\";
            }

            string temp = targetPathOfFile;
            temp += fileName;

            if (File.Exists(temp))
                return targetPathOfFile;
            else
                return "error";
        }

        private void DecompressFileToTargetDir(string fileName, string filePath)
        {
            /* fileName is file.txt We need to change it to file.gz, because it is comressed in archieve */
            string gzFileName = GetGzFormat(fileName);

            /* now we need to decompress archieve. But before this, we need to get path to archieve, that has .gz format in TargetDirectory */
            string targetPathOfFileDir = GetPathOfFileInTargetDir(gzFileName);

            string compressedFile = targetPathOfFileDir;
            compressedFile += gzFileName;

            string decompressedFile = targetPathOfFileDir;
            decompressedFile += fileName;

            FileOperations.DecompressFile(compressedFile, decompressedFile);
        }
    }
}
