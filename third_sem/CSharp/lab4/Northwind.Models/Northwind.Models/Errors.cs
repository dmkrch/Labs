using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.Models
{
    public class Errors
    {
        public string Exception { get; private set; }

        public string Message { get; private set; }

        public DateTime? Time { get; private set; }

        public Errors(string exception, string message, DateTime time)
        {
            Exception = exception;
            Message = message;
            Time = time;
        }
    }
}
