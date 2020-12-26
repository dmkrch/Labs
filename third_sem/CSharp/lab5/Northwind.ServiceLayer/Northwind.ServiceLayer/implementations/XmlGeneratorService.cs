using Northwind.ServiceLayer.interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;
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

        public async Task XmlGenerate<T>(IEnumerable<T> info)
        {
            await Task.Run(() =>
            {
                List<T> orders = new List<T>(info);

                XmlSerializer formatter = new XmlSerializer(typeof(List<T>));

                using (FileStream fstream = new FileStream(pathToXml, FileMode.OpenOrCreate))
                {
                    formatter.Serialize(fstream, orders);
                }
            });
        }
    }
}
