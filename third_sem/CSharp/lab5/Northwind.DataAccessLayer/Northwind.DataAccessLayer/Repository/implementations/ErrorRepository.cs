﻿using Northwind.DataAccessLayer.Repository.interfaces;
using Northwind.Models;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;


namespace Northwind.DataAccessLayer.Repository.implementations
{
    class ErrorRepository : IRepository<Error>
    {
        private string _connectionString;

        public ErrorRepository(string connectionString)
        {
            _connectionString = connectionString;
        }
        public void Create(Error item)
        {
            using (SqlConnection connection = new SqlConnection(_connectionString))
            {
                connection.Open();

                var command = new SqlCommand("AddErrorMessage", connection)
                {
                    CommandType = System.Data.CommandType.StoredProcedure
                };

                SqlParameter excepParam = new SqlParameter
                {
                    ParameterName = "@exception",
                    Value = item.Exception
                };
                command.Parameters.Add(excepParam);

                SqlParameter messParam = new SqlParameter
                {
                    ParameterName = "@message",
                    Value = item.Message
                };
                command.Parameters.Add(messParam);

                SqlParameter dateParam = new SqlParameter
                {
                    ParameterName = "@time",
                    Value = item.Time
                };
                command.Parameters.Add(dateParam);

                var result = command.ExecuteScalar();
            }
        }


        public void Delete(DateTime birthDay)
        {
            throw new NotImplementedException();
        }

        public Error Get(int id)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<Error> GetAll()
        {
            throw new NotImplementedException();
        }

        public void Update(Error item)
        {
            throw new NotImplementedException();
        }
    }
}
