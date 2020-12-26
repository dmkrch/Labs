using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;
using Northwind.ServiceLayer.interfaces;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Northwind.ServiceLayer.implementations
{
    public class OrderService : IOrderService
    {
        private IUnitOfWork _Database { get; set; }


        public OrderService(IUnitOfWork unitOfWork)
        {
            _Database = unitOfWork;
        }

        private async Task<IEnumerable<Order>> GetOrders() => await _Database.Orders.GetAll();


        public async Task<IEnumerable<Order>> GetListOfOrders()
        {
            return await Task.Run(async () =>
            {
                var orders = await GetOrders();
                return orders;
            });
        }
    }
}
