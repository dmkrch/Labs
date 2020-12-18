using Northwind.Models;

namespace Northwind.DataAccessLayer.Repository.interfaces
{
    public interface IUnitOfWork
    {
        IRepository<Order> Orders { get; }
        IRepository<Errors> Errors { get; }
    }
}