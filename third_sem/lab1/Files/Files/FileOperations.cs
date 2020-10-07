using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

namespace Files
{
    static class FileOperations
    { 
        public static void GetFileInformation(string path)
        {
            FileInfo fileInf = new FileInfo(path);

            if (fileInf.Exists)
            {
                Console.WriteLine("\nName of file: {0}", fileInf.Name);
                Console.WriteLine("Creature time: {0}", fileInf.CreationTime);
                Console.WriteLine("Size: {0}\n", fileInf.Length);
            }
            else
            {
                Console.WriteLine("\nNo such file\n");
            }
        }

        public static void CreateFile(string path, string name)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            if (dirInfo.Exists)
            {
                path += name;
                File.Create(path);
            }
            else
            {
                Console.WriteLine("No such directory");
                return;
            }
        }

        public static void DeleteFile(string path)
        {
            if (File.Exists(path))
            {
                File.Delete(path);
                Console.WriteLine("Deleted!");
            }
            else
            {
                Console.WriteLine("No such file");
            }
        }

        public static void MoveFile(string pathFrom, string pathTo)
        {
            if(File.Exists(pathFrom))
            {
                File.Move(pathFrom, pathTo);
            }
        }
    }
}
