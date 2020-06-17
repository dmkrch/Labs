#ifndef CirkH
#define CirkH

#include "Figure.h"
#include <vcl.h>
#include <math.h>


#endif

class Cirk : public Figure
{
	public:
		Cirk()
		{

		}


		void set_radius()
		{
			radius = abs(get_second_x_coord() - get_center_x_coord());
		}

        void show(TCanvas *Canvas, TImage *Image1)
		{
			Image1->Canvas->Ellipse(get_center_x_coord() - radius, get_center_y_coord() - radius, get_center_x_coord() + radius, get_center_y_coord() + radius);
		}

		void set_area_and_perimeter()
		{
			set_area(3.14 * radius * radius);
			set_perimeter(2 * 3.14 * radius);
		}

		void move(int dx, int dy)
		{
			set_center_x_coord(dx + get_center_x_coord());
			set_center_y_coord(dy + get_center_y_coord());

			set_second_x_coord(dx + get_second_x_coord());
			set_second_y_coord(dy + get_second_y_coord());

			set_radius();
		}

		void hide(TCanvas *Canvas, TImage *Image1)
		{
			Image1->Canvas->Pen->Color=clWhite;
			Image1->Canvas->Brush->Color=clWhite;

			Image1->Canvas->Ellipse(get_center_x_coord() - radius, get_center_y_coord() - radius, get_center_x_coord() + radius, get_center_y_coord() + radius);
		}

		void scale_inc(int dx)
		{
			set_second_x_coord(dx + get_second_x_coord());

			set_radius();
		}

		void scale_dec(int dx)
		{
			set_second_x_coord(get_second_x_coord() - dx);

			set_radius();
		}

		void set_center_coordinats(TEdit *Edit4, TEdit *Edit5)
		{
			Edit4 -> Text = IntToStr(get_center_x_coord());
			Edit5 -> Text = IntToStr(get_center_y_coord());
		}

	private:
		int radius;
};