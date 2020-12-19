using System;

namespace Northwind.Models
{
    public class Error
    {
        public Error(string exception, string message, DateTime time)
        {
            Exception = exception;
            Message = message;
            Time = time;
        }

        public string Exception { get; private set; }

        public string Message { get; private set; }

        public DateTime? Time { get; private set; }
    }
}
