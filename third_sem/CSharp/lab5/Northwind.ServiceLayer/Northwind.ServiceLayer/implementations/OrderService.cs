using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;
using Northwind.ServiceLayer.interfaces;
using System.Collections.Generic;

namespace Northwind.ServiceLayer.implementations
{
    public class OrderService : IOrderService
    {
        private IUnitOfWork _Database { get; set; }


        public OrderService(IUnitOfWork unitOfWork)
        {
            _Database = unitOfWork;
        }

        public IEnumerable<Order> GetListOfOrders()
        {
            return _Database.Orders.GetAll();
        }

        public Order GetInfo(int? id)
        {
            var order = _Database.Orders.Get(id.Value);

            return order;
        }
    }
}
