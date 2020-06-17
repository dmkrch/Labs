#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "List.h"
#include <string>


#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
List<String> stringList;
String resultString = "";
List<int> index;


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	for (int i = 0; i < ListBox1->Items->Count; ++i)
		if(ListBox1->Selected[i])
		{
			index.push_back(i);
		}


	for(int i = 0, k = 0; k < index.GetSize(); ++i)
	{
		if(index[k] == i)
		{
			resultString += stringList[i];

			++k;
		}
	}
}


void __fastcall TForm1::InitializeList1Click(TObject *Sender)
{
	stringList.push_back("hello world");
	stringList.push_back("how are you");
	stringList.push_back("123");
	stringList.push_back("im fine");
	stringList.push_back("ok then");
	stringList.push_back("");
	stringList.push_back("123$");

}


void __fastcall TForm1::Showlist1Click(TObject *Sender)
{
	ListBox1 ->Clear();

	for(int i = 0; i < stringList.GetSize(); ++i)
	{
		ListBox1->Items->Add(stringList[i]);
	}
}


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	for (int i = 0; i < ListBox1->Items->Count; ++i)
		if(ListBox1->Selected[i])
		{
			resultString += stringList[i];
			stringList[i] = resultString;
		}

    for(int i = 0, k = 0; k < index.GetSize(); ++i)
	{
		if(index[k] == i)
		{
			stringList.removeAt(i);

			for(int i = 0; i < index.GetSize(); ++i)
			{
				--index[i];
			}

            i = -1;
			++k;
		}
	}

	resultString = "";
	index.clear();
}
