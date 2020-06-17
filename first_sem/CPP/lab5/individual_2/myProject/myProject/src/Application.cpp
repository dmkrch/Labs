#include <iostream>
#include <string>
#include <vector>
#include "Engine.h"

using namespace std;

vector<Train> arrayOfTrain;

void addElement()
{
	Train temp;
	temp.setStartingStation();
	temp.setTerminalStation();
	temp.setArrivalTime();
	temp.setDepartureTime();
	temp.setFreePlaces();
	arrayOfTrain.push_back(temp);
}
void showAllInfo()
{
	for (int i = 0; i < arrayOfTrain.size(); i++)
		arrayOfTrain[i].showInfo();
}
void createClasses(int n)
{
	arrayOfTrain.clear();
	for (int i = 0; i < n; i++)
		addElement();
}
void findByAndShow(short filter, string keyword)//0 for startingStation, 1 for terminalStation, 2 for departureTime,
{												//3 for arrivalTime, 4 for freePlaces
	for (int i = 0; i < arrayOfTrain.size(); i++)
	{
		string temp;
		switch (filter)
		{
		case 0:
			temp = arrayOfTrain[i].getStartingStation();
			break;
		case 1:
			temp = arrayOfTrain[i].getTerminalStation();
			break;
		case 2:
			temp = arrayOfTrain[i].getDepartureTime();
			break;
		case 3:
			temp = arrayOfTrain[i].getArrivalTime();
			break;
		case 4:
			temp = arrayOfTrain[i].getFreePlaces();
			break;
		}
		if (temp == keyword)
			arrayOfTrain[i].showInfo();
	}
}
void findByAndChange(short filter, string keyword)//0 for startingStation, 1 for terminalStation, 2 for departureTime,
{												//3 for arrivalTime, 4 for freePlaces
	for (int i = 0; i < arrayOfTrain.size(); i++)
	{
		string temp;
		switch (filter)
		{
		case 0:
			temp = arrayOfTrain[i].getStartingStation();
			break;
		case 1:
			temp = arrayOfTrain[i].getTerminalStation();
			break;
		case 2:
			temp = arrayOfTrain[i].getDepartureTime();
			break;
		case 3:
			temp = arrayOfTrain[i].getArrivalTime();
			break;
		case 4:
			temp = arrayOfTrain[i].getFreePlaces();
			break;
		}
		if (temp == keyword)
		{
			arrayOfTrain[i].setStartingStation();
			arrayOfTrain[i].setTerminalStation();
			arrayOfTrain[i].setArrivalTime();
			arrayOfTrain[i].setDepartureTime();
			arrayOfTrain[i].setFreePlaces();
		}
	}
}
void findByAndDelete(short filter, string keyword)//0 for startingStation, 1 for terminalStation, 2 for departureTime,
{												//3 for arrivalTime, 4 for freePlaces
	for (int i = 0; i < arrayOfTrain.size(); i++)
	{
		string temp;
		switch (filter)
		{
		case 0:
			temp = arrayOfTrain[i].getStartingStation();
			break;
		case 1:
			temp = arrayOfTrain[i].getTerminalStation();
			break;
		case 2:
			temp = arrayOfTrain[i].getDepartureTime();
			break;
		case 3:
			temp = arrayOfTrain[i].getArrivalTime();
			break;
		case 4:
			temp = arrayOfTrain[i].getFreePlaces();
			break;
		}
		if (temp == keyword)
			arrayOfTrain.erase(arrayOfTrain.begin() + i);
	}
}

void desendingSortByFreePlaces()
{
	vector<Train> temp;
	for (int i = 0; i < arrayOfTrain.size(); i++)
	{
		temp.push_back(arrayOfTrain[i]);
		for (int j = temp.size() - 1; j > 0 && temp[j].getFreePlaces() > temp[j - 1].getFreePlaces(); j--)
		{
			Train tempOne = temp[j];
			temp[j] = temp[j - 1];
			temp[j - 1] = tempOne;
		}
	}
	arrayOfTrain = temp;
}

int main()
{
	int n;
	printf_s("Enter amount of classes: ");
	scanf_s("%i", &n);
	createClasses(n);
	string destination;
	printf_s("Enter destination for sort: ");
	cin >> destination;
	desendingSortByFreePlaces();
	findByAndShow(1, destination);
	return 0;
}