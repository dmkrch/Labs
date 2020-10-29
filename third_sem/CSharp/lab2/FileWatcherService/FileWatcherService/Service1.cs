using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Threading;
using System.Text.RegularExpressions;
using System.Globalization;

namespace FileWatcherService
{
    public partial class Service1 : ServiceBase
    {
        Logger logger;
        public Service1()
        {
            InitializeComponent();
            this.CanStop = true;
            this.CanPauseAndContinue = true;
            this.AutoLog = true;
        }

        protected override void OnStart(string[] args)
        {
            logger = new Logger();
            Thread loggerThread = new Thread(new ThreadStart(logger.Start));
            loggerThread.Start();
        }

        protected override void OnStop()
        {
            logger.Stop();
            Thread.Sleep(1000);
        }
    }


    class Logger
    {
        FileSystemWatcher watcher;
        object obj = new object();
        bool enabled = true;
        public Logger()
        {
            watcher = new FileSystemWatcher(@"D:\Git\Labs\third_sem\CSharp\lab2\ClientDirectory");
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
            string fileName = e.Name;
            string filePath = e.FullPath;
  
            Regex filePattern = new Regex(@"Sales_[0-9]{4}_((0[1-9])|(1[0-2]))_((0[1-9])|(1[0-9])|(2[0-9])|(3[0-1]))_((0[0-9])|(1[0-9])|(2[0-3]))_[0-5][0-9]_[0-5][0-9].txt");
            //                                      year         month                       day                           hour                   minutes     seconds

            if(filePattern.IsMatch(fileName))
            {
                /* we need to encrypt the data of file */ 
                EncryptFile(fileName, filePath);

                /* now we need to compreess this file and move zip file to target directory */
                CompressAndMove(fileName, filePath);


                
            }
        }

        private void EncryptFile(string fileName, string filePath)
        {
            var key = "b14ca5898a4e4133bbce2ea2315a1916";
            string data;
            string encryptedData;

            lock (obj)
            {
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
        }

        private void CompressAndMove(string fileName, string filePath)
        {
            string currPath = @"D:\Git\Labs\third_sem\CSharp\lab2\TargetDirectory\";

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

            // now targetPath looks: D:\Git\Labs\third_sem\CSharp\lab2\TargetDirectory\...\blablabla.txt
            // we need to change it so that the end of path will have .gz format
            StringBuilder newPathString = new StringBuilder();

            for (int i = 0; i < currPath.Length; ++i)
            {
                if (currPath[i] != '.')
                {
                    newPathString.Append(currPath[i]);
                }
                else
                {
                    newPathString.Append(".gz");
                    break;
                }
            }
            currPath = newPathString.ToString();
            // now targetPath is (...)\blablabla.gz

            FileOperations.CompressFile(filePath, currPath);
        }
    }
}
