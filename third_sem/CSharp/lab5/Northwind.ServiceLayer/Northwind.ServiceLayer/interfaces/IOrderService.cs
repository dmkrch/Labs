using Northwind.Models;

namespace Northwind.ServiceLayer.interfaces
{
    public interface IOrderService
    {
        Order GetInfo(int? id);
    }
}
