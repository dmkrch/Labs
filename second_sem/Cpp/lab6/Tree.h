#ifndef TreeH
#define TreeH

#endif

#include <vcl.h>

template <typename T>
class Node
{
public:
	Node(int value, T data)
	{
		this->value = value;
		this->data = data;

		right = NULL;
		left = NULL;
	}

	T data;
	int value;
	Node* left;
	Node* right;
};



template <typename T>
class Tree
{
public:
	Tree() { root = NULL; }
	~Tree() { Destroy_tree(); }

	void Key_print(TMemo* Memo1);
	void Backward_print(TMemo* Memo1);
	void Direct_print(TMemo* Memo1);
	void Delete_node(int key);
	void Show(int key, TMemo* Memo1);
	void Destroy_tree();
	void Insert(int key, T data = T());
	void Add_array_info(int array[], int length, String array2[]);
	Node<T>* Search(int key);

	Node<T>* root;

private:
	Node<T>* Delete_node(Node<T>* temp, int key);
	void Destroy_tree(Node<T>* leaf);
	void Insert(int key, T data, Node<T>* leaf);
	void Key_print(TMemo* Memo1, Node<T>* root);
	void Backward_print(TMemo* Memo1, Node<T>* root);
	void Direct_print(TMemo* Memo1, Node<T>* root);
	Node<T>* Search(int key, Node<T>* leaf);
};


template <typename T>
void Tree<T>::Destroy_tree(Node<T>* leaf)
{
	if (leaf != NULL)
	{
		Destroy_tree(leaf->left);
		Destroy_tree(leaf->right);
		delete leaf;
	}
}


template <typename T>
void Tree<T>::Insert(int key, T data, Node<T>* leaf)
{

	if (key < leaf->value)
	{
		if (leaf->left != NULL)
		{
			Insert(key, data, leaf->left);
		}
		else
		{
			leaf->left = new Node<T>(key, data);
		}
	}
	else if (key >= leaf->value)
	{
		if (leaf->right != NULL)
		{
			Insert(key, data, leaf->right);
		}
		else
		{
			leaf->right = new Node<T>(key, data);
		}
	}

}


template <typename T>
void Tree<T>::Insert(int key, T data)
{
	if (root != NULL)
	{
		Insert(key, data, root);
	}
	else
	{
		root = new Node<T>(key, data);
	}
}

template <typename T>
Node<T>* Tree<T>::Delete_node(Node<T>* node, int value)
{

    if(node == NULL)
        return node;

	if(value == node->value)
	{

		Node<T>* temp;
        if(node->right == NULL)
			temp = node->left;

		else
		{
			Node<T>* ptr = node->right;
			if(ptr->left == NULL)
			{
                ptr->left = node->left;
				temp = ptr;
			}
			else
			{

				Node<T>* pmin = ptr->left;

				while(pmin->left != NULL)
				{
                    ptr  = pmin;
                    pmin = ptr->left;
				}

				ptr->left   = pmin->right;
                pmin->left  = node->left;
                pmin->right = node->right;
				temp = pmin;
            }
        }

        delete node;
		return temp;
	}

	else if(value < node->value)
		node->left  = Delete_node(node->left, value);

    else
		node->right = Delete_node(node->right, value);

    return node;
}



template <typename T>
void Tree<T>::Delete_node(int key)
{
	root = Delete_node(root, key);
}


template <typename T>
Node<T>* Tree<T>::Search(int key, Node<T>* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
		{
			return leaf;
		}
		if (key < leaf->value)
		{
			return Search(key, leaf->left);
		}
		else
		{
			return Search(key, leaf->right);
		}
	}
	else
	{
		return NULL;
	}
}


template <typename T>
Node<T>* Tree<T>::Search(int key)
{
	return Search(key, root);
}


template<typename T>
void Tree<T>::Show(int key, TMemo* Memo1)
{
	Node<T>*current = Search(key);

	Memo1 -> Lines -> Add(current->data);
}


template <typename T>
void Tree<T>::Destroy_tree()
{
	Destroy_tree(root);
}


template <typename T>
void Tree<T>::Add_array_info(int values[], int length, String data[])
{
	for(int i = 0; i < length; ++i)
	{
		Insert(values[i], data[i]);
	}
}

template <typename T>
void Tree<T>::Direct_print(TMemo *Memo1)
{
	Direct_print(Memo1, root);
}

template <typename T>
void Tree<T>::Direct_print(TMemo *Memo1, Node<T>* ptr)
{
	if(ptr)
	{
		Memo1->Lines->Add((ptr->data).c_str());
		Direct_print(Memo1, ptr->left);
		Direct_print(Memo1, ptr->right);
	}
}

template <typename T>
void Tree<T>::Backward_print(TMemo *Memo1)
{
	Backward_print(Memo1, root);
}

template <typename T>
void Tree<T>::Backward_print(TMemo *Memo1, Node<T>* ptr)
{
	if(ptr)
	{
		Backward_print(Memo1, ptr->left);
		Backward_print(Memo1, ptr->right);
		Memo1->Lines->Add((ptr->data).c_str());
	}
}

template <typename T>
void Tree<T>::Key_print(TMemo *Memo1)
{
	Key_print(Memo1, root);
}

template <typename T>
void Tree<T>::Key_print(TMemo *Memo1, Node<T>* ptr)
{
	if(ptr)
	{
		Key_print(Memo1, ptr->left);
		Memo1->Lines->Add((ptr->data).c_str());
		Key_print(Memo1, ptr->right);
	}
}
