#ifndef FigureH
#define FigureH

#pragma once

#endif



class Figure
{
	public:
		void set_area(double area)
		{
			this -> area = area;
		}

		void set_perimeter(int perimeter)
		{
			this -> perimeter = perimeter;
		}

		double get_area()
		{
			return area;
		}

		int get_perimeter()
		{
			return perimeter;
		}

		void set_first_x_coord(int coord)
		{
			first_x_coord = coord;
		}

		void set_first_y_coord(int coord)
		{
			first_y_coord = coord;
		}

		void set_second_x_coord(int coord)
		{
			second_x_coord = coord;
		}

		void set_second_y_coord(int coord)
		{
			second_y_coord = coord;
		}

		void set_third_x_coord(int coord)
		{
			third_x_coord = coord;
		}

		void set_third_y_coord(int coord)
		{
			third_y_coord = coord;
		}

		void set_fourth_x_coord(int coord)
		{
			fourth_x_coord = coord;
		}

		void set_fourth_y_coord(int coord)
		{
			fourth_y_coord = coord;
		}

		int get_first_x_coord()
		{
			return first_x_coord;
		}

		int get_first_y_coord()
		{
			return first_y_coord;
		}

		int get_second_x_coord()
		{
			return second_x_coord;
		}

		int get_second_y_coord()
		{
			return second_y_coord;
		}

		int get_third_x_coord()
		{
			return third_x_coord;
		}

		int get_third_y_coord()
		{
			return third_y_coord;
		}

		int get_fourth_x_coord()
		{
			return fourth_x_coord;
		}

		int get_fourth_y_coord()
		{
			return fourth_y_coord;
		}

		void set_center_x_coord(int coord)
		{
			center_x_coord = coord;
		}

		void set_center_x_coord(int coord1, int coord2)
		{
			center_x_coord = (coord1 + coord2) / 2;
		}

		void set_center_x_coord(int coord1, int coord2, int coord3)
		{
			center_x_coord = (coord1 + coord2 + coord3) / 3;
		}

		void set_center_x_coord(int coord1, int coord2, int coord3, int coord4)
		{
			center_x_coord = (coord1 + coord2  + coord3 + coord4) / 4;
		}

		void set_center_y_coord(int coord)
		{
			center_y_coord = coord;
		}

		void set_center_y_coord(int coord1, int coord2)
		{
			center_y_coord = (coord1 + coord2) / 2;
		}

		void set_center_y_coord(int coord1, int coord2, int coord3)
		{
			center_y_coord = (coord1 + coord2 + coord3) / 3;
		}

		void set_center_y_coord(int coord1, int coord2, int coord3, int coord4)
		{
			center_y_coord = (coord1 + coord2  + coord3 + coord4) / 4;
		}

		int get_center_x_coord()
		{
			return center_x_coord;
		}

		int get_center_y_coord()
		{
			return center_y_coord;
		}

	private:
		double area;
		int perimeter;
		int first_x_coord;
		int first_y_coord;
		int second_x_coord;
		int second_y_coord;
		int third_x_coord;
		int third_y_coord;
		int fourth_x_coord;
		int fourth_y_coord;
		int center_x_coord;
		int center_y_coord;
};

