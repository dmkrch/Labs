#ifndef MenuH
#define MenuH

#include <vector>
#include <string>
#include "Dish.h"
#pragma once

#endif


class Menu
{
	public:
		Menu()
		{
			counter = 0;
		}

		void InitInfo(String file)
		{
			TStringList *List = new TStringList;
			AnsiString fileName = file ;
			List->LoadFromFile(fileName);

			amountOfDishes = (List -> Count) / 4;

			for (int i = 0; i < amountOfDishes; ++i)
			{
				AnsiString title = List -> Strings[counter++];
				AnsiString description = List -> Strings[counter++];
				int price = (List -> Strings[counter++]).ToInt();
				++counter;


				Dish dish(title, description, price);
				_menu.push_back(dish);
			}
		}


		void ShowInfo(TMemo *Memo1)
		{
			Memo1->Lines->Clear();

			for (int i = 0; i < amountOfDishes; i++)
			{
				String text("Dish #" + (String)i);
				String title("\tTitle: " + _menu[i].GetTitle());
				String description("\tDescription: " + _menu[i].GetDescription());
				String price("\tPrice: " + (String)_menu[i].GetPrice());


				Memo1 -> Lines -> Add(text);
				Memo1 -> Lines -> Add(title);
				Memo1 -> Lines -> Add(description);
				Memo1 -> Lines -> Add(price + " $");
			}
		}

		void ShowInfoByPrice(TMemo *Memo1)
		{
			Dish temp;
			std::vector <Dish> _menuTemp;
			_menuTemp = _menu;

			for (int i = 0; i < _menuTemp.size() - 1; i++)
			{
				for (int j = 0; j < _menuTemp.size() - i - 1; j++)
				{
					if ( (_menuTemp[j].GetPrice()) > (_menuTemp[j + 1].GetPrice()) )
					{
						temp = _menuTemp[j];
						_menuTemp[j] = _menuTemp[j + 1];
						_menuTemp[j + 1] = temp;
					}
				}
			}

			Memo1->Lines->Clear();

            for (int i = 0; i < amountOfDishes; i++)
			{
				String text("Dish #" + (String)i);
				String title("\tTitle: " + _menuTemp[i].GetTitle());
				String description("\tDescription: " + _menuTemp[i].GetDescription());
				String price("\tPrice: " + (String)_menuTemp[i].GetPrice());

				Memo1 -> Lines ->Add(text);
				Memo1 -> Lines -> Add(title);
				Memo1 -> Lines -> Add(description);
				Memo1 -> Lines -> Add(price + " $");
			}

		}

		Dish CheckDishByName(AnsiString title)
		{
			for (int i = 0; i < amountOfDishes; i++)
			{
				if (_menu[i].GetTitle() == title)
				{
					return _menu[i];
					break;
				}
			}

			Dish falseDish("false");

			return falseDish;
		}

		int GetAmountOfDishes()
		{
			return amountOfDishes;
		}

		String GetDishTitle(int i)
		{
			return _menu[i].GetTitle();
        }


	private:
		int counter;
		int amountOfDishes;
		std::vector <Dish> _menu;
};
