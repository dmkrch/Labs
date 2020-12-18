using System.Collections.Generic;

namespace Northwind.ServiceLayer.interfaces
{
    public interface IXmlGeneratorService
    {
        void XmlGenerate<T>(IEnumerable<T> info);
    }
}
