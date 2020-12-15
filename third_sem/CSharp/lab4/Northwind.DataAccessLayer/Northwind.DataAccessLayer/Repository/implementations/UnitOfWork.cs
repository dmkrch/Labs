using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.DataAccessLayer.Repository.implementations
{
    public class UnitOfWork : IUnitOfWork
    {
        private string _connectionString;
        private OrderRepository orderRepository;
        private ErrorsRepository errorsRepository;

        public UnitOfWork(string connectionString)
        {
            _connectionString = connectionString;
        }

        public IRepository<Order> Orders
        {
            get
            {
                if (orderRepository == null)
                    orderRepository = new OrderRepository(_connectionString);
                return orderRepository;
            }
        }

        public IRepository<Errors> Errors
        {
            get
            {
                if (errorsRepository == null)
                    errorsRepository = new ErrorsRepository(_connectionString);
                return errorsRepository;
            }
        }
    }
}
