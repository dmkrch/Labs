#include <stdio.h>
#include <iostream>

#include <fstream>
#include <string>

class Receipt
{
public:

	Receipt(std::string name, std::string address, std::string date, int hash)
	{
		_name = name;
		_address = address;
		_date = date;
		_hash = hash;
	}

	Receipt()
	{

	}

	std::string get_name()
	{
		return _name;
	}

	std::string get_address()
	{
		return _address;
	}

	std::string get_date()
	{
		return _date;
	}

	void set_name(std::string name)
	{
		_name = name;
	}

	void set_address(std::string address)
	{
		_address = address;
	}

	void set_date(std::string date)
	{
		_date = date;
	}

	int get_hash()
	{
		return _hash;
	}

private:
	std::string _name{};
	std::string _address{};
	std::string _date{};
	int _hash;
};

class TailorShop
{
public:

	void file_input()
	{
		std::ofstream fout;
		fout.open("myFile.txt", std::ios::app);

		for (int i = 0; i < counter; ++i)
		{
			fout << "\nName: " << massive[i].get_name() << "\n";
			fout << "Address: " << massive[i].get_address() << "\n";
			fout << "Date: " << massive[i].get_date() << "\n";
			fout << "Hash: " << massive[i].get_hash() << "\n";
		}

		fout.close();
	}
	void edit_receipt(int hash)
	{
		for (int i = 0; i < counter; ++i)
			if (massive[i].get_hash() == hash)
			{
				int choice;
				std::string line;

				std::cout << "\t\t#1 Edit name - enter 1\n\t\t#2 Edit address - enter 2\n\t\t#3 Edit date - enter 3\n";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					std::cout << "\t\t\tEnter new name ";
					std::cin >> line;

					massive[i].set_name(line);
					break;

				case 2:
					std::cout << "\t\t\tEnter new address ";

					while (std::cin.get() != '\n')
						continue;

					getline(std::cin, line);

					massive[i].set_address(line);
					break;
				case 3:
					std::cout << "\t\t\tEnter new date ";
					std::cin >> line;

					massive[i].set_date(line);
					break;
				}
				system("cls");
			}
	}
	void delete_receipt(int hash)
	{
		for (int i = 0; i < counter; ++i)
			if (massive[i].get_hash() == hash)
			{
				Receipt* temp = nullptr;
				temp = new Receipt[counter - 1];

				for (int j = i; j < counter - 1; ++j)
				{
					massive[j] = massive[j + 1];
				}

				for (int i = 0; i < counter - 1; ++i)
				{
					temp[i] = massive[i];
				}

				massive = temp;
				--counter;
			}
	}
	void delete_same_receipts()
	{
		for (int i = 0; i < counter; ++i)
		{
			std::string temp_name = massive[i].get_name();

			for (int j = i + 1; j < counter; ++j)
			{
				if (massive[j].get_name() == temp_name)
				{
					delete_receipt(massive[j].get_hash());
					--j;
				}
			}
		}
	}
	void show_all_receipts()
	{
		std::cout << "All receipts are\n\n";

		for (int i = 0; i < counter; ++i)
		{
			std::cout << "\nName: " << massive[i].get_name() << "\n";
			std::cout << "Address: " << massive[i].get_address() << "\n";
			std::cout << "Date: " << massive[i].get_date() << "\n";
			std::cout << "Hash: " << massive[i].get_hash() << "\n";
		}

	}
	void show_hash_receipt(int hash)
	{
		for (int i = 0; i < counter; ++i)
			if (massive[i].get_hash() == hash)
			{
				std::cout << "\nName: " << massive[i].get_name() << "\n";
				std::cout << "Address: " << massive[i].get_address() << "\n";
				std::cout << "Date: " << massive[i].get_date() << "\n";
				std::cout << "Hash: " << massive[i].get_hash() << "\n";
			}
	}
	void add_Receipt(Receipt receipt)
	{
		Receipt* temp = nullptr;

		if (counter == 0)
		{
			massive = new Receipt;
			massive[0] = receipt;
		}

		else
		{
			temp = new Receipt[counter + 1];

			for (int i = 0; i < counter; ++i)
				temp[i] = massive[i];

			temp[counter] = receipt;
			massive = temp;
		}

		++counter;
	}

private:
	int counter = 0;
	Receipt* massive = nullptr;
};

int main()
{

	int choice;
	int counter = 1;
	TailorShop tailor_shop;

	while (1)
	{
		std::cout << "\n----------------------------------\n|  #1 Add a receipt - enter 1    |\n|  #2 Delete a receipt - enter 2 |\n|  #3 Edit a receipt - enter 3   |\n|  #4 Show a receipt             |\n|  #5 Exit - enter 5             |\n----------------------------------\n";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			int amount;
			std::cout << "Enter number of receipts you want to add ";
			std::cin >> amount;
			system("cls");

			for (int i = 0; i < amount; i++)
			{
				int hash = counter;

				std::string name;
				std::string date;
				std::string address;
				std::cout << "\nEnter name ";
				std::cin >> name;

				while (std::cin.get() != '\n')
					continue;

				std::cout << "Enter address ";
				getline(std::cin, address);

				std::cout << "Enter date ";
				std::cin >> date;

				system("cls");

				Receipt receipt(name, address, date, hash);
				tailor_shop.add_Receipt(receipt);

				++counter;
			}
			tailor_shop.file_input();
			break;

		case 2:
			int choice;
			std::cout << "\t#1 - delete exact receipt - enter 1\n\t#2 - delete same recipts - enter 2\n";
			std::cin >> choice;
			if (choice == 1)
			{
				int hash;
				std::cout << "\n\t\tEnter receipt's hash\n";
				std::cin >> hash;
				tailor_shop.delete_receipt(hash);
			}
			else if (choice == 2)
			{
				tailor_shop.delete_same_receipts();
			}
			tailor_shop.file_input();
			system("cls");
			break;

		case 3:
			int hash_1;
			std::cout << "\n\tEnter receipt's hash ";
			std::cin >> hash_1;

			while (std::cin.get() != '\n')
				continue;

			tailor_shop.edit_receipt(hash_1);
			tailor_shop.file_input();
			system("cls");
			break;

		case 4:
			int choice_2;

			std::cout << "\t#1 Show all receipts - enter 1\n\t#2 Show exact receipts - enter 2\n";
			std::cin >> choice_2;
			system("cls");

			if (choice_2 == 1)
				tailor_shop.show_all_receipts();
			else if (choice_2 == 2)
			{
				int hash_2;
				std::cout << "Enter the hash of receipt you want to show ";
				std::cin >> hash_2;
				system("cls");
				tailor_shop.show_hash_receipt(hash_2);
			}
			break;
		case 5:
			return 0;
		}
	}
}