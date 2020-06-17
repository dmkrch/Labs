#pragma once
#include <iostream>
#include <string>

using namespace std;

class Train
{
private:
	string startingStation;
	string terminalStation;
	string departureTime;
	string arrivalTime;
	unsigned int freePlaces;
public:
	Train();
	int setStartingStation();
	int setTerminalStation();
	int setDepartureTime();
	int setArrivalTime();
	int setFreePlaces();

	string getStartingStation();
	string getTerminalStation();
	string getArrivalTime();
	string getDepartureTime();
	unsigned int getFreePlaces();

	void showInfo();

};