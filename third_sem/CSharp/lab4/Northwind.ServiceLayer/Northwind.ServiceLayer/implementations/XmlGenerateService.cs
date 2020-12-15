using Northwind.ServiceLayer.interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
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

        public void XmlGenerate<T>(IEnumerable<T> info)
        {
            try
            {
                List<T> orders = new List<T>(info);

                XmlSerializer formatter = new XmlSerializer(typeof(List<T>));

                using (FileStream stream = new FileStream(pathToXml, FileMode.OpenOrCreate))
                {
                    formatter.Serialize(stream, orders);
                }
            }
            catch (Exception trouble)
            {
                throw trouble;
            }
        }
    }
}
