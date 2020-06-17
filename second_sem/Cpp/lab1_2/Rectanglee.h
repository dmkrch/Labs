#ifndef RectangleeH
#define RectangleeH


#include "Figure.h"
#include <vcl.h>

#endif

class Rectanglee : public Figure
{
	public:
		Rectanglee()
		{

		}

		void show(TCanvas *Canvas, TImage *Image1)
		{
			Image1 -> Canvas -> MoveTo(get_first_x_coord(), get_first_y_coord());

			Image1 -> Canvas -> LineTo(get_second_x_coord(), get_second_y_coord());
			Image1 -> Canvas -> LineTo(get_third_x_coord(), get_third_y_coord());
			Image1 -> Canvas -> LineTo(get_fourth_x_coord(), get_fourth_y_coord());
			Image1 -> Canvas -> LineTo(get_first_x_coord(), get_first_y_coord());


			Image1->Canvas->FloodFill(get_center_x_coord(), get_center_y_coord(), Image1->Canvas->Pixels[get_center_x_coord()][get_center_y_coord()], fsSurface);
		}

		void set_area_and_perimeter()
		{
			int a = abs(get_first_x_coord() - get_fourth_x_coord());
			int b = abs(get_first_y_coord() - get_second_y_coord());

			set_area(a * b);
			set_perimeter(2 * a + 2 * b);
		}

		void move(int dx, int dy)
		{
			set_center_x_coord(dx + get_center_x_coord());
			set_center_y_coord(dy + get_center_y_coord());

			set_first_x_coord(dx + get_first_x_coord());
			set_first_y_coord(dy + get_first_y_coord());

			set_second_x_coord(dx + get_second_x_coord());
			set_second_y_coord(dy + get_second_y_coord());

			set_third_x_coord(dx + get_third_x_coord());
			set_third_y_coord(dy + get_third_y_coord());

			set_fourth_x_coord(dx + get_fourth_x_coord());
			set_fourth_y_coord(dy + get_fourth_y_coord());
		}

		void hide(TCanvas *Canvas, TImage *Image1)
		{
			Image1->Canvas->Pen->Color=clWhite;
			Image1->Canvas->Brush->Color=clWhite;

			show(Image1 -> Canvas, Image1);
		}

		void scale_inc(int dx)
		{
			set_first_x_coord(get_first_x_coord() - dx);
			set_first_y_coord(get_first_y_coord() + dx);

			set_second_x_coord(get_second_x_coord() - dx);
			set_second_y_coord(get_second_y_coord() - dx);

			set_third_x_coord(get_third_x_coord() + dx);
			set_third_y_coord(get_third_y_coord() - dx);

			set_fourth_x_coord(get_fourth_x_coord() + dx);
			set_fourth_y_coord(get_fourth_y_coord() + dx);
		}

		void scale_dec(int dx)
		{
			set_first_x_coord(get_first_x_coord() + dx);
			set_first_y_coord(get_first_y_coord() - dx);

			set_second_x_coord(get_second_x_coord() + dx);
			set_second_y_coord(get_second_y_coord() + dx);

			set_third_x_coord(get_third_x_coord() - dx);
			set_third_y_coord(get_third_y_coord() + dx);

			set_fourth_x_coord(get_fourth_x_coord() - dx);
			set_fourth_y_coord(get_fourth_y_coord() - dx);
		}

		void set_center_coordinats(TEdit *Edit4, TEdit *Edit5)
		{
			set_center_x_coord(get_first_x_coord(), get_second_x_coord(), get_third_x_coord(), get_fourth_x_coord());
			set_center_y_coord(get_first_y_coord(), get_second_y_coord(), get_third_y_coord(), get_fourth_y_coord());

			Edit4 -> Text = IntToStr(get_center_x_coord());
			Edit5 -> Text = IntToStr(get_center_y_coord());
		}

};
