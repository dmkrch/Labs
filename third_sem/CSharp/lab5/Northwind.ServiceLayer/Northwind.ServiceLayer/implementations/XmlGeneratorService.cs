using Northwind.ServiceLayer.interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace Northwind.ServiceLayer.implementations
{
    public class XmlGenerateService<T> : IXmlGeneratorService
    {
        private readonly string pathToXml;

        public XmlGenerateService(string path)
        {
            pathToXml = path;
        }

        public void XmlGenerate<T>(IEnumerable<T> info)
        {
            try
            {
                List<T> orders = new List<T>(info);

                XmlSerializer formatter = new XmlSerializer(typeof(List<T>));

                using (FileStream fstream = new FileStream(pathToXml, FileMode.OpenOrCreate))
                {
                    formatter.Serialize(fstream, orders);
                }
            }
            catch (Exception trouble)
            {
                throw trouble;
            }

        }
    }
}
