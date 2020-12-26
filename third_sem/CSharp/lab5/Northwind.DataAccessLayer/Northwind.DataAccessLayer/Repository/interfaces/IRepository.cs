using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Northwind.DataAccessLayer.Repository.interfaces
{
    public interface IRepository<T> where T : class
    {
        Task<IEnumerable<T>> GetAll();
        Task<T> Get(int id);
        void Create(T item);
        void Update(T item);
        void Delete(DateTime birthDay);
    }
}
