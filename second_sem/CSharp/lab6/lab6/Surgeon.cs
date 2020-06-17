﻿using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace lab6
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
            Id = _counter;
        }

        public ISchedule schedule { get; set; }

        public int Id { get; set; }


        public delegate void displayMes(string mes);
        public event displayMes displayMessage;


        public void SortOperationsByName()
        {
            operationsList.Sort();
        }
       
        public void SortOperationsByLength()
        {
            operationsList.Sort(new OperationComparer());
        }

        public void AddOperation(Operation operation)
        {
                operationsList.Add(operation);
        }

        public void ShowAllOperations()
        {
            for (int i = 0; i < operationsList.Count; ++i)
            {
                displayMessage?.Invoke("\tTITLE: " + operationsList[i].Title + "\tDIFFICULTY: " + operationsList[i].Difficulty + "\n\tSUCCESSED: " + operationsList[i].SuccessOperations + "\t\tCOMPLICATED: " + operationsList[i].ComplicatedOperations);
            }
        }

        public double GetOperationPercentage(string title)
        {
            double percentage = -1;

            for (int i = 0; i < operationsList.Count; ++i)
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
            for (int i = 0; i < operationsList.Count; ++i)
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


        private static int _counter = -1;
        private List<Operation> operationsList = new List<Operation>();
    }
}
