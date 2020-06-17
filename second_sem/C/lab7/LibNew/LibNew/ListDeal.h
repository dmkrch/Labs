#pragma once

#include "Deal.h"


/* ���������, ����������� ���� ������  */
struct NodeDeal
{
	NodeDeal* next;

	Deal* deal;
};

/* ���������, ����������� ������, �������� ������ */
struct ListDeal
{
	NodeDeal* head;

	int size;
};



/* ��������� ������ ������ Deal � ������ ������ ListDeal*/
void AddDeal(ListDeal* dealList, Deal* deal);

/* ���� ������ Deal �� �������� ����� � ������ � ���������� ���� ������ */
Deal* FindDeal(ListDeal* listDeal, char* title);

/* ������� ������ deal �� listDeal */
void RemoveDeal(Deal* deal, ListDeal* listDeal);