using System;

namespace lab3_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Furniture shelf = new Furniture(25, "shelf", true);

           
            Wardrobe ward = new Wardrobe();

            ward.GetCapacity();
        }
    }
}
