using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace doctor
{
    class SurgeonList
    {

        public void ShowAllInfo(int id)
        {
            Console.WriteLine("#" + (surgeonList[id].GetId() + 1) + "      NAME: " + surgeonList[id].Name + "\t\tAGE: " + surgeonList[id].Age + "\n\tWORK EXPERIENCE: " + surgeonList[id].WorkExperience + "\tQUALIFICATION: " + surgeonList[id].Qualification);
            Console.WriteLine("\n");
            Console.WriteLine("\n\t" + surgeonList[id].Name + "'s operations:\n");
            surgeonList[id].ShowAllOperations();
        }

        public void AddSurgeon()
        {
            Console.Clear();

            string name = _fileInput[inputCounter++];
            int age = Int32.Parse(_fileInput[inputCounter++]);
            int workExperience = Int32.Parse(_fileInput[inputCounter++]);
            string qualification = _fileInput[inputCounter++];
            string scienceDegree = _fileInput[inputCounter++];
            inputCounter++;

            Surgeon surgeon = new Surgeon(name, age, workExperience, qualification, scienceDegree);
            surgeon.AddOperations();

            surgeonList.Add(surgeon);

            ++_counter;
        }

        public string GetName(int id)
        {
            return surgeonList[id].Name;
        }

        public int FindBestSurgeon(string title)
        {
            int id = -1;
            double currentPercentage = -1;
            double maxPercentage = -1;

            for (int i = 0; i < 5; ++i)
            {
                currentPercentage = surgeonList[i].GetOperationPercentage(title);

                if (currentPercentage > maxPercentage)
                {
                    maxPercentage = currentPercentage;
                    id = i;
                }
            }

            
            return id;
        }

        public int PerformOperation()
        {
            int result = -1;
            Random rnd = new Random();


            Console.Write("What operation do u need to perform? ");
            string title = Console.ReadLine();

            Console.WriteLine("Which doctor you want to choose? ");
            int id = Int32.Parse(Console.ReadLine()) - 1;

            if (surgeonList[id].GetOperationPercentage(title) != -1)
            {
                Console.Write("The doctor " + surgeonList[id].Name + " has " + surgeonList[id].GetOperationPercentage(title) * 100 + " % on success.\nDo u want to perform the operation?(1 - yes, 2 - no)  ");
                int choice = Int32.Parse(Console.ReadLine());

                if (choice == 1)
                {
                    int number = 0;

                    number = rnd.Next(1, 101);

                    if (number <= (int)(surgeonList[id].GetOperationPercentage(title) * 100 + 1))
                    {
                        Console.Clear();
                        for (int i = 0; i < 20; ++i)
                        {
                            Console.Write(".");
                            System.Threading.Thread.Sleep(200);
                        }

                        surgeonList[id].AddStatisticOperation(title, true);

                        result = 1;
                    }

                    else
                    {
                        Console.Clear();
                        for (int i = 0; i < 20; ++i)
                        {
                            Console.Write(".");
                            System.Threading.Thread.Sleep(200);
                        }

                        surgeonList[id].AddStatisticOperation(title, false);

                        result = 0;
                    }
                }

                else
                {
                    result = -1;
                }

                return result;
            }
            else
            {
                Console.WriteLine("This doctor does not perform such operations\n");
                return -2;
            }
        }

        private List <Surgeon> surgeonList = new List <Surgeon>();
        private static int _counter = 0;
        private string[] _fileInput = File.ReadAllLines("surgeonInput.txt");
        private static int inputCounter = 1;
    }
}