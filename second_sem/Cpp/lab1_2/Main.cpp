#include <vcl.h>
#pragma hdrstop

#include "Main.h"


#define AREA 15

#include <math.h>
#include <string>

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;




__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ellipse = new Ellipsee;
	cirk = new Cirk;
	trapezium = new Trapezium;
	parallelogram = new Parallelogram;
	rectanglee = new Rectanglee;
	trianglee = new Trianglee;
	move_state = false;
}

void set_current_color(TObject* Sender)
{
	int index = Form1 -> ComboBox1 -> ItemIndex;

	switch(index)
	{
		case 0:
			Form1 -> Image1->Canvas->Brush->Color=clBlack;
			break;
		case 1:
			Form1 -> Image1->Canvas->Brush->Color=clRed;
			break;
		case 2:
			Form1 ->Image1->Canvas->Brush->Color=clGreen;
			break;
		case 3:
			Form1 ->Image1->Canvas->Brush->Color=clGray;
			break;
		case 4:
			Form1 ->Image1->Canvas->Brush->Color=clBlue;
			break;
		case 5:
			Form1 ->Image1->Canvas->Brush->Color=clYellow;
			break;
		case 6:
			Form1 ->Image1->Canvas->Brush->Color=clWhite;
			break;
	}

	index = Form1 ->ComboBox2 -> ItemIndex;

	switch(index)
	{
		case 0:
			Form1 ->Image1->Canvas->Pen->Color=clBlack;
			break;
		case 1:
			Form1 ->Image1->Canvas->Pen->Color=clRed;
			break;
		case 2:
			Form1 ->Image1->Canvas->Pen->Color=clGreen;
			break;
		case 3:
			Form1 ->Image1->Canvas->Pen->Color=clGray;
			break;
		case 4:
			Form1 ->Image1->Canvas->Pen->Color=clBlue;
			break;
		case 5:
			Form1 ->Image1->Canvas->Pen->Color=clYellow;
			break;
		case 6:
			Form1 ->Image1->Canvas->Pen->Color=clWhite;
			break;
	}

}


void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	static int counter0 = 1;
	static int counter1 = 1;
	static int counter2 = 1;
	static int counter3 = 1;
	static int counter4 = 1;
	static int counter5 = 1;

	if (RadioGroup2 -> ItemIndex == 0)
	{
		switch(RadioGroup1 -> ItemIndex)
		{
		case 0:
			if (counter0 % 2 == 1)
			{
				ellipse -> set_first_x_coord(X);
				ellipse -> set_first_y_coord(Y);
				++counter0;
			}

			else if (counter0 % 2 == 0)
			{
				ellipse -> set_second_x_coord(X);
				ellipse -> set_second_y_coord(Y);

				ellipse -> set_center_coordinats(Edit4, Edit5);
				ellipse -> set_area_and_perimeter();

				Edit6 -> Text = ellipse -> get_area();
				Edit7 -> Text = ellipse -> get_perimeter();

				ellipse -> show(Image1 -> Canvas, Image1);
				++counter0;
			}

			break;

		case 1:

			if (counter1 % 2 == 1)
			{
				cirk -> set_center_x_coord(X);
				cirk -> set_center_y_coord(Y);

				++counter1;
			}

			else if (counter1 % 2 == 0)
			{
				cirk -> set_second_x_coord(X);
				cirk -> set_second_y_coord(Y);
				cirk -> set_radius();
				cirk -> set_area_and_perimeter();

				cirk -> set_center_coordinats(Edit4, Edit5);

				Edit6 -> Text = cirk -> get_area();
				Edit7 -> Text = cirk -> get_perimeter();

				cirk -> show(Image1 -> Canvas, Image1);

				++counter1;
			}

			break;

		case 2:

			if (counter2 % 2 == 1)
			{
				trapezium -> set_first_x_coord(X);
				trapezium -> set_first_y_coord(Y);

				++counter2;
			}

			else if (counter2 % 2 == 0)
			{
				int add_first(StrToInt(Edit1 -> Text));
				int add_second(StrToInt(Edit2 -> Text));

				trapezium -> set_second_x_coord(X);
				trapezium -> set_second_y_coord(Y);

				trapezium -> set_third_x_coord(trapezium -> get_second_x_coord() + add_second);
				trapezium -> set_fourth_x_coord(trapezium -> get_first_x_coord() + add_first);
				trapezium -> set_third_y_coord(trapezium -> get_second_y_coord());
				trapezium -> set_fourth_y_coord(trapezium -> get_first_y_coord());


				trapezium -> set_center_coordinats(Edit4, Edit5);
				trapezium -> set_area_and_perimeter();

				Edit6 -> Text = trapezium -> get_area();
				Edit7 -> Text = trapezium -> get_perimeter();

				trapezium -> show(Image1 -> Canvas, Image1);

				++counter2;
			}

			break;


		case 3:
			if (counter3 % 2 == 1)
			{
				parallelogram -> set_first_x_coord(X);
				parallelogram -> set_first_y_coord(Y);

				++counter3;
			}

			else if (counter3 % 2 == 0)
			{
				int add_first(StrToInt(Edit3 -> Text));

				parallelogram -> set_second_x_coord(X);
				parallelogram -> set_second_y_coord(Y);

				parallelogram -> set_third_x_coord(parallelogram -> get_second_x_coord() + add_first);
				parallelogram -> set_third_y_coord(parallelogram -> get_second_y_coord());

				parallelogram -> set_fourth_x_coord(parallelogram -> get_first_x_coord() + add_first);
				parallelogram -> set_fourth_y_coord(parallelogram -> get_first_y_coord());

				parallelogram -> set_center_coordinats(Edit4, Edit5);
				parallelogram -> set_area_and_perimeter();


				Edit6 -> Text = parallelogram -> get_area();
				Edit7 -> Text = parallelogram -> get_perimeter();

				parallelogram -> show(Image1 -> Canvas, Image1);

				++counter3;
			}

			break;

		case 4:

			if (counter4 % 2 == 1)
			{
				rectanglee -> set_first_x_coord(X);
				rectanglee -> set_first_y_coord(Y);

				++counter4;
			}

			else if (counter4 % 2 == 0)
			{
				rectanglee -> set_third_x_coord(X);
				rectanglee -> set_third_y_coord(Y);
				rectanglee -> set_second_x_coord(rectanglee -> get_first_x_coord());
				rectanglee -> set_second_y_coord(rectanglee -> get_third_y_coord());
				rectanglee -> set_fourth_x_coord(rectanglee -> get_third_x_coord());
				rectanglee -> set_fourth_y_coord(rectanglee -> get_first_y_coord());

				rectanglee -> set_center_coordinats(Edit4, Edit5);
				rectanglee -> set_area_and_perimeter();

				Edit6 -> Text = rectanglee -> get_area();
				Edit7 -> Text = rectanglee -> get_perimeter();

				rectanglee -> show(Image1 -> Canvas, Image1);

				++counter4;
			}

			break;

		case 5:

			if (counter5 % 3 != 0 && counter5 % 2 == 1)
			{
				trianglee -> set_first_x_coord(X);
				trianglee -> set_first_y_coord(Y);

				++counter5;
			}

			else if (counter5 % 3 != 0 && counter5 % 2 == 0)
			{
				trianglee -> set_second_x_coord(X);
				trianglee -> set_second_y_coord(Y);

				++counter5;
			}

			else if (counter5 % 3 == 0)
			{
				trianglee -> set_third_x_coord(X);
				trianglee -> set_third_y_coord(Y);

				trianglee -> set_center_coordinats(Edit4, Edit5);
				trianglee -> show(Image1 -> Canvas, Image1);

				++counter5;
			}

			break;
		}
	}

	else if (RadioGroup2 -> ItemIndex == 1)
	{
		int index;
		int center_x_coord;
		int center_y_coord;

		index = RadioGroup1 -> ItemIndex;

		switch(index)
		{
			case 0:

				center_x_coord = ellipse -> get_center_x_coord();
				center_y_coord = ellipse -> get_center_y_coord();

				if (((X - center_x_coord <= AREA) && (X - center_x_coord >= -AREA)) && ((Y - center_y_coord <= AREA) && (Y - center_y_coord >= -AREA)))
				{
					move_state = true;
				}

				break;

			case 1:

				center_x_coord = cirk -> get_center_x_coord();
				center_y_coord = cirk -> get_center_y_coord();

				if (((X - center_x_coord <= AREA) && (X - center_x_coord >= -AREA)) && ((Y - center_y_coord <= AREA) && (Y - center_y_coord >= -AREA)))
				{
					move_state = true;
				}

				break;

			case 2:

				center_x_coord = trapezium -> get_center_x_coord();
				center_y_coord = trapezium -> get_center_y_coord();

				if (((X - center_x_coord <= AREA) && (X - center_x_coord >= -AREA)) && ((Y - center_y_coord <= AREA) && (Y - center_y_coord >= -AREA)))
				{
					move_state = true;
				}

				break;

			case 3:

				center_x_coord = parallelogram -> get_center_x_coord();
				center_y_coord = parallelogram -> get_center_y_coord();

				if (((X - center_x_coord <= AREA) && (X - center_x_coord >= -AREA)) && ((Y - center_y_coord <= AREA) && (Y - center_y_coord >= -AREA)))
				{
					move_state = true;
				}

				break;

			case 4:

				center_x_coord = rectanglee -> get_center_x_coord();
				center_y_coord = rectanglee -> get_center_y_coord();

				if (((X - center_x_coord <= AREA) && (X - center_x_coord >= -AREA)) && ((Y - center_y_coord <= AREA) && (Y - center_y_coord >= -AREA)))
				{
					move_state = true;
				}

				break;

			case 5:

				center_x_coord = trianglee -> get_center_x_coord();
				center_y_coord = trianglee -> get_center_y_coord();

				if (((X - center_x_coord <= AREA) && (X - center_x_coord >= -AREA)) && ((Y - center_y_coord <= AREA) && (Y - center_y_coord >= -AREA)))
				{
					move_state = true;
				}

				break;
		}
	}
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Image1->Canvas->Pen->Color=clWhite;
	Image1->Canvas->Brush->Color=clWhite;

	Image1->Canvas->Rectangle(0, 0, Image1->Width,Image1->Height);

	set_current_color(Sender);
}



void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	set_current_color(Sender);
}

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	set_current_color(Sender);
}


void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	if (RadioGroup2 -> ItemIndex == 1)
	{
		if (move_state == true)
		{
			int index = RadioGroup1 -> ItemIndex;
			int delta_x = 0;
			int delta_y = 0;

			switch(index)
			{
				case 0:
					delta_x = X - ellipse -> get_center_x_coord();
					delta_y = Y - ellipse -> get_center_y_coord();

					ellipse -> hide(Image1 -> Canvas, Image1);
					set_current_color(Sender);
					ellipse -> move(delta_x, delta_y);
					ellipse -> set_center_coordinats(Edit4, Edit5);
					ellipse -> show(Image1 -> Canvas, Image1);

					break;
				case 1:
					delta_x = X - cirk -> get_center_x_coord();
					delta_y = Y - cirk -> get_center_y_coord();

					cirk -> hide(Image1 -> Canvas, Image1);
					set_current_color(Sender);
					cirk -> move(delta_x, delta_y);
					cirk -> set_center_coordinats(Edit4, Edit5);
					cirk -> show(Image1 -> Canvas, Image1);

					break;

				case 2:
					delta_x = X - trapezium -> get_center_x_coord();
					delta_y = Y - trapezium -> get_center_y_coord();

					trapezium -> hide(Image1 -> Canvas, Image1);
					set_current_color(Sender);
					trapezium -> move(delta_x, delta_y);
					trapezium -> set_center_coordinats(Edit4, Edit5);
					trapezium -> show(Image1 -> Canvas, Image1);

					break;

				case 3:
					delta_x = X - parallelogram -> get_center_x_coord();
					delta_y = Y - parallelogram -> get_center_y_coord();

					parallelogram -> hide(Image1 -> Canvas, Image1);
					set_current_color(Sender);
					parallelogram -> move(delta_x, delta_y);
					parallelogram -> set_center_coordinats(Edit4, Edit5);
					parallelogram -> show(Image1 -> Canvas, Image1);

					break;

				case 4:
					delta_x = X - rectanglee -> get_center_x_coord();
					delta_y = Y - rectanglee -> get_center_y_coord();

					rectanglee -> hide(Image1 -> Canvas, Image1);
					set_current_color(Sender);
					rectanglee -> move(delta_x, delta_y);
					rectanglee -> set_center_coordinats(Edit4, Edit5);
					rectanglee -> show(Image1 -> Canvas, Image1);

					break;

				case 5:
					delta_x = X - trianglee -> get_center_x_coord();
					delta_y = Y - trianglee -> get_center_y_coord();

					trianglee -> hide(Image1 -> Canvas, Image1);
					set_current_color(Sender);
					trianglee -> move(delta_x, delta_y);
					trianglee -> set_center_coordinats(Edit4, Edit5);
					trianglee -> show(Image1 -> Canvas, Image1);

					break;
			}
		}
	}
}

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	move_state = false;
}


void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	if (RadioGroup2 -> ItemIndex == 2)
	{
		int index = RadioGroup1 -> ItemIndex;
		int dx = 2;

		switch(index)
		{
			case 0:

				ellipse ->hide(Image1 -> Canvas, Image1);
				set_current_color(Sender);
				ellipse -> scale_inc(dx);
				ellipse -> show(Image1 -> Canvas, Image1);

				break;

			case 1:

				cirk ->hide(Image1 -> Canvas, Image1);
				set_current_color(Sender);
				cirk -> scale_inc(dx);
				cirk -> show(Image1 -> Canvas, Image1);

				break;

			case 2:

				trapezium -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				trapezium -> scale_inc(dx);
				trapezium -> show(Image1 -> Canvas, Image1);

				break;

			case 3:

				parallelogram -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				parallelogram -> scale_inc(dx);
				parallelogram -> show(Image1 -> Canvas, Image1);

				break;

			case 4:

				rectanglee -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				rectanglee -> scale_inc(dx);
				rectanglee -> show(Image1 -> Canvas, Image1);

				break;

			case 5:

				trianglee -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				trianglee -> scale_inc(dx);
				trianglee -> show(Image1 -> Canvas, Image1);

				break;
		}
	}
}
void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    if (RadioGroup2 -> ItemIndex == 2)
	{
		int index = RadioGroup1 -> ItemIndex;
		int dx = 2;

		switch(index)
		{
			case 0:

				ellipse ->hide(Image1 -> Canvas, Image1);
				set_current_color(Sender);
				ellipse -> scale_dec(dx);
				ellipse -> show(Image1 -> Canvas, Image1);

				break;

			case 1:

				cirk ->hide(Image1 -> Canvas, Image1);
				set_current_color(Sender);
				cirk -> scale_dec(dx);
				cirk -> show(Image1 -> Canvas, Image1);

				break;

			case 2:

				trapezium -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				trapezium -> scale_dec(dx);
				trapezium -> show(Image1 -> Canvas, Image1);

				break;

			case 3:

				parallelogram -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				parallelogram -> scale_dec(dx);
				parallelogram -> show(Image1 -> Canvas, Image1);

				break;

			case 4:

				rectanglee -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				rectanglee -> scale_dec(dx);
				rectanglee -> show(Image1 -> Canvas, Image1);

				break;

			case 5:

				trianglee -> hide(Image1 ->Canvas, Image1);
				set_current_color(Sender);
				trianglee -> scale_dec(dx);
				trianglee -> show(Image1 -> Canvas, Image1);

				break;
		}
	}
}
