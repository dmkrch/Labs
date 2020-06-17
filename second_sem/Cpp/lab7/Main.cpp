//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "TaskHashTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TaskHashTable<String> *hash_table = new TaskHashTable<String>();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1 ->Clear();
	String data = Edit1 ->Text;
	String result = "";
	bool state;


	switch(RadioGroup1->ItemIndex)
	{
		case 0:
			if(data != "")
			{
				hash_table ->Add_element(data);

				Edit1->Clear();
			}

			hash_table ->Show_table(Memo1);
			break;

		case 1:
			Edit1->Clear();
			result = hash_table ->Delete_elemenet(data);

			if(result == "deleted")
			{
				hash_table->Show_table(Memo1);
			}
			else
				Memo1 ->Lines->Add(result);

			break;

		case 2:
			if(data != "")
			{
				result = hash_table ->Find_element(data);

				Memo1 ->Lines->Add(result);
				Edit1->Clear();
			}
			break;

		case 3:
			hash_table ->Show_table(Memo1);

			Edit1->Clear();
			break;

		case 4:
			int popular_index = hash_table ->Get_popular_index();
			++popular_index;
			result = "The most frequent index: " + (String)(popular_index);

			Memo1 ->Lines ->Add(result);
			Edit1->Clear();
			break;
    }
}
//---------------------------------------------------------------------------



