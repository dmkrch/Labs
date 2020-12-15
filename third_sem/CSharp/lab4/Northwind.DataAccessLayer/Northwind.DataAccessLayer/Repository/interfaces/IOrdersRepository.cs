using Northwind.Models;
using Northwind.Models.SearchModels;

namespace Northwind.DataAccessLayer.Repository.interfaces
{
    public interface IOrdersRepository
    {
        SearchResult<Order> GetOrders(SearchCriteria searchCriteria);
    }
}
