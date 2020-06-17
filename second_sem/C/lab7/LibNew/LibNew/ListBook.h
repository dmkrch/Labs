#pragma once

#include "Book.h"


/* ���������, ����������� ���� ������, �������� ��������� */
struct NodeBook
{
	NodeBook* next;

	Book* book;
	int quantity;
};

/* ���������, ����������� ������, �������� ��������� */
struct ListBook
{
	NodeBook* head;

	int size;
};



/* ������� ������ ������ ListBook */
ListBook* CreateListBook();

/* ��������� ������ ������ Book � ������ ������ ListBook */
void AddBook(ListBook* listBook, Book* book, int quantity);

/* ���� ����� �� �������� � ���������� ����� ������ ������ Book */
Book* FindBook(ListBook* listBook, char* title);

/* ������� ����� Book �� ListBook */
void RemoveBook(Book* book, ListBook* listBook);