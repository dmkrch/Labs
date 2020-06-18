#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "List.h"  // ������������ ���� ����������� ������
#include "Tree.h"  // ������������ ���� ������
#include "Stack.h" // ������������ ���� �����



/* ������� ������������ �������� �� ������ ����������, ���������� � ���������� ������. �������� List - ������ �
   treeStack - ��� �������� ���������� �������� */
void AddTreeFromList(DoubleLinkedList* List, Stack* treeStack)
{
    Node* currListNode = (Node*)malloc(sizeof(Node)); // ������� ��������� ���������� ����� ������ ����� �� ����� ����������� ������
    currListNode = List->head; // ������������� �������� � "������" ������

    for (int i = 0; i < List->size; ++i)
    {

        Tree* tree = CreateTree(); // ������� ������

        tree->pos = currListNode->treeNumber; // ������������� ���� pos ������

        for (int k = 0; k < currListNode->arrSize; ++k) // ���� ���������� ����� ������ �� ������ ������� ����� �����
        {

            if(tree->root != NULL)
                PushTreeNode(tree->root, currListNode->arr[k]);
            else
            {
                TreeNode* newNode = new TreeNode();
                newNode->left = NULL;
                newNode->right = NULL;
                newNode->key = currListNode->arr[k];

                tree->root = newNode;
            }
        }


        // ��������� ������ Tree - tree ��������� ����������� � ������ ����� ���� �������� � ����
        PushTree(treeStack, tree);


        // ������ ���� ���������� ��������� � ��������� ���������� �� ���� �����, ����� ������ ������� ������ � ������� ����� ������
        currListNode = currListNode->next;
    }
}


void ShowHighestKeyOfTrees(Stack* treeStack)
{
    StackNode* currNode = treeStack->head; // ������� ��������� ���������� ������������ ������� ���� �����

    while(currNode != NULL)
    {
        TreeNode* root = currNode->tree->root; // ������� ���� ������ �������� ���� ����� ��� ������

        while (root->right != NULL)  // �� ��������� ����� � root ����� ����, �������� �������� �����������
            root = root->right;
        
        printf("Max key of tree #%d = %d\n", currNode->tree->pos, root->key);

        currNode = currNode->next; // ������������� �������� �������� ���� ����� �� �������� ����
    }
}

int main()
{
    DoubleLinkedList* List = CreateDblLinkedList();

    int arr[3] = { 1,2,3 };
    int arr1[4] = { 3,7,4,8 };
    int arr2[5] = { 2,9,7,3,6 };

    PushNode(List, arr, 3, 34);
    PushNode(List, arr1, 4, 75);
    PushNode(List, arr2, 5, 22);
    // �� ������ ������ ����������� ���������� ������ List � ����� ������, ������� ����� �� ������ ������������� � �������


    // ������ ������� ����(���������) ��� �������� ��������
    Stack* treeStack = CreateStack();

    //��������� � ���� ������� �� ������ ����������, ������� � ����� ����������� ������
    AddTreeFromList(List, treeStack);


    // ������ � ���������� treeStack ������������ ������� � ����� ������� 
    // ������� ����� �������� ��� ����������� ����������� ����� � ������ ������
    ShowHighestKeyOfTrees(treeStack);

    DeleteList(List);
    DeleteStack(treeStack);
}