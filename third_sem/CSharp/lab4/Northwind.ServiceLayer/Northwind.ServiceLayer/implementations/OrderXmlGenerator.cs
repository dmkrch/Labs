using Northwind.Models;
using Northwind.Models.SearchModels;
using Northwind.ServiceLayer.interfaces;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;

namespace Northwind.ServiceLayer.implementations
{
    public class OrderXmlGenerator : IXmlGeneratorService
    {
        public void GenerateXml(SearchResult<Order> searchResult, string targerDirectoryPath, string xmlFileName)
        {
            List<Order> list = new List<Order>();
            foreach (var variable in searchResult.Entities)
            {
                list.Add(variable);
            }

            XmlSerializer formatter = new XmlSerializer(typeof(List<Order>));
            using (FileStream fs = new FileStream(Path.Combine(targerDirectoryPath, xmlFileName), FileMode.Append))
            {
                formatter.Serialize(fs, list);
            }
        }

        public void GenerateXsd(string targetDirectoryPath, string xmlFileName, string xsdFileName)
        {
            XmlReader reader = XmlReader.Create(Path.Combine(targetDirectoryPath, xmlFileName));
            XmlSchemaSet schemaSet = new XmlSchemaSet();
            XmlSchemaInference schema = new XmlSchemaInference();
            schemaSet = schema.InferSchema(reader);
            reader.Dispose();

            XmlSerializer formatter = new XmlSerializer(typeof(XmlSchema));

            using (FileStream fs = new FileStream(Path.Combine(targetDirectoryPath, xsdFileName), FileMode.OpenOrCreate))
            {
                foreach (XmlSchema s in schemaSet.Schemas())
                {
                    formatter.Serialize(fs, s);
                }
            }
        }
    }
}
