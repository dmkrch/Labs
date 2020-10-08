using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

namespace Files
{
    static class FileOperations
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

        public static StatusCode AppendFile(string path, string data)
        {
            if (File.Exists(path))
            {
                using (FileStream fstream = new FileStream(path, FileMode.Append))
                {
                    byte[] array = System.Text.Encoding.Default.GetBytes(data);
                    fstream.Write(array);

                    return StatusCode.SuccessPrint;
                }
            }
            else
            {
                return StatusCode.FileNotExist;
            }
        }

        public static StatusCode ReadFromFile(string path, ref string data)
        {
            if (File.Exists(path))
            {
                using (FileStream fstream = new FileStream(path, FileMode.Append))
                {
                    byte[] array = System.Text.Encoding.Default.GetBytes(data);
                    //fstream.Read();

                    return StatusCode.SuccessPrint;
                }
            }
            else
            {
                return StatusCode.FileNotExist;
            }
        }
    }
}
