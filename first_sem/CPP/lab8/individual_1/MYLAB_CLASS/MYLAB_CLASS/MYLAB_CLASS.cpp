#include <stdio.h>
#include <iostream>
#include <string> 

class Lists
{
private:
	std::string name;
	std::string date;
	std::string status;
public:
	void GetInfo()
	{
		std::cout << "\nEnter the name of item you want to add ";
		getline(std::cin, name);
		std::cout << "Enter the date when item was delivered ";
		getline(std::cin, date);

		while (1)
		{
			std::cout << "Enter the status of item (ready \ not ready) ";
			getline(std::cin, status);

			if (status == "ready" || status == "not ready")
				break;
		} 
	}

	void ShowInfo()
	{
		std::cout << "\nName of item: " << name;
		std::cout << "\nDate when item was delivered: " << date;
		std::cout << "\nStatus: " << status << "\n\n";
	}

	std::string GetStatus()
	{
		return status;
	}
};

void sort(Lists* arr_lists, int number_of_lists)
{
	for (int i = 1; i < number_of_lists; i++)
	{
		for (int j = number_of_lists - 1; j >= i; j--)
			if ((arr_lists[j - 1].GetStatus() == "not ready")&&(arr_lists[j].GetStatus() == "ready"))
			{
				Lists x = arr_lists[j - 1];
				arr_lists[j - 1] = arr_lists[j];
				arr_lists[j] = x;
			}
	}
}
void output_info(Lists* arr_lists, int number_of_lists)
{
	int switch_choose;
	bool check_for_exit = true;

	do
	{
		do
		{
			std::cout << "\n\n#1 show all lists - enter 1\n#2 show READY lists - enter 2\n#3 show NOT READY lists - enter 3\n#4 exit - enter 4\n\n";
			std::cin >> switch_choose;
		} 
		while (switch_choose < 1 || switch_choose > 4);


		switch (switch_choose)
		{
		case 1:
			std::cout << "ALL LISTS\n";
			for (int i = 0; i < number_of_lists; ++i)
				arr_lists[i].ShowInfo();
			break;

		case 2:
			std::cout << "READY LISTS\n";
			for (int i = 0; i < number_of_lists; ++i)
				if (arr_lists[i].GetStatus() == "ready")
					arr_lists[i].ShowInfo();
				else
					break;
			break;

		case 3:
			std::cout << "NOT READY LISTS\n";
			for (int i = 0; i < number_of_lists; ++i)
				if (arr_lists[i].GetStatus() == "not ready")
					arr_lists[i].ShowInfo();
			break;

		case 4:
			check_for_exit = false;
			break;
		}
	} while (check_for_exit == true);
}

int main()
{ 
	// Getting number of lists and allocating memory to massive according to it
	Lists* arr_lists;
	int number_of_lists;

	std::cout << "How many lists you want to create? ";
	std::cin >> number_of_lists;

	while (std::cin.get() != '\n')
		continue;

	arr_lists = new Lists[number_of_lists];


	// Getting info of lists
	for (int i = 0; i < number_of_lists; ++i)
		arr_lists[i].GetInfo();


	// Sorting lists and showing menu to control
	sort(arr_lists, number_of_lists);
	output_info(arr_lists, number_of_lists);

}