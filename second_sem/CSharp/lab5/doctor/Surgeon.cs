using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace doctor
{
    class Surgeon : Doctor
    {
        public Surgeon(string name, int age, int workExperience, string qualification, string scienceDegree)
        {
            Name = name;
            Age = age;
            WorkExperience = workExperience;
            Qualification = qualification;
            ScienceDegree = scienceDegree;

            ++_counter;
            _id = _counter;
        }

        public int GetId()
        {
            return _id;
        }

        public void AddOperations()
        {
            int amountOfOperations = Int32.Parse(_fileInput[0]);

            for (int i = 0; i < amountOfOperations; ++i)
            {
                string title = _fileInput[inputCounter++];
                string difficulty = _fileInput[inputCounter++];
                double successOperations = Double.Parse(_fileInput[inputCounter++]);
                double complicatedOperations = Double.Parse(_fileInput[inputCounter++]);

                inputCounter++;

                Operation operation = new Operation(title, difficulty, successOperations, complicatedOperations);
                operationsList.Add(operation);
            }
        }

        public void ShowAllOperations()
        {
            for (int i = 0; i < 3; ++i)
            {
                Console.WriteLine("\tTITLE: " + operationsList[i].Title + "\tDIFFICULTY: " + operationsList[i].Difficulty + "\n\tSUCCESSED: " + operationsList[i].SuccessOperations + "\t\tCOMPLICATED: " + operationsList[i].ComplicatedOperations);
            }
        }

        public double GetOperationPercentage(string title)
        {
            double percentage = -1;

            for (int i = 0; i < 3; ++i)
            {
                if (operationsList[i].Title == title)
                {
                    percentage = operationsList[i].SuccessOperations / (operationsList[i].SuccessOperations + operationsList[i].ComplicatedOperations);
                }
            }

            return percentage;
        }

        public void AddStatisticOperation(string title, bool state)
        {
            for (int i = 0; i < 3; ++i)
            {
                if (operationsList[i].Title == title)
                {
                    if (state == true)
                    {
                        operationsList[i].SuccessOperations++;
                    }
                    else
                    {
                        operationsList[i].ComplicatedOperations++;
                    }
                }
            }
        }


        private int _id = 0;
        private static int _counter = -1;
        private List<Operation> operationsList = new List<Operation>();
        private string[] _fileInput = File.ReadAllLines("operationInput.txt");
        private static int inputCounter = 1;
    }
}
