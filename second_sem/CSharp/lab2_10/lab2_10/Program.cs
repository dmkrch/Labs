using System;

namespace lab2_10
{
    class Program
    {
        static void Main()
        {
            string line;
            double number = 0;
            double numbers_before_dot = 0;
            bool status_dot = false;

            Console.WriteLine("Write number  ");
            line = Console.ReadLine();

            for (int i = 0; i < line.Length; ++i) // counting numers before dot
            {
                if (line[i] > 47 && line[i] < 58)
                    ++numbers_before_dot;
                else if (line[i] == '.')
                    break;
            }


            for (int i = 0; i < line.Length; ++i)
            {
                if (line[i] > 47 && line[i] < 58 && status_dot == false)
                {
                    number += Math.Pow(10.0, numbers_before_dot - 1) * (line[i] - 48);
                    numbers_before_dot--;
                }

                else if (line[i] == '.' || status_dot == true)
                {
                    status_dot = true;

                    if (line[i] == '.')
                        numbers_before_dot--;

                    else
                    {
                        number += Math.Pow(10.0, numbers_before_dot) * (line[i] - '0');
                        numbers_before_dot--;
                    }
                }
            }

            Console.WriteLine(number);
        }
	}
}
