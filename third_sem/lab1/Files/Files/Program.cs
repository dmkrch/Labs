using System;
using System.Globalization;
using System.Reflection.Metadata.Ecma335;
using System.Text.RegularExpressions;

namespace Files
{
    class Program
    {
        public static void InputFilePath(ref string path)
        {
            Regex pathPattern = new Regex(@"D:\\(\w+\\?)*");

            while (true)
            {
                Console.WriteLine(@"Enter path of file. Example:  D:\asdfj\asd");

                path = Console.ReadLine();

                if (pathPattern.IsMatch(path))
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Error input :(");
                }
            }
        }

        public static void InputDirectoryPath(ref string path)
        {
            Regex pathPattern = new Regex(@"D:\\(\w+\\?)*\\");

            while (true)
            {
                Console.WriteLine(@"Enter path. Example:  D:\asdfj\asd\");

                path = Console.ReadLine();

                if (pathPattern.IsMatch(path))
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Error input :(");
                }
            }
        }

        public static void PrintMenu()
        {
            Console.WriteLine("1 - Create file");
            Console.WriteLine("2 - Delete file");
            Console.WriteLine("3 - Get information about file");
            Console.WriteLine("4 - Move file");
            Console.WriteLine("5 - Record to file");
            Console.WriteLine("6 - Read from file");
            Console.WriteLine("7 - Exit");
        }



        static void Main(string[] args)
        {
            while (true)
            {
                PrintMenu();

                int index = 0;

                while (true)
                {
                    string line = Console.ReadLine();

                    try
                    {
                        index = Int32.Parse(line);
                    }
                    catch
                    {
                        Console.WriteLine("wrong input");
                        continue;
                    }
                    break;
                }

                string path = null;
                string pathTo = null;
                string pathFrom = null;
                string name = null;

                switch(index)
                {
                    case 1:
                        Console.Write("Enter name of file: ");
                        name = Console.ReadLine();
                        InputDirectoryPath(ref path);
                        FileOperations.CreateFile(path, name);
                        break;
                    case 2:
                        InputFilePath(ref path);
                        FileOperations.DeleteFile(path);
                        break;
                    case 3:
                        InputFilePath(ref path);
                        FileOperations.GetFileInformation(path);
                        break;
                    case 4:
                        InputFilePath(ref pathFrom);
                        InputFilePath(ref pathTo);
                        FileOperations.MoveFile(pathFrom, pathTo);
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        Environment.Exit(0);
                        break;

                    default:
                        Console.WriteLine("No such index\n");
                        break;
                }
                Console.WriteLine("press key to continue...");
                Console.ReadKey();
                Console.Clear();
            }
        }
    }
}
