using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

namespace lab7
{
    class RationalNumber : IEquatable<RationalNumber>
    {
        public RationalNumber(double numerator, double denomintaor)
        {
            Numerator = numerator;
            Denominator = denomintaor;

            Value = Numerator / Denominator;
        }

        public RationalNumber(double value)
        {
            Value = value;
        }

        public RationalNumber() { }

        public double Numerator { get; set; }

        public double Denominator { get; set; }

        public double Value { get; set; }

        //method of IEquatable interface to comparise objects
        public bool Equals(RationalNumber other)
        {
            if (other.Value == null)
                return false;

            if (this.Value == other.Value)
                return true;
            else
                return false;
        }



        // method for getting object by string input in different formats
        public static RationalNumber GetObjectByString(string inputString)
        {
            string pattern1 = @"\d*\.\d*"; // 0.4
            string pattern2 = @"\d*,\d*";  // 0,4
            string pattern3 = @"\d*/\d*";  // 2/5

            if (Regex.IsMatch(inputString, pattern1) || Regex.IsMatch(inputString, pattern2)) // this is for pattern1 and pattern2 - 0.4 || 0,4
            {
                double value = Double.Parse(inputString.Replace(',', '.'), CultureInfo.InvariantCulture);

                return new RationalNumber(value);
            }

            else if (Regex.IsMatch(inputString, pattern3)) // this is for pattern3 - 2/5
            {
                int numerator = 0;
                int denominator = 0;

                StringBuilder numeratorString = new StringBuilder();
                StringBuilder denominatorString = new StringBuilder();

                bool beforeDot = true;


                for (int i = 0; i < inputString.Length; ++i)
                {
                    if (inputString[i] == '/')
                    {
                        beforeDot = false;
                        continue;
                    }

                    if (beforeDot == false)
                    {
                        denominatorString.Append(inputString[i]);
                    }

                    else
                    {
                        numeratorString.Append(inputString[i]);
                    }
                }


                numerator = Convert.ToInt32(numeratorString.ToString());
                denominator = Convert.ToInt32(denominatorString.ToString());

                return new RationalNumber(numerator, denominator);
            }
            
            else
            {
                return new RationalNumber(0, 1);
            }
        }



        //overload for object method "ToString" that takes argument (A\B\C) to display string in different formats
        public override string ToString()
        {
            return ToString("A");
        }

        public string ToString(string par)
        {
            if (string.IsNullOrEmpty(par))
                par = "A";

            switch (par)
            {
                case "A":
                    return string.Format(Value.ToString());  
                case "B":
                    return string.Format("{0:0.000}", Value);
                case "C":
                    return string.Format("{0:#.0}", Value);
                default:
                    string msg = string.Format("'{0}' is an invalid format string", par);
                    throw new ArgumentException(msg);
            }
        }



        // overload of operators
        public static RationalNumber operator +(RationalNumber n1, RationalNumber n2)
        {
            return new RationalNumber { Value = n1.Value + n2.Value };
        }

        public static RationalNumber operator -(RationalNumber n1, RationalNumber n2)
        {
            return new RationalNumber { Value = n1.Value - n2.Value };
        }

        public static RationalNumber operator *(RationalNumber n1, RationalNumber n2)
        {
            return new RationalNumber { Value = n1.Value * n2.Value };
        }

        public static RationalNumber operator /(RationalNumber n1, RationalNumber n2)
        {
            return new RationalNumber { Value = n1.Value / n2.Value };
        }

        public static bool operator <(RationalNumber n1, RationalNumber n2)
        {
            return n1.Value < n2.Value;
        }

        public static bool operator >(RationalNumber n1, RationalNumber n2)
        {
            return n1.Value > n2.Value;
        }

        public static bool operator ==(RationalNumber n1, RationalNumber n2)
        {
            return n1.Value == n2.Value;
        }

        public static bool operator !=(RationalNumber n1, RationalNumber n2)
        {
            return n1.Value != n2.Value;
        }



        // overload explicit\implicit castings to other types
        public static implicit operator RationalNumber(double value)
        {
            return new RationalNumber { Value = value };
        }

        public static implicit operator RationalNumber(int value)
        {
            return new RationalNumber { Value = value };
        }

        public static explicit operator double(RationalNumber numb)
        {
            return numb.Value;
        }

        public static explicit operator int(RationalNumber numb)
        {
            return (int)numb.Value;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            RationalNumber number1 = new RationalNumber(3, 5); // example for constructor                                                            
            RationalNumber numbGetByMethod1 = RationalNumber.GetObjectByString("2/5"); // examples for method that takes string and returns          
            RationalNumber numbGetByMethod2 = RationalNumber.GetObjectByString("2.5"); // object (uses regular expressions)
            RationalNumber numbGetByMethod3 = RationalNumber.GetObjectByString("4/10");


            Console.WriteLine(numbGetByMethod1 > numbGetByMethod2); // examples for overloading operators
            Console.WriteLine(numbGetByMethod1 < numbGetByMethod2);
            Console.WriteLine(numbGetByMethod1 + numbGetByMethod2);


            Console.WriteLine(numbGetByMethod1.ToString("A")); // example for overloading ToString method.
            Console.WriteLine(numbGetByMethod2.ToString("B")); // it also takes parameter(A\B\C) to 
            Console.WriteLine(numbGetByMethod1.ToString("C")); // display string in different formats


            if(numbGetByMethod1.Equals(numbGetByMethod3))      // example for overloading the interface of comparison
               Console.WriteLine("numbers are equal");


            int x = (int)numbGetByMethod2;                     // examples for explicit\implicit casting to other types
            Console.WriteLine(x);

            double y = (double)numbGetByMethod1;
            Console.WriteLine(y);

            RationalNumber number2 = 24;
            RationalNumber number5 = 2.4;

            Console.WriteLine(number5.ToString("A"));
        }
    }
}
