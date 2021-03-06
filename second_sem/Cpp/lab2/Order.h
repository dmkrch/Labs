#ifndef OrderH
#define OrderH

#include <vector>
#include "Dish.h"

#endif

class Order
{
	public:
		Order(int orderIndex, AnsiString tableIndex)
		{
			_orderIndex = orderIndex;
			_tableIndex = tableIndex;
		}

		int GetOrderIndex()
		{
			return _orderIndex;
		}

		AnsiString GetTableIndex()
		{
			return _tableIndex;
		}

		int GetQuantity(int i)
		{
			return _dishesQuantity[i];
		}

		AnsiString GetTitle(int i)
		{
			return _dish[i].GetTitle();
		}

		void AddDish(Dish dish, int quantity)
		{
			_dish.push_back(dish);
			_dishesQuantity.push_back(quantity);
		}

		int GetNumberOfDishes()
		{
			return _dish.size();
		}

		int GetAmountOfDishes(String title)
		{
			for (int i = 0; i < _dish.size(); i++)
			{
				if (_dish[i].GetTitle() == title)
				{
					return _dishesQuantity[i];
				}
			}

			return 0;
		}

		int GetAmountOfDishes()
		{
            return _dish.size();
		}



		int GetPrice()
		{
			int sum = 0;

			for (int i = 0; i < _dish.size(); i++)
			{
				sum += _dish[i].GetPrice() * _dishesQuantity[i];
			}

            return sum;
        }

	private:
		int _orderIndex;
		AnsiString _tableIndex;
		std::vector <Dish> _dish;
		std::vector <int> _dishesQuantity;
};
