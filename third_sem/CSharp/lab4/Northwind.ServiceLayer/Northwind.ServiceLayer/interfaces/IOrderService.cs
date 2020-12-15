using Northwind.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.ServiceLayer.interfaces
{
    public interface IOrderService
    {
        Order GetInfo(int? id);
    }
}
