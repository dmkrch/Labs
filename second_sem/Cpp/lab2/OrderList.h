#ifndef OrderListH
#define OrderListH

#include <iostream>
#include <vector>
#include <string>
#include "Order.h"
#include "Dish.h"
#include "Menu.h"
#include <bits.h>

#endif


class OrderList
{
	public:
		void InitInfo(AnsiString file, Menu *menu, TEdit *Edit1)
		{
			TStringList *List = new TStringList;
			AnsiString fileName = file ;
			List->LoadFromFile(fileName);


			counter = 0;
			amountOfOrders = 0;

			for (int i = 0; List -> Strings[counter] != "eof"; ++i)
			{

				int orderIndex = (List -> Strings[counter++]).ToInt();
				AnsiString tableIndex = List -> Strings[counter++];

				Order order(orderIndex, tableIndex);

				while(List -> Strings[counter++] == "/////")
				{
					AnsiString title = List -> Strings[counter++];
					int quantity = (List -> Strings[counter++]).ToInt();

					Dish dish = menu -> CheckDishByName(title);

					if (dish.GetTitle() != "false")
					{
						order.AddDish(dish,quantity);
					}
				}

				_orderList.push_back(order);

				++amountOfOrders;
			}
		}

		void ShowInfo(TMemo *Memo1)
		{
			Memo1->Lines->Clear();

			for (int i = 0; i < amountOfOrders; i++)
			{
				String orderIndex("Order #" + (String)(_orderList[i].GetOrderIndex()));
				String tableIndex("\tTable " + _orderList[i].GetTableIndex());

				Memo1 -> Lines -> Add(orderIndex);
				Memo1 -> Lines -> Add(tableIndex);
				Memo1 -> Lines -> Add("\n");

				for (int k = 0; k < _orderList[i].GetNumberOfDishes(); k++)
				{
					String title("\tDish: " + _orderList[i].GetTitle(k));
					String quantity(" - " + (String)_orderList[i].GetQuantity(k));
					String dish(title + quantity);

					Memo1 -> Lines -> Add(dish);
				}
			}
		}

		void ShowTopDishes(Menu *menu, TMemo *Memo1)
		{
			Memo1 ->Clear();

			String firstTitle;
			String secondTitle;
			String thirdTitle;

			int firstAmount = 0;
			int secondAmount = 0;
			int thirdAmount = 0;


			for (int i = 0; i < (menu -> GetAmountOfDishes()); i++)
			{
				String tempTitle = menu -> GetDishTitle(i);
				int tempAmount = 0;

				for (int i = 0; i < amountOfOrders; i++)
				{
					tempAmount += _orderList[i].GetAmountOfDishes(tempTitle);
				}

				if (tempAmount > thirdAmount)
				{
					if (tempAmount > secondAmount)
					{
						 if (tempAmount > firstAmount)
						 {
							thirdAmount = secondAmount;
							thirdTitle = secondTitle;

						 	secondAmount = firstAmount;
							secondTitle = firstTitle;

							firstAmount = tempAmount;
							firstTitle = tempTitle;
						 }

						 else
						 {
							thirdAmount = secondAmount;
							thirdTitle = secondTitle;

							secondAmount = tempAmount;
							secondTitle = tempTitle;
						 }
					}

					else
					{
						thirdAmount = tempAmount;
						thirdTitle = tempTitle;
					}

				}
			}

			Memo1 -> Lines -> Add(firstTitle + " - " + firstAmount + " orders");
			Memo1 -> Lines -> Add(secondTitle + " - " + secondAmount + " orders");
			Memo1 -> Lines -> Add(thirdTitle + " - " + thirdAmount + " orders");
		}

		void AddOrder(String tableIndex, std::vector<String> dishesList, Menu *menu)
		{
			int orderIndex;
			int size = _orderList.size();

			orderIndex = _orderList[size - 1].GetOrderIndex() + 1;
			Order order(orderIndex, tableIndex);

			for (int i = 0; i < dishesList.size(); i++)
			{
				String title;
				String quantity;
				String lineInput = dishesList[i];

				for (int i = 1; i <= lineInput.Length(); i++)
				{
					if ((lineInput[i] < '0') || (lineInput[i] > '9'))
					{
						title += lineInput[i];
					}

					else
					{
						quantity += lineInput[i];
					}
				}

				String tempLine;
				for (int i = 1; i < title.Length(); i++)
				{
					tempLine += title[i];
				}

				title = tempLine;

				Dish dish = menu -> CheckDishByName(title);

				if (dish.GetTitle() != "false")
				{
					order.AddDish(dish,quantity.ToInt());
				}
			}

			_orderList.push_back(order);
			++amountOfOrders;
		}

		void DeleteOrder(int orderIndex)
		{
			for (int i = 0; i < _orderList.size(); i++)
			{
				if (_orderList[i].GetOrderIndex() == orderIndex)
				{
					_orderList.erase(_orderList.begin() + i);
					--amountOfOrders;
				}
			}
		}

		int GetPrice(int orderIndex)
		{
			for (int i = 0; i < _orderList.size(); i++)
			{
				if (_orderList[i].GetOrderIndex() == orderIndex)
				{
					return _orderList[i].GetPrice();
				}
			}

			return 0;
        }

		int GetAmountOfOrders()
		{
			return amountOfOrders;
		}


		void SaveToFile(TSaveDialog* SaveDialog1)
		{
			TStringList *List = new TStringList;

			if(SaveDialog1->Execute())
			{
				for (int i = 0; i < amountOfOrders; i++)
				{
					List -> Add(_orderList[i].GetOrderIndex());
					List -> Add(_orderList[i].GetTableIndex());

					for (int k = 0; k < _orderList[i].GetAmountOfDishes(); k++)
					{
						List -> Add("/////");
						List -> Add(_orderList[i].GetTitle(k));
						List -> Add(_orderList[i].GetQuantity(k));
					}

					List ->Add("-------------------");
				}

				List -> Add("eof");
			}

			List -> SaveToFile(SaveDialog1 ->FileName);
		}

	private:

		std::vector <Order> _orderList;
		int counter;
		int amountOfOrders;
};
