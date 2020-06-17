using System;

namespace sharps_test
{ 
    class Program
    {
        static void Main()
        {
            Furniture shelf = new Furniture(25, "shelf", true);

            Console.WriteLine(shelf.GetCapacity());
        }
    }




}
