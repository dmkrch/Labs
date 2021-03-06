#pragma hdrstop

#include <vcl.h>
#include "Main.h"
#include "Rectang.h"
#include "Trolley.h"
#include "Circ.h"

#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
Trolley *A = new Trolley(571,300,721,350);
Trolley *B = new Trolley(722,300,872,350);
Circ *C = new Circ(596, 350, 20);
Circ *D = new Circ(696, 350, 20);
Circ *C1 = new Circ(746, 350, 20);
Circ *D1 = new Circ(846, 350, 20);
Rectang *E = new Rectang(635, 270, 705, 300);
Rectang *E1 = new Rectang(785, 270, 855, 300);
Rectang *F = new Rectang(596, 250, 630, 300);
Rectang *F1 = new Rectang(746, 250, 780, 300);


static int acc = 1;
int counter = 0;



__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}



void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Timer1 -> Enabled = true;
}



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Timer1 -> Enabled = false;
}



void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Image1 -> Canvas->Pen->Color=clSilver;     // here is bag with background
	Image1 -> Canvas->Brush->Color=clSilver;
	Image1 -> Canvas->Rectangle(1, 320, 722, 470);

	Image1 -> Canvas->Pen->Color=clWhite;
	Image1 -> Canvas->Brush->Color=clWhite;
	Image1 -> Canvas->Rectangle(1, 360, 722, 370);
	Image1 -> Canvas->Rectangle(1, 420, 722, 430);

	Image1 -> Canvas->Pen->Color=clSkyBlue;
	Image1 -> Canvas->Brush->Color=clSkyBlue;
	Image1 -> Canvas->Rectangle(1, 1, 722, 320);


	if (A -> GetX2(Image1 -> Canvas) > 0)
	{

		Edit1 -> Text = A -> GetX1(Image1 -> Canvas);
		Edit2 -> Text = A -> GetX2(Image1 -> Canvas);

		A -> hide (Image1 -> Canvas);
		A -> move (Image1 -> Canvas);
		A -> show (Image1 -> Canvas);

		C -> hide (Image1 -> Canvas);
		C -> move (Image1 -> Canvas);
		C -> show (Image1 -> Canvas);

		D -> hide (Image1 -> Canvas);
		D -> move (Image1 -> Canvas);
		D -> show (Image1 -> Canvas);

		E -> hide (Image1 -> Canvas);
		E -> move (Image1 -> Canvas);
		E -> show_red(Image1 -> Canvas);

		F -> hide (Image1 -> Canvas);
		F -> move (Image1 -> Canvas);
		F -> show_blue(Image1 -> Canvas);


		if (A -> GetX1(Image1 -> Canvas) <= 0)
		{
			Edit1 -> Text = B -> GetX1(Image1 -> Canvas);
			Edit2 -> Text = B -> GetX2(Image1 -> Canvas);

			B -> hide (Image1 -> Canvas);
			B -> move (Image1 -> Canvas);
			B -> show (Image1 -> Canvas);

			C1 -> hide (Image1 -> Canvas);
			C1 -> move (Image1 -> Canvas);
			C1 -> show (Image1 -> Canvas);

			D1 -> hide (Image1 -> Canvas);
			D1 -> move (Image1 -> Canvas);
			D1 -> show (Image1 -> Canvas);

			E1 -> hide (Image1 -> Canvas);
			E1 -> move (Image1 -> Canvas);
			E1 -> show_red (Image1 -> Canvas);

			F1 -> hide (Image1 -> Canvas);
			F1 -> move (Image1 -> Canvas);
			F1 -> show_blue (Image1 -> Canvas);
		}
	}
	else
	{
		A -> SetX1(B -> GetX1(Image1 -> Canvas));
		A -> SetX2(B -> GetX2(Image1 -> Canvas));
		A -> SetY1(B -> GetY1(Image1 -> Canvas));
		A -> SetY2(B -> GetY2(Image1 -> Canvas));

		E -> SetX1(B -> GetX1(Image1 -> Canvas) + 64);
		E -> SetX2(B -> GetX2(Image1 -> Canvas) - 16);
		E -> SetY1(B -> GetY1(Image1 -> Canvas) - 30);
		E -> SetY2(B -> GetY2(Image1 -> Canvas) - 50);

		F -> SetX1(B -> GetX1(Image1 -> Canvas) + 25);
		F -> SetX2(B -> GetX2(Image1 -> Canvas) - 91);
		F -> SetY1(B -> GetY1(Image1 -> Canvas) - 50);
		F -> SetY2(B -> GetY2(Image1 -> Canvas) - 50);


		C -> SetX((B -> GetX1(Image1 -> Canvas)) + 25);
		D -> SetX((B -> GetX1(Image1 -> Canvas)) + 125);

		B -> SetX1(722);
		B -> SetX2(872);
		B -> SetY1(300);
		B -> SetY2(350);

		C1 -> SetX(746);
		D1 -> SetX(846);

		E1 -> SetX1(785);
		E1 -> SetX2(855);
		E1 -> SetY1(270);
		E1 -> SetY2(300);

		F1 -> SetX1(746);
		F1 -> SetX2(780);
		F1 -> SetY1(250);
		F1 -> SetY2(300);
	}
}



void __fastcall TForm1::Button3Click(TObject *Sender)
{
	acc = acc * 2;
}



void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(acc > 1)
		acc = acc / 2;
}
