#pragma once

#include "Reader.h"


/* ���������, ����������� ���� ������, �������� ����� */
struct NodeReader
{
	NodeReader* next;

	Reader* reader;
};

/* ���������, ����������� ������, �������� ��������� */
struct ListReader
{
	NodeReader* head;

	int size;
};



/* ������� ������ �������� � ���������� �� ��� ����������, ��� ������ ������������ */
void AddNewReader(ListReader* listReader);

/* ������� ������ ������ ListReader*/
ListReader* CreateListReader();

/* ��������� ������ ������ Reader � ������ ������ ListReader */
void AddReader(ListReader* listReader, Reader* reader);

/* ���� �������� �� ������� � ������ ������ � ���������� ����� ������ ������ Reader */
Reader* FindReader(ListReader* listReader, char* surname, int group);