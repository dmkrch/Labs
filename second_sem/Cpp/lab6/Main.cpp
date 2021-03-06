#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "TaskTree.h"
#include <string>

#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
TaskTree<String> *tree = new TaskTree<String>;


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	int values[10] = {24, 2, 25, 15, 7, 3, 9, 5, 6, 28};
	int length = 10;
	String data[10] = {"Alex", "Max", "Jack", "George", "Pavel", "Dmitriy",
						"John", "Den", "Denis", "Ben"};

	tree->Add_array_info(values, length, data);

	tree->Show_tree(TreeView1);

}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int key = (Edit1 -> Text).ToInt();
	String name = Edit2 -> Text;

	tree->Insert(key, name);

	tree->Show_tree(TreeView1);

	Edit1 ->Clear();
	Edit2 ->Clear();
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1 ->Lines->Clear();

	switch(RadioGroup1 -> ItemIndex)
	{
		case 0:
			if(Edit5 ->Text == "")
			{
				tree->Key_print(Memo1);
			}
			else
			{
				tree->Show((Edit5->Text).ToInt(), Memo1);
			}
			break;

		case 1:
			tree->Direct_print(Memo1);
			break;

		case 2:
			tree->Backward_print(Memo1);
			break;
	}
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int key = (Edit3 ->Text).ToInt();

	tree->Delete_node(key);

	tree->Show_tree(TreeView1);

	Edit3 ->Clear();
}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Label5 ->Caption = tree->Amount_of_left_nodes();
}


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	tree = tree->CreateBalancedTree(tree->root, Memo1);

	tree->Show_tree(TreeView1);
}
