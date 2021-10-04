using ConfigManager.Parsers.interfaces;
using System;
using System.IO;
using System.Xml.Linq;
using System.Xml.Schema;
using System.Xml.Serialization;

namespace ConfigManager.Parsers.parsers
{
    public class XmlParser : IConfigurationParser
    {
        /* the only method of parser's interface we must implement */
        public T Parse<T>(string xmlConfigurationFileName) where T : new()
        {
            T options = new T();

            try
            {
                Validate(xmlConfigurationFileName);

                string xmlInner = "";

                /* creating formatter for serialization */
                XmlSerializer formatter = new XmlSerializer(typeof(T));

                /* using linq to xml classes */
                XDocument xDoc = XDocument.Load(xmlConfigurationFileName);

                /* getting all nodes of root node to list of nodes */
                var nodes = xDoc.Document.Descendants();

                foreach (var node in nodes)
                {
                    if (node.Name == typeof(T).Name)
                    {
                        xmlInner = node.ToString();
                        break;
                    }
                }

                using (TextReader tReader = new StringReader(xmlInner))
                {
                    options = (T)formatter.Deserialize(tReader);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            return options;
        }


        /* method to check whether xml file is correct. Checking xsd file */
        private void Validate(string xmlConfigFileName)
        {
            XmlSchemaSet schemas = new XmlSchemaSet();
            schemas.Add(null, Path.ChangeExtension(xmlConfigFileName, "xsd"));      // in schemas - path of xsd file

            XDocument xDoc = XDocument.Load(xmlConfigFileName);                     // loading xml file to xDoc

            xDoc.Validate(schemas, (sender, validationEventArgs) =>                 // main method to check xml file according to xsd file
            {
                if (validationEventArgs.Message.Length != 0)
                {
                    throw validationEventArgs.Exception;
                }
            });
        }
    }
}
