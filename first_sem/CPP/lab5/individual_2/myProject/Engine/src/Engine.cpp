#include <iostream>
#include <string>
#include "Engine.h"

using namespace std;

Train::Train()
{
	startingStation = "[none]";
	terminalStation = "[none]";
	departureTime = "[none]";
	arrivalTime = "[none]";
	freePlaces = NULL;
	printf_s("New Train structure created\n");
}

int Train::setStartingStation()
{
	printf_s("Current value of startingStation field: %s. Enter new value of startingStation field: "
		, getStartingStation().c_str());
	string temp;
	cin >> temp;
	if (temp.size() != 0)
	{
		startingStation = temp;
		printf_s("Value changed successfully.\n");
		return 0;
	}
	else
	{
		printf_s("Some shit went wrong. Value hasn't been changed\n");
		return 1;
	}
}
int Train::setTerminalStation()
{
	printf_s("Current value of terminalStation field: %s. Enter new value of terminalStation field: "
		, getTerminalStation().c_str());
	string temp;
	cin >> temp;
	if (temp.size() != 0)
	{
		terminalStation = temp;
		printf_s("Value changed successfully.\n");
		return 0;
	}
	else
	{
		printf_s("Some shit went wrong. Value hasn't been changed\n");
		return 1;
	}
}
int Train::setDepartureTime()
{
	printf_s("Current value of departureTime field: %s. Enter new value of departureTime field: "
		, getDepartureTime().c_str());
	string temp;
	cin >> temp;
	if (temp.size() != 0)
	{
		departureTime = temp;
		printf_s("Value changed successfully.\n");
		return 0;
	}
	else
	{
		printf_s("Some shit went wrong. Value hasn't been changed\n");
		return 1;
	}
}
int Train::setArrivalTime()
{
	printf_s("Current value of arrivalTime field: %s. Enter new value of arrivalTime field: "
		, getArrivalTime().c_str());
	string temp;
	cin >> temp;
	if (temp.size() != 0)
	{
		arrivalTime = temp;
		printf_s("Value changed successfully.\n");
		return 0;
	}
	else
	{
		printf_s("Some shit went wrong. Value hasn't been changed\n");
		return 1;
	}
}
int Train::setFreePlaces()
{
	printf_s("Current value of freePlaces field: %u. Enter new value of freePlaces field: "
		, getFreePlaces());
	int temp;
	scanf_s("%i", &temp);
	if (temp >= 0)
	{
		freePlaces = temp;
		printf_s("Value changed successfully.\n");
		return 0;
	}
	else
	{
		printf_s("Some shit went wrong. Value hasn't been changed\n");
		return 1;
	}
}

string Train::getStartingStation()
{
	return startingStation;
}
string Train::getTerminalStation()
{
	return terminalStation;
}
string Train::getArrivalTime()
{
	return arrivalTime;
}
string Train::getDepartureTime()
{
	return departureTime;
}
unsigned int Train::getFreePlaces()
{
	return freePlaces;
}

void Train::showInfo()
{
	printf_s("Train info:\n");
	printf_s("Starting station: %s\n", getStartingStation().c_str());
	printf_s("Terminal station: %s\n", getTerminalStation().c_str());
	printf_s("Arrival time: %s\n", getArrivalTime().c_str());
	printf_s("Departure time: %s\n", getDepartureTime().c_str());
	printf_s("Free places: %u\n", getFreePlaces());
}