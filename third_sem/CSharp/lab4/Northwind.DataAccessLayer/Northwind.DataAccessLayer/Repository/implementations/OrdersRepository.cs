using Northwind.DataAccessLayer.Extensions;
using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;
using Northwind.Models.SearchModels;
using System;
using System.Data;
using System.Data.SqlClient;

namespace Northwind.DataAccessLayer.Repository.implementations
{
    public class OrdersRepository : IOrdersRepository
    {
        private readonly string _connection;
        private SqlConnection _sqlConnection;

        public OrdersRepository(string connection)
        {
            _connection = connection ?? throw new ArgumentOutOfRangeException("cant be null");
            _sqlConnection = new SqlConnection(_connection);
        }


        public SearchResult<Order> GetOrders(SearchCriteria searchCriteria)
        {
            try
            {
                _sqlConnection.Open();

                var command = new SqlCommand("[dbo].[Orders_ReadMany]", _sqlConnection);

                command.CommandType = CommandType.StoredProcedure;

                command.Parameters.AddWithValue("@OrderBy", searchCriteria.OrderBy);
                command.Parameters.AddWithValue("@OrderDirection", (int)searchCriteria.OrderDirection);
                command.Parameters.AddWithValue("@Page", searchCriteria.Page);
                command.Parameters.AddWithValue("@Count", searchCriteria.Count);

                var outputParameter = new SqlParameter("@Total", SqlDbType.Int);
                outputParameter.Direction = ParameterDirection.Output;

                command.Parameters.Add(outputParameter);

                var entities = command.ReadMany<Order>();

                var searchResult = new SearchResult<Order>();
                searchResult.Entities = entities;
                searchResult.Total = Convert.ToInt32(outputParameter.Value);

                return searchResult;

                /*...*/
            }

            finally
            {
                _sqlConnection.Close();
            }
        }
    }
}
