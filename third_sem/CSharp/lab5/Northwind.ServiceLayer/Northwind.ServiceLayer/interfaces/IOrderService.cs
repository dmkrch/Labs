using Northwind.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Northwind.ServiceLayer.interfaces
{
    public interface IOrderService
    {
        Task<IEnumerable<Order>> GetListOfOrders();
    }
}
