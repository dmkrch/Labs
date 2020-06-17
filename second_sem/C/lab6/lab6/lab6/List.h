#pragma once

#ifndef SYMBOL
#define SYMBOL

/* ���������, ����������� ���� ����������� ������ */
struct Node
{
    Node* next;
    Node* prev;
    int* arr;
    int arrSize;
    int treeNumber;
};


/* ���������, ����������� ���������� ������ */
struct DoubleLinkedList
{
    int size;
    Node* head;
    Node* tail;
};


/* ������� �������� ���������� ����������� ������ */
DoubleLinkedList* CreateDblLinkedList();

/* ������� ���������� ���� � ���������� ������ */
void PushNode(DoubleLinkedList* list, int* arr, int arrSize, int treeNumber);

/* ������� �������� ������ */
void DeleteList(DoubleLinkedList* list);

#endif