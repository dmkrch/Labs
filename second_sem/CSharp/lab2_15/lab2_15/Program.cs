using System;
using System.Text;
//using static System.String;

namespace lab2_15
{
    class Program
    {
        static void Main()
        {
            string line = null;
            string alphabet = "aeiouy";

            Console.WriteLine("line: ");
            line = Console.ReadLine();

            StringBuilder lineEdited;// = new StringBuilder();


            for (int i = 0; i < line.Length; ++i)
            {
                bool isEdited = false;
                isEdited = false;

                for (int k = 0; k < alphabet.Length; ++k)
                {
                    if (line[i] == alphabet[k])
                    {
                        char ch = line[i];

                        lineEdited.Append((char)(ch));
                        lineEdited.Append((char)(ch + 1));

                        ++i;
                        isEdited = true;
                        break;
                    }
                }

                if (isEdited == false)
                {
                    lineEdited.Append(line[i]);
                }
            }

            Console.WriteLine("line edited: " + lineEdited);
        }
    }
}
