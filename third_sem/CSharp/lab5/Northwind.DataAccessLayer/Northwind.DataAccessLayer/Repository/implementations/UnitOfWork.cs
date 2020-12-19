using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;


namespace Northwind.DataAccessLayer.Repository.implementations
{
    public class UnitOfWork : IUnitOfWork
    {
        private string _connectionString;
        private OrderRepository orderRepository;
        private ErrorRepository errorRepository;

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

        public IRepository<Error> Errors
        {
            get
            {
                if (errorRepository == null)
                    errorRepository = new ErrorRepository(_connectionString);
                return errorRepository;
            }
        }
    }
}
