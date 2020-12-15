using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.Models.SearchModels
{
    public class SearchCriteria
    {
        /* model of searching. These are arguments that we need to pass to procedure 'GetOrders in database */
        public string OrderBy { get; set; }

        public OrderDirection OrderDirection { get; set; }

        public int Page { get; set; }

        public int Count { get; set; }
    }
}
