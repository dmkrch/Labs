namespace Northwind.Models
{
    public class Order
    {
        public int OrderID { get; set; }

        public string FirstName { get; set; }

        public string LastName { get; set; }

        public string ShipCountry { get; set; }

        public string ShipCity { get; set; }

        public string ShipAddress { get; set; }

        public decimal? Freight { get; set; }

        public string ShipName { get; set; }

        public string ContactName { get; set; }

        public string CompanyName { get; set; }

        public string Phone { get; set; }
    }
}
