#pragma once

#include "ListBook.h"
#include "ListReader.h"

/* ���������, ����������� ���������� */
struct CathLibrary
{
	ListBook* bookList;
	ListReader* readerList;
};



CathLibrary* CreateCathLibrary();