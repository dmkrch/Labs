#pragma once


/* ���������, ����������� ����� */
struct Book
{
	char* author;
	char* title;
	char* note;
	int price;
};



/* ������� ������ ������ Book */
Book* CreateBook(char* author, char* title, int price, char* note);