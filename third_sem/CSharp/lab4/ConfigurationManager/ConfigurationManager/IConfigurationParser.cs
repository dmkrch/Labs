using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyConfigurationManager
{
    public interface IConfigurationParser
    {
        // this method gets the name of configuration file and returns parsed object
        public T Parse<T>(string configFileName) where T : new();
    }
}
