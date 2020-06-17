//---------------------------------------------------------------------------

#include <vcl.h>
#pragma once
#ifndef RectangH
#define RectangH
//---------------------------------------------------------------------------
#endif

extern int acc;

class Rectang
{
	private:
		int x1, y1, x2, y2;

	public:
		Rectang(int x1, int y1, int x2, int y2)
		{
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
		};

		Rectang ()
		{

        };

		int GetX1(TCanvas *Canvas)
		{
			return x1;
		}

		int GetX2(TCanvas *Canvas)
		{
			return x2;
		}

		int GetY1(TCanvas *Canvas)
		{
			return y1;
		}

		int GetY2(TCanvas *Canvas)
		{
			return y2;
		}

		void SetX1(int coord)
		{
			x1 = coord;
		}

		void SetX2(int coord)
		{
			x2 = coord;
		}

		void SetY1(int coord)
		{
			y1 = coord;
		}

		void SetY2(int coord)
		{
			y2 = coord;
		}

		void show(TCanvas *Canvas)
		{
			Canvas->Pen->Color=clYellow;
			Canvas->Pen->Width = 1;
			Canvas->Brush->Color=clYellow;
			Canvas->Rectangle(x1, y1, x2, y2);
		}

		void show_red(TCanvas *Canvas)
		{
			Canvas->Pen->Color=clRed;
			Canvas->Pen->Width = 1;
			Canvas->Brush->Color=clRed;
			Canvas->Rectangle(x1, y1, x2, y2);
		}

		void show_blue(TCanvas *Canvas)
		{
			Canvas->Pen->Color=clAqua;
			Canvas->Pen->Width = 1;
			Canvas->Brush->Color=clAqua;
			Canvas->Rectangle(x1, y1, x2, y2);
        }

		void move(TCanvas *Canvas)
		{
			x1 -= acc;
			x2 -= acc;
		}

		void hide(TCanvas *Canvas)
		{
			Canvas->Pen->Color = clWhite;
			Canvas->Brush->Color = clWhite;
			Canvas->Rectangle(x1, y1, x2, y2);
		}
};



