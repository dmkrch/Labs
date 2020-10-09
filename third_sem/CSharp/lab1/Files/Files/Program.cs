using System;
using System.Globalization;
using System.IO;
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
            Regex pathPattern;

            while (true)
            {
                path = Console.ReadLine();

                if (path.Length <= 3)
                {
                    pathPattern = new Regex(@"D:\\(\w+\\?)*");
                }
                else
                {
                    pathPattern = new Regex(@"D:\\(\w+\\?)*\\");
                }

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

        public static void PrintStatusCodeMessage(FileOperations.StatusCode code)
        {
            switch (code)
            {
                case FileOperations.StatusCode.SuccessPrint:
                    Console.WriteLine("Success");
                    break;

                case FileOperations.StatusCode.DirectoryNotExist:
                    Console.WriteLine("Directory doesn't exist");
                    break;

                case FileOperations.StatusCode.FileNotExist:
                    Console.WriteLine("File doesn't exist");
                    break;

                case FileOperations.StatusCode.DirectorySourceNotExist:
                    Console.WriteLine("Source directory doesnt exist");
                    break;

                case FileOperations.StatusCode.DirectoryDestinationNotExist:
                    Console.WriteLine("Destination directory doesnt exist");
                    break;

                case FileOperations.StatusCode.MoveError:
                    Console.WriteLine("Failed to move file");
                    break;
            }
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
                string data = null;
                FileOperations.StatusCode statusCode;

                switch (index)
                {
                    case 1:
                        Console.Write("Enter name of file: ");
                        name = Console.ReadLine();

                        Console.WriteLine(@"Enter path. Example:  D:\asdfj\asd\");
                        InputDirectoryPath(ref path);

                        statusCode = FileOperations.CreateFile(path, name);
                        PrintStatusCodeMessage(statusCode);
                        break;


                    case 2:
                        Console.WriteLine(@"Enter path of file. Example:  D:\asdfj\asd");
                        InputFilePath(ref path);

                        statusCode = FileOperations.DeleteFile(path);
                        PrintStatusCodeMessage(statusCode);
                        break;


                    case 3:
                        Console.WriteLine(@"Enter path of file. Example:  D:\asdfj\asd");
                        InputFilePath(ref path);

                        statusCode = FileOperations.GetFileInformation(path);
                        PrintStatusCodeMessage(statusCode);
                        break;


                    case 4:
                        Console.Write("Enter name of file: ");
                        name = Console.ReadLine();

                        Console.WriteLine(@"Enter path to directory of file. Example:  D:\asdfj\asd\");
                        InputDirectoryPath(ref pathFrom);
                        
                        Console.WriteLine(@"Enter destination directory of file. Example:  D:\asdfj\asd1\");
                        InputDirectoryPath(ref pathTo);

                        statusCode = FileOperations.MoveFile(pathFrom, pathTo, name);
                        PrintStatusCodeMessage(statusCode);
                        break;


                    case 5:
                        Console.WriteLine("Enter data you want to record: ");
                        data = Console.ReadLine();

                        Console.WriteLine(@"Enter path of file. Example:  D:\asdfj\asd");
                        InputFilePath(ref path);

                        statusCode = FileOperations.AppendFile(path, data);
                        PrintStatusCodeMessage(statusCode);
                        break;


                    case 6:
                        Console.WriteLine(@"Enter path of file. Example:  D:\asdfj\asd");
                        InputFilePath(ref path);

                        statusCode = FileOperations.ReadFromFile(path, ref data);
                        PrintStatusCodeMessage(statusCode);

                        Console.WriteLine("Your data: {0}", data);
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
