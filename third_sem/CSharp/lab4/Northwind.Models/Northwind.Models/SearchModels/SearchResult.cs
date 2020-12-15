using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.Models.SearchModels
{
    public class SearchResult<TEntity> where TEntity : new()
    {
        public IEnumerable<TEntity> Entities { get; set; }

        public int Total { get; set; }

        public string OrderedBy { get; set; }

        public OrderDirection OrderedDirection { get; set; } = OrderDirection.NoOrder;
    }
}
