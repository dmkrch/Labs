namespace myLib
{
    public class ConfigurationManager
    {
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
