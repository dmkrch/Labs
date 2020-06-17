#pragma once
#include "Book.h"


/* ���������, ����������� ���� ������ */
struct DealDate
{
	int year;
	int month;
	int day;
};

/* ���������, ����������� ������ */
struct Deal
{
	Book* book;
	DealDate* dealDate;
};



/* ������� ������ ������ Deal */
Deal* CreateDeal(Book* book, DealDate* dealDate);

/* ������� ������ ������ DealDate */
DealDate* CreateDealDate(int year, int month, int day);