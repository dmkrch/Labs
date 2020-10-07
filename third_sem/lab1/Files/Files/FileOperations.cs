using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Files
{
    static class FileOperations
    {
        public static void PrintHello()
        {
            Console.WriteLine("Hello, world\n");
        }

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
            //File file = new File(path);
        }
    }
}
