using System;
using System.Collections.Generic;
using System.Text;

namespace lab3_3
{
    class Furniture
    {
        public Furniture(int capacity, string name, bool has_capacity)
        {
            _capacity = capacity;
            _name = name;
            _has_capacity = has_capacity;
        }

        public Furniture()
        {

        }



        public int GetCapacity()
        {
            return _capacity;
        }

        public string GetName()
        {
            return _name;
        }

        public bool HasCapacity()
        {
            return _has_capacity;
        }

        private int _capacity;
        private string _name;
        private bool _has_capacity;
    }
}
