using System;

namespace lab2_1
{
    class Program
    {
        static void Main()
        {
            string date_1 = null;
            string date_2 = null;
            int[] arr_1 = new int [10];
            int[] arr_2 = new int [10];

            for (int i = 0; i < 10; ++i)
                arr_1[i] = 0;

            for (int i = 0; i < 10; ++i)
                arr_2[i] = 0;

            DateTime date_now = DateTime.Now;
            date_1 = date_now.ToString();
            date_2 = date_now.ToString("R");

            for (int i = 0; i < date_1.Length; ++i)
            {
                if (date_1[i] > 47 && date_1[i] < 58)
                {
                    char ch = date_1[i];

                    ++arr_1[ch - 48];
                }
            }

            for (int i = 0; i < date_2.Length; ++i)
            {
                if (date_2[i] > 47 && date_2[i] < 58)
                {
                    char ch = date_2[i];

                    ++arr_2[ch - 48];
                }
            }

            Console.WriteLine("1st format:  " + date_1);
            
            for (int i = 0; i < 10; ++i)
                Console.WriteLine("\tnumber of " + i + " = " + arr_1[i]);

            Console.WriteLine("\n\n2nd format:  " + date_2);

            for (int i = 0; i < 10; ++i)
                Console.WriteLine("\tnumber of " + i + " = " + arr_2[i]);
        }
    }
}
