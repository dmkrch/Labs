using Northwind.Models;
using Northwind.Models.SearchModels;


namespace Northwind.ServiceLayer.interfaces
{
    public interface IXmlGeneratorService
    {
        public void GenerateXml(SearchResult<Order> searchResult, string pathToSave, string xmlFileName);

        public void GenerateXsd(string pathToSave, string xmlFileName, string xsdFileName);
    }
}
