#ifndef ShopH
#define ShopH

#endif

#pragma once
#include <vcl.h>
#include "Order.h"
#include <iostream.h>
#include <string>
#include "List.h"

class Shop
{
	public:
		Shop()
		{
			ready_counter = 0;
			not_ready_counter = 0;
		}

		void Initialize_shop(String file, TLabel *Label1) // initializes shop object with information from file
		{                                                 // it is placed in executed orders list
			Label1 ->Caption = "Text for input";

			TStringList *List = new TStringList;
			AnsiString fileName = file ;
			List->LoadFromFile(fileName);

			int i = 0;

			while(List -> Strings[i++] != "eof")
			{
				String name = "";
				try                      // exceptions
				{
					name = List -> Strings[i++];
				}
				catch(...)
				{
					Label1 ->Caption = "wrong input";
					return;
				}

				String address = List -> Strings[i++];
				String date = List -> Strings[i++];

				Order order(name, address, date, ready_counter);
				_ready_orders.push_back(order);

				++ready_counter;
			}

		}

		void Show_info(TMemo *Memo1, String type_order)   // displays all information on memo1
		{
			Memo1->Lines->Clear();

			if (type_order == "not ready")
			{
				for (int i = 0; i < not_ready_counter; i++)
				{
					Show_order(Memo1, i, "not ready");
				}
			}

			else if (type_order == "ready")
			{
				for (int i = 0; i < ready_counter; i++)
				{
					Show_order(Memo1, i, "ready");
				}
			}
		}

		void Show_info(TMemo *Memo1, String type_order, int id)   //   displays information depending on id
		{
			Memo1->Lines->Clear();

			if (type_order == "not ready")
			{
				for (int i = 0; i < not_ready_counter; i++)
				{
					if(_not_ready_orders[i].Get_id() == id)
					{
						Show_order(Memo1, i, "not ready");

						break;
					}
				}
			}

			else if (type_order == "ready")
			{
                for (int i = 0; i < ready_counter; i++)
				{
					if(_ready_orders[i].Get_id() == id)
					{
						Show_order(Memo1, i, "ready");

						break;
					}
				}
			}
		}

		void Show_info(TMemo *Memo1, String type_order, String name)  // displays information depending on name
		{
			Memo1->Lines->Clear();

			if (type_order == "not ready")
			{
				for (int i = 0; i < not_ready_counter; i++)
				{
					if(_not_ready_orders[i].Get_name() == name)
					{
						Show_order(Memo1, i, "not ready");

						break;
					}
				}
			}

			else if (type_order == "ready")
			{
                for (int i = 0; i < ready_counter; i++)
				{
					if(_ready_orders[i].Get_name() == name)
					{
						Show_order(Memo1, i, "ready");

						break;
					}
				}
			}
		}

		void Show_order(TMemo *Memo1, int i, String type_order)    // displays information of a single order  by id
		{
            if (type_order == "not ready")
			{
				String id("Id: " + (String)_not_ready_orders[i].Get_id());
				String name("\tName: " + _not_ready_orders[i].Get_name());
				String address("\tAddress: " + _not_ready_orders[i].Get_address());
				String date("\tDate: " + _not_ready_orders[i].Get_date());


				Memo1 -> Lines -> Add(id);
				Memo1 -> Lines -> Add(name);
				Memo1 -> Lines -> Add(address);
				Memo1 -> Lines -> Add(date);
			}

			else if (type_order == "ready")
			{
				String id("Id: " + (String)_ready_orders[i].Get_id());
				String name("\tName: " + _ready_orders[i].Get_name());
				String address("\tAddress: " + _ready_orders[i].Get_address());
				String date("\tDate: " + _ready_orders[i].Get_date());


				Memo1 -> Lines -> Add(id);
				Memo1 -> Lines -> Add(name);
				Memo1 -> Lines -> Add(address);
				Memo1 -> Lines -> Add(date);
			}
		}

		void Execute_order(int id)               // executes order - moving order from "not executed list" to "executed list"
		{
			for (int i = 0; i < not_ready_counter; i++)
			{
				if (id == _not_ready_orders[i].Get_id())
				{
					Order order = _not_ready_orders[i];
					order.Set_id(ready_counter++);

					_not_ready_orders.removeAt(id);
					--not_ready_counter;

					for (int i = id; i < not_ready_counter; i++)
					{
						_not_ready_orders[i].Set_id(i);
					}


					_ready_orders.push_back(order);

					break;
				}
			}
		}

		void Add_order(String name, String address, String date)   // adds not executed order
		{
			Order order(name, address, date, not_ready_counter);
			++not_ready_counter;

			_not_ready_orders.push_back(order);
        }

		void Delete_same_orders()
		{
			for (int i = 0; i < not_ready_counter - 1; i++)
			{
				for (int k = i + 1; k < not_ready_counter; k++)
				{
					if(_not_ready_orders[k].Get_name() == _not_ready_orders[i].Get_name() &&
							_not_ready_orders[k].Get_address() == _not_ready_orders[i].Get_address())
					{
						_not_ready_orders.removeAt(k);
						--not_ready_counter;

						for (int m = k; m < not_ready_counter; m++)
						{
							_not_ready_orders[m].Set_id(m);
						}

						--k;
					}

				}
			}
        }



	private:
		int ready_counter;                          // amount of ready orders
		int not_ready_counter;                      // amount of not ready orders
		List <Order> _ready_orders;                 // list for ready orders
		List <Order> _not_ready_orders;             // list for not ready orders
};
