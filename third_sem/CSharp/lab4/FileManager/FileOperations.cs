using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileManager
{
    public class FileOperations
    {
        public enum StatusCode
        {
            // if operation was successful
            Success,
            SuccessPrint,

            // if operation was failed
            Error,
            ErrorPrint,

            // codes for files
            FileNotExist,
            FileIsBeingUsed,
            MoveError,

            //codes for directories
            DirectoryNotExist,
            DirectoryDestinationNotExist,
            DirectorySourceNotExist,
        }


        public static StatusCode GetFileInformation(string path)
        {
            FileInfo fileInf = new FileInfo(path);

            if (fileInf.Exists)
            {
                Console.WriteLine("\nName of file: {0}", fileInf.Name);
                Console.WriteLine("Creature time: {0}", fileInf.CreationTime);
                Console.WriteLine("Size: {0}\n", fileInf.Length);

                return StatusCode.Success;
            }
            else
            {
                return StatusCode.FileNotExist;
            }
        }

        public static StatusCode CreateFile(string path, string name)
        {
            if (Directory.Exists(path))
            {
                path += name;
                File.Create(path).Dispose();

                return StatusCode.SuccessPrint;
            }
            else
            {
                return StatusCode.DirectoryNotExist;
            }
        }

        public static StatusCode DeleteFile(string path)
        {
            if (File.Exists(path))
            {
                File.Delete(path);
                return StatusCode.SuccessPrint;
            }
            else
            {
                return StatusCode.FileNotExist;
            }
        }

        public static StatusCode MoveFile(string pathFrom, string pathTo, string name)
        {
            if (Directory.Exists(pathFrom))
            {
                pathFrom += name;

                if (File.Exists(pathFrom))
                {
                    if (Directory.Exists(pathTo))
                    {
                        pathTo += name;
                        File.Move(pathFrom, pathTo);

                        return StatusCode.SuccessPrint;
                    }
                    else
                    {
                        return StatusCode.DirectoryDestinationNotExist;
                    }
                }
                else
                {
                    return StatusCode.FileNotExist;
                }
            }
            else
            {
                return StatusCode.DirectorySourceNotExist;
            }
        }

        public static StatusCode ReadFromFile(string path, ref string data)
        {
            if (File.Exists(path))
            {
                using (FileStream fstream = File.OpenRead(path))
                {
                    byte[] array = new byte[fstream.Length];
                    // считываем данные
                    fstream.Read(array, 0, array.Length);
                    // декодируем байты в строку
                    data = System.Text.Encoding.Default.GetString(array);

                    return StatusCode.SuccessPrint;
                }
            }
            else
            {
                return StatusCode.FileNotExist;
            }
        }

        public static StatusCode CompressFile(string sourceFile, string compressedFile)
        {
            // поток для чтения исходного файла
            using (FileStream sourceStream = new FileStream(sourceFile, FileMode.OpenOrCreate))
            {
                // поток для записи сжатого файла
                using (FileStream targetStream = File.Create(compressedFile))
                {
                    // поток архивации
                    using (GZipStream compressionStream = new GZipStream(targetStream, CompressionMode.Compress))
                    {
                        sourceStream.CopyTo(compressionStream); // копируем байты из одного потока в другой
                        Console.WriteLine("Сжатие файла {0} завершено. Исходный размер: {1}  сжатый размер: {2}.",
                            sourceFile, sourceStream.Length.ToString(), targetStream.Length.ToString());

                        return StatusCode.Success;
                    }
                }
            }
        }

        public static StatusCode DecompressFile(string compressedFile, string targetFile)
        {
            // поток для чтения из сжатого файла
            using (FileStream sourceStream = new FileStream(compressedFile, FileMode.OpenOrCreate))
            {
                // поток для записи восстановленного файла
                using (FileStream targetStream = File.Create(targetFile))
                {
                    // поток разархивации
                    using (GZipStream decompressionStream = new GZipStream(sourceStream, CompressionMode.Decompress))
                    {
                        decompressionStream.CopyTo(targetStream);
                        Console.WriteLine("Восстановлен файл: {0}", targetFile);

                        return StatusCode.Success;
                    }
                }
            }
        }
    }
}
