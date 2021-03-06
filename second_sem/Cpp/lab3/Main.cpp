#include <vcl.h>
#pragma hdrstop
#pragma once

#include "Main.h"
#include "Order.h"
#include "Shop.h"


#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
Shop *_shop = new Shop();

int id = 0;
int clicks_of_button = 1;
int clicks_of_add = 0;

String name = "";
String state = "";
String address = "";
String date = "";


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}



void __fastcall TForm1::Openfile1Click(TObject *Sender)
{
	if (OpenDialog1 -> Execute())
	{
		_shop ->Initialize_shop(OpenDialog1 ->FileName, Label1);
	}
}



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Label1 ->Caption = "Text for input";

	String type_order;

	if (RadioGroup2 -> ItemIndex == 0)
		type_order = "ready";
	else if (RadioGroup2 -> ItemIndex == 1)
		type_order = "not ready";

	switch (RadioGroup1 ->ItemIndex)
	{
		case 0:
			_shop ->Show_info(Memo1, type_order, id);
			break;

		case 1:
			_shop ->Show_info(Memo1, type_order, name);
			break;

		case 2:
			_shop ->Show_info(Memo1, type_order);
			break;

		default:
			break;
	}

    Edit1 ->Text = "";
}



void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	Label1 ->Caption = "Text for input";
	switch (RadioGroup1 ->ItemIndex)
	{
		case 0:
			Label1 ->Caption = "Enter id of order";
			break;
		case 1:
			Label1 ->Caption = "Enter name";
	}
}


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	if (state == "")
	{
        switch(RadioGroup1 ->ItemIndex)
		{
			case 0:
				try
				{
					id = (Edit1 -> Text).ToInt();
				}
				catch(...)
				{
					Label1 ->Caption = "incorrect format";
				}
				break;
			case 1:
				name = Edit1 ->Text;
				break;
		}
	}

	else if(state == "add")
	{
		if(clicks_of_button == 1)
		{
			name = Edit1 ->Text;
			Edit1 ->Text = "";
			Label1 ->Caption = "Enter address";
		}
		else if(clicks_of_button == 2)
		{
			address = Edit1 ->Text;
			Edit1 ->Text = "";
			Label1 ->Caption = "Enter date";
		}
		else if(clicks_of_button == 3)
		{
		   date = Edit1 ->Text;
		   Edit1 ->Text = "";

		   _shop ->Add_order(name, address, date);
           Label1 ->Caption = "Order has been added!";
		   clicks_of_button = 1;
		   return;
		}

		++clicks_of_button;
	}

	else if (state == "execute")
	{
		id = (Edit1 ->Text).ToInt();

		_shop ->Execute_order(id);
		Label1 ->Caption = "Order has been executed!";
	}
}


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(clicks_of_add == 0)
	{
        Edit1 ->Text = "";
		Label1 ->Caption = "Enter name";
		state = "add";

		++clicks_of_add;
	}
	else
	{
		clicks_of_add = 0;
		state = "";
		Label1 ->Caption = "Text for input";
    }
}

void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
    Label1 ->Caption = "Text for input";
}


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	state = "execute";
	Label1 ->Caption = "Enter id";
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    _shop ->Delete_same_orders();
}
/
