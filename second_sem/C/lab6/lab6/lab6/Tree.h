#pragma once



/* ���������, ����������� ���� ��������� ������ */
struct TreeNode
{
    int key;

    TreeNode* left;
    TreeNode* right;
};

/* ���������, ����������� �������� ������ ������ */
struct Tree
{
    TreeNode* root;

    int pos;
    int size;
};


/* ������� �������� ���������� ��������� ���������� ������ */
Tree* CreateTree();

/* ������� ���������� ���� ������ � ������ */
void PushTreeNode(TreeNode* root, int key);

/* ������� �������� ������ */
void DeleteTree(TreeNode* leaf);