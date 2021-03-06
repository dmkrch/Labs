#ifndef EllipseeH
#define EllipseeH
#include <vcl.h>
#include "Figure.h"
#include <math.h>

#endif

class Ellipsee : public Figure
{
	public:
		Ellipsee()
		{

		}

		void hide(TCanvas *Canvas, TImage *Image1)
		{
			Image1->Canvas->Pen->Color=clWhite;
			Image1->Canvas->Brush->Color=clWhite;

			Image1->Canvas->Ellipse(get_first_x_coord(), get_first_y_coord(), get_second_x_coord(), get_second_y_coord());
		}

		void move(int dx, int dy)
		{
			set_center_x_coord(dx + get_center_x_coord());
			set_center_y_coord(dy + get_center_y_coord());

			set_first_x_coord(dx + get_first_x_coord());
			set_second_x_coord(dx + get_second_x_coord());

			set_first_y_coord(dy + get_first_y_coord());
			set_second_y_coord(dy + get_second_y_coord());
		}

		void show(TCanvas *Canvas, TImage *Image1)
		{
			Image1->Canvas->Ellipse(get_first_x_coord(), get_first_y_coord(), get_second_x_coord(), get_second_y_coord());
		}

		void set_area_and_perimeter()
		{
			double area_value = 0;
			int perimeter_value = 0;

			int a = abs(get_first_x_coord() - get_second_x_coord()) / 2;
			int b = abs(get_first_y_coord() - get_second_y_coord()) / 2;

			area_value = 3.14 * a * b;
			perimeter_value = 3.14 * sqrt(0.5*(a*a + b*b)) * 2;

			set_area(area_value);
			set_perimeter(perimeter_value);
		}

		void scale_inc(int dx)
		{
			set_first_x_coord(get_first_x_coord() - dx);
			set_first_y_coord(get_first_y_coord() + dx);
			set_second_x_coord(get_second_x_coord() + dx);
			set_second_y_coord(get_second_y_coord() - dx);
		}

		void scale_dec(int dx)
		{
			set_first_x_coord(get_first_x_coord() + dx);
			set_first_y_coord(get_first_y_coord() - dx);
			set_second_x_coord(get_second_x_coord() - dx);
			set_second_y_coord(get_second_y_coord() + dx);
		}

		void set_center_coordinats(TEdit *Edit4, TEdit *Edit5)
		{
			set_center_x_coord(get_first_x_coord(), get_second_x_coord());
			set_center_y_coord(get_first_y_coord(), get_second_y_coord());

			Edit4 -> Text = IntToStr(get_center_x_coord());
			Edit5 -> Text = IntToStr(get_center_y_coord());
		}

};
