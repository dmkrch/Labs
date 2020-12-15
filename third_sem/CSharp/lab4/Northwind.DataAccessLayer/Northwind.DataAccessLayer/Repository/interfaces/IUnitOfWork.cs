using Northwind.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.DataAccessLayer.Repository.interfaces
{
    public interface IUnitOfWork
    {
        IRepository<Order> Orders { get; }
        IRepository<Errors> Errors { get; }
    }
}
