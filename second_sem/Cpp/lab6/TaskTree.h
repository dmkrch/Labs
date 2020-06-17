//---------------------------------------------------------------------------

#ifndef TaskTreeH
#define TaskTreeH
//---------------------------------------------------------------------------
#endif

#include "Tree.h"
#include <vcl.h>
#include <vector>
#include <string>



template <typename T>
class TaskTree : public Tree<T>
{
public:
	TaskTree() : Tree<T>()
	{

	}

	void Show_tree(TTreeView *TreeView)
	{
		int index = 0;
		TreeView->Items->Clear();
		if(root)
		{
			String add_input  = " ";
			add_input += root->value;
			String input = (root->data).c_str() + add_input;
			TreeView->Items->Add(NULL, input);
			Print_tree(root, TreeView, index);
		}
	}

	int Amount_of_left_nodes()
	{
		counter = 0;

		return Amount_of_left_nodes(root);
	}

	void Get_Node_Data(Node<T>* ptr, std::vector <int>& keys, std::vector<T>& data)
	{
		if(ptr)
		{
			Get_Node_Data(ptr->left, keys, data);

			keys.push_back(ptr->value);
			data.push_back(ptr->data);

			Get_Node_Data(ptr->right, keys, data);
		}
	}

	TaskTree<T>* CreateBalancedTree(Node<T>* ptr, TMemo* Memo1)
	{
		TaskTree<String> *tree = new TaskTree<String>;

		std::vector<int> values;
		std::vector<String> data;

		Get_Node_Data(ptr, values, data);
		BalanceTree(tree, 0, values.size() - 1, (values.size() - 1) / 2, values, data);

		return tree;
	}

	void BalanceTree(TaskTree<String> *tree, int begin, int end, int value, std::vector<int> values, std::vector<T> data)
	{
		if ((end - begin) == 1)
		{
			tree->Insert(values[begin], data[begin]);
			tree->Insert(values[end], data[end]);
			return;
		}

		else if (begin == end)
		{
			tree->Insert(values[begin], data[begin]);
			return;
		}

		else
		{
			tree->Insert(values[value], data[value]);
		}

		BalanceTree(tree, begin, value - 1, (begin + value - 1) / 2, values, data);
		BalanceTree(tree, value + 1, end, (value + 1 + end) / 2, values, data);
	}

private:
	void Print_tree(Node<T>* temp, TTreeView *TreeView, int &index)
	{
		int i = index;

		if(temp->left)
		{
			String add_input =  " ";
			add_input += temp->left->value;
			String input = (temp->left->data).c_str() + add_input;
			TreeView->Items->AddChild(TreeView->Items->Item[i], input);
			Print_tree(temp->left, TreeView, ++index);
		}
		if(temp->right)
		{
			String add_input = " ";
			add_input += temp->right->value;
			String input = (temp->right->data).c_str() + add_input;
			TreeView->Items->AddChild(TreeView->Items->Item[i], input);
			Print_tree(temp->right, TreeView, ++index);
		}
	}

	int Amount_of_left_nodes(Node<T>* ptr)
	{
		if(ptr->left != NULL)
			Amount_of_left_nodes(ptr->left);

		if(ptr == root)
			return counter;

		++counter;

		if(ptr->right != NULL)
			Amount_of_left_nodes(ptr->right);
	}

	int counter;
};
