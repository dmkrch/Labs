//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>

template <typename T>
class Node
{
public:
	Node* pNext;
	T data;

	Node(T data = T(), Node* pNext = NULL)
	{
		this->data = data;
		this->pNext = pNext;
	}
};


template<typename T>
class Stack
{
	public:
		Stack();
		~Stack();

		void Clear();
		void Pop();
		void Push(T data);
		int Get_Size() { return Size; }
		T& operator[](const int index);
		void Remove_At(int index);


	private:
		void pop_front();
		int Size;
		Node<T> *head;
};



template <typename T>
Stack<T>::Stack()
{
	Size = 0;
	head = NULL;
}


template <typename T>
Stack<T>::~Stack()
{

}


template<typename T>
void Stack<T>::Clear()
{
	while (Size)
	{
		Pop();
	}
}


template<typename T>
void Stack<T>::Pop()
{
	Remove_At(Size - 1);
}


template<typename T>
void Stack<T>::Push(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current ->pNext != NULL)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
	}

	++Size;
}


template<typename T>
T& Stack<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;
	while (current != NULL)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}

template<typename T>
void Stack<T>::Remove_At(int index)
{
	if (index == 0)
	{
		pop_front();
	}

	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}
}

template<typename T>
void Stack<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;

	delete temp;

	Size--;
}
