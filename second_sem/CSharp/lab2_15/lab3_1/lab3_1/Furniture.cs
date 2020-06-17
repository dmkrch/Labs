using System;

namespace sharps_test
{
    class Furniture
    {
        public Furniture(int capacity, string name, bool has_capacity)
        {
            _capacity = capacity;
            _name = name;
            _has_capacity = has_capacity;
        }

        public int GetCapacity()
        {
            return _capacity;
        }

        private int _capacity;
        private string _name;
        private bool _has_capacity;
    }
}
