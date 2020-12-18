namespace ConfigurationManager.Parsers.interfaces
{
    public interface IConfigurationParser
    {
        // this method gets the name of configuration file and returns parsed object
        public T Parse<T>(string configFileName) where T : new();
    }
}
