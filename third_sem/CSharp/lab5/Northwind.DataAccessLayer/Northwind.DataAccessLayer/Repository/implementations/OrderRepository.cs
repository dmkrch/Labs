using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Threading;

namespace Northwind.DataAccessLayer.Repository.implementations
{
    internal class OrderRepository : IRepository<Order>
    {
        private readonly string _connectionString;

        public OrderRepository(string connectionString)
        {
            _connectionString = connectionString;
        }

        public void Create(Order item)
        {
            throw new NotImplementedException();
        }

        public void Update(Order item)
        {
            throw new NotImplementedException();
        }

        public void Delete(DateTime birthDay)
        {
            throw new NotImplementedException();
        }

        public Order Get(int id)
        {
            using (SqlConnection connection = new SqlConnection(_connectionString))
            {
                connection.Open();

                try
                {
                    var command = new SqlCommand("GetOrderInfo", connection)
                    {
                        CommandType = System.Data.CommandType.StoredProcedure
                    };

                    var reader = command.ExecuteReader();
                    var order = new Order();

                    if (reader.HasRows)
                    {
                        while (reader.Read())
                        {
                            order.OrderID = reader.GetInt32(0);
                            order.FirstName = reader.GetString(1);
                            order.LastName = reader.GetString(2);
                            order.ShipCountry = reader.GetString(3);
                            order.ShipCity = reader.GetString(4);
                            order.ShipAddress = reader.GetString(5);
                            order.Freight = reader.GetInt32(6);
                            order.ShipName = reader.GetString(7);
                            order.ContactName = reader.GetString(8);
                            order.CompanyName = reader.GetString(9);
                            order.Phone = reader.GetString(10);
                        }
                    }
                    reader.Close();

                    return order;
                }
                catch (Exception trouble)
                {
                    throw trouble;
                }
            }
        }


        public IEnumerable<Order> GetAll()
        {
            using (SqlConnection connection = new SqlConnection(_connectionString))
            {
                connection.Open();                  //  here is the problem !!!!!!
                var orders = new List<Order>();

                try
                {
                    var command = new SqlCommand("GetOrdersInfo", connection)
                    {
                        CommandType = System.Data.CommandType.StoredProcedure
                    };

                    var reader = command.ExecuteReader();

                    
                    if (reader.HasRows)
                    {
                            while (reader.Read())
                            {
                                var order = new Order();

                                order.OrderID = reader.GetInt32(0);
                                order.FirstName = reader.GetString(1);
                                order.LastName = reader.GetString(2);
                                order.ShipCountry = reader.GetString(3);
                                order.ShipCity = reader.GetString(4);
                                order.ShipAddress = reader.GetString(5);
                                order.Freight = reader.GetDecimal(6);
                                order.ShipName = reader.GetString(7);
                                order.ContactName = reader.GetString(8);
                                order.CompanyName = reader.GetString(9);
                                order.Phone = reader.GetString(10);


                                orders.Add(order);
                        }
                    }
                    reader.Close();

                    return orders;
                }
                catch (Exception trouble)
                {
                    throw trouble;
                }
            }
        }
    }
}
