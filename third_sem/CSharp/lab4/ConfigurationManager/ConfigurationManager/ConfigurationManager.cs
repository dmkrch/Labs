using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyConfigurationManager
{
    public class ConfigurationManager
    {
        public ConfigurationManager()
        { }

        private readonly IConfigurationParser configParser;

        public ConfigurationManager(IConfigurationParser configParser)
        {
            this.configParser = configParser;
        }

        public T GetOptions<T>(string fileOptionsPath) where T : new()
        {
            return configParser.Parse<T>(fileOptionsPath);
        }
    }
}
