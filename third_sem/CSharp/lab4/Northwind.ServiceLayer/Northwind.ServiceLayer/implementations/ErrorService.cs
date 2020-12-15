using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;

namespace Northwind.ServiceLayer.implementations
{
    public class ErrorService
    {
        private IUnitOfWork _Database { get; set; }

        public ErrorService(IUnitOfWork unitOfWork)
        {
            _Database = unitOfWork;
        }

        public void AddErrors(Errors error)
        {
            _Database.Errors.Create(error);
        }
    }
}
