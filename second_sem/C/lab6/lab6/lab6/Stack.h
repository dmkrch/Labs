#pragma once



/* ���������, ����������� ���� �����, ��������� ������� */
struct StackNode
{
    Tree* tree;
    StackNode* next;
};

/* ���������, ����������� ���� �����, ��������� ������� */
struct Stack
{
    StackNode* head;

    int size;
};


/* ������� �������� ���������� ����� */
Stack* CreateStack();

/* ������� ���������� ������ "tree" � ���� "treeStack" */
void PushTree(Stack* treeStack, Tree* tree);

/* ������� �������� ����� */
void DeleteStack(Stack* stack);