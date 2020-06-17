#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Tree.h"
#include "Stack.h"


Stack* CreateStack()
{
    Stack* tmp = (Stack*)malloc(sizeof(Stack));
    tmp->size = 0;
    tmp->head = NULL;

    return tmp;
}


void PushTree(Stack* treeStack, Tree* tree)
{
    if (treeStack->head == NULL)
    {
        StackNode* nodeForAdd = (StackNode*)malloc(sizeof(StackNode));
        nodeForAdd->tree = tree;
        nodeForAdd->next = NULL;

        treeStack->head = nodeForAdd;

        ++treeStack->size;
    }

    else
    {
        StackNode* currListNode = (StackNode*)malloc(sizeof(StackNode));
        currListNode = treeStack->head; // ������������� �������� ��������� ���������� ��� ������ ������

        while (true)
        {
            if (currListNode->next == NULL) // ����� ��������� ���� � ������
            {
                StackNode* nodeForAdd = (StackNode*)malloc(sizeof(StackNode)); // ������� ��������� ���������� ( ���� ����� )

                nodeForAdd->tree = tree; // ������������� � ����� ���� ������ �� ������
                nodeForAdd->next = NULL; // ������������� � ����� ���� ������ �� ����. ����

                currListNode->next = nodeForAdd; // ����������� �������������� ���� � ���� next - ����������� ����� ����

                ++treeStack->size;
                break; // ������� �� ����� � �������
            }

            currListNode = currListNode->next; // ����������� �������� ���� ������ �� ��������� ����
        }
    }
}

void DeleteStack(Stack* stack)
{
    StackNode* item = stack->head;
    StackNode* next;

    while (item->next != NULL)
    {
        next = item->next;

        free(item);

        item = next;
    }

    free(item);
}