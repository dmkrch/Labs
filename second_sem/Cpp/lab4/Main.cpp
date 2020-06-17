//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Algorithm.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Algorithm *alg = new Algorithm();

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(RadioGroup1 ->ItemIndex == 0)
	{
		if(Edit1 ->Text != "")
		{
			Edit2 -> Text = alg -> Execute_calculations(alg ->Get_OPZ(Edit1 -> Text));
		}
		else
			Label1 ->Caption = "enter an expression";
	}
	else if(RadioGroup1 ->ItemIndex == 1)
	{
        if(Edit1 ->Text != "")
		{
			Edit2 -> Text = alg -> Execute_calculations(Edit1 -> Text);
		}
		else
			Label1 ->Caption = "enter an expression";
    }
}
//---------------------------------------------------------------------------
