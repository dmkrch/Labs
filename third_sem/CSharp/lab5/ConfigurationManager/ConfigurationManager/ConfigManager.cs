using ConfigurationManager.Parsers.interfaces;

namespace ConfigurationManager
{
    public class ConfigManager
    {
        private readonly IConfigurationParser configParser;

        public ConfigManager(IConfigurationParser configParser)
        {
            this.configParser = configParser;
        }

        public T GetOptions<T>(string fileOptionsPath) where T : new()
        {
            return configParser.Parse<T>(fileOptionsPath);
        }
    }
}
