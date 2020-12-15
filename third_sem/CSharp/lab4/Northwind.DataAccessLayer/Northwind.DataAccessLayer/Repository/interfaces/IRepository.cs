﻿using System;
using System.Collections.Generic;

namespace Northwind.DataAccessLayer.Repository.interfaces
{
    public interface IRepository<T> where T : class
    {
        IEnumerable<T> GetAll();
        T Get(int id);
        void Create(T item);
        void Update(T item);
        void Delete(DateTime birthDay);
    }
}
