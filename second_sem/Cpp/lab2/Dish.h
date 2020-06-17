#ifndef DishH
#define DishH

#include <string>
#include <iostream>
#include <vcl.h>

#pragma once

#endif

class Dish
{
	public:
		Dish(AnsiString title, AnsiString description, int price)
		{
			_title = title;
			_description = description;
			_price = price;
		}

		Dish(AnsiString title)
		{
			_title = title;
        }

		Dish()
		{

        }

		AnsiString GetTitle()
		{
			return _title;
		}

		AnsiString GetDescription()
		{
			return _description;
		}

		int GetPrice()
		{
			return _price;
        }



	private:
		AnsiString _title;
		AnsiString _description;
		int _price;
};
