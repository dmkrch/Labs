using System.Collections.Generic;
using System.Threading.Tasks;

namespace Northwind.ServiceLayer.interfaces
{
    public interface IXmlGeneratorService
    {
        Task XmlGenerate<T>(IEnumerable<T> info);
    }
}
