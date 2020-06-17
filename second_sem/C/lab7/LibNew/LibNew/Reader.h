#pragma once


#include "ListDeal.h"


/* ���������, ����������� �������� */
struct Reader
{
	char* surname;
	char* name;
	int group;
	char* telephoneNumber;
	char* email;
	char* note;
	ListDeal* dealList;
	int penalty;
};



/* ������� ������ ������ Reader �� ��� ����������, ��� ���������� � ���������� */
Reader* CreateReader(char* surname, char* name, int group, char* number, char* email, char* note);