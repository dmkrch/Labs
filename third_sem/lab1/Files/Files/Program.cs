using System;
using System.Globalization;
using System.Reflection.Metadata.Ecma335;
using System.Text.RegularExpressions;

namespace Files
{
    class Program
    {
        public static void PrintMenu()
        {
            Console.WriteLine("1 - Create file");
            Console.WriteLine("2 - Delete file");
            Console.WriteLine("3 - Get information about file");
            Console.WriteLine("4 - Move file");
            Console.WriteLine("5 - Record to file");
            Console.WriteLine("6 - Read from file");
        }

        public static void PathInput(string path)
        {
            Regex pathPattern = new Regex(@"[C\|D]:\\(\w+\\?)*");

            while (true)
            {
                Console.WriteLine(@"Enter path. Example:  C:\asdfj\asd");

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
                
                switch(index)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
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
