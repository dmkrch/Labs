#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Menu.h"
#include "OrderList.h"
#include <vector>

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Menu *menu = new Menu();
OrderList *orderList = new OrderList();

static int counter = 0;
String tableIndex;
bool addingState = false;
std::vector <String> dishesList;


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}



void __fastcall TForm1::Ope1Click(TObject *Sender)
{
	if (OpenDialog1 -> Execute())
	{
		menu ->InitInfo(OpenDialog1 ->FileName);
	}
}



void __fastcall TForm1::Save1Click(TObject *Sender)
{
	orderList -> SaveToFile(SaveDialog1);
}


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	menu ->ShowInfo(Memo1);
}



void __fastcall TForm1::Button3Click(TObject *Sender)
{
    menu -> ShowInfoByPrice(Memo1);
}



void __fastcall TForm1::Openorders1Click(TObject *Sender)
{
	if (OpenDialog1 -> Execute())
	{
		orderList ->InitInfo(OpenDialog1 ->FileName, menu, Edit1);
	}
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	orderList -> ShowInfo(Memo1);
}



void __fastcall TForm1::Button5Click(TObject *Sender)
{
    orderList -> ShowTopDishes(menu, Memo1);
}



void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	if (RadioGroup1 ->ItemIndex == 0)
	{
		Edit1 ->Text = "";
		Label1 -> Caption = "Enter order id to show price";
	}

	else if (RadioGroup1 ->ItemIndex == 1)
	{
		Edit1 ->Text = "";
		Label1 -> Caption = "Enter table index";
	}

	else if (RadioGroup1 ->ItemIndex == 2)
	{
        Edit1 ->Text = "";
		Label1 -> Caption = "Enter table index to delete";
	}

}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if (RadioGroup1 -> ItemIndex == 0)
	{
		int price = 0;
		int orderIndex = (Edit1 ->Text).ToInt();

		price = orderList -> GetPrice(orderIndex);

		Edit1 ->Text = "The price is " + (String)price + " $";
	}

	else if (RadioGroup1 -> ItemIndex == 1)
	{
		String dishAndQuantity;

		if (Edit1 ->Text != "")
		{
			switch(counter)
			{
				case 0:
					tableIndex = Edit1->Text;
					Edit1 ->Text = "";

					Label1 ->Caption = "Enter dish #1";
					counter ++;

					break;

				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
                    dishAndQuantity = Edit1 ->Text;
					dishesList.push_back(dishAndQuantity);
					Edit1 ->Text = "";

					Label1 ->Caption = "Enter dish #" + (String)(counter + 1);

					++counter;
					break;
			}
		}
	}

	else if (RadioGroup1 -> ItemIndex == 2)
	{
		int orderIndex = (Edit1 ->Text).ToInt();

		orderList -> DeleteOrder(orderIndex);

		Edit1 ->Text = "The order has been deleteed";
	}
}

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	orderList ->AddOrder(tableIndex, dishesList, menu);
	dishesList.clear();

	addingState = false;
	counter = 0;
	Label1 ->Caption = "Information for input";
}
