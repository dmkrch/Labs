//---------------------------------------------------------------------------

#include <vcl.h>
#pragma once
#ifndef CircH
#define CircH
//---------------------------------------------------------------------------
#endif

extern int acc;

class Circ
{
private:
	int x, y, r;

public:
	Circ(int x, int y, int r)
	{
		this -> x = x;
		this -> y = y;
		this -> r = r;
	};

	void SetX(int coord)
	{
		x = coord;
    }

	Circ ()
	{

	};

	void show(TCanvas *Canvas)
	{
		Canvas->Pen->Color=clGray;
		Canvas->Brush->Color=clBlack;
		Canvas->Ellipse(x - r, y + r, x + r, y - r);
	}

	void move(TCanvas *Canvas)
	{
		x = x - acc;
	}

	void hide(TCanvas *Canvas)
	{
		Canvas->Pen->Color = clWhite;
		Canvas->Brush->Color = clWhite;
		Canvas->Ellipse(x - r, y + r, x + r, y - r);
	}
};
