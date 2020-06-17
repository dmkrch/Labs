//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>


template<typename T>
class List
{
	public:
		List();
		~List();

		void clear();
		void pop_front();
		void pop_back();
		void push_back(T data);
		int GetSize() { return Size; }
		T& operator[](const int index);
		void removeAt(int index);


	private:
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

		int Size;
		Node<T> *head;
};



template <typename T>
List<T>::List()
{
	Size = 0;
	head = NULL;
}


template <typename T>
List<T>::~List()
{

}


template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}


template<typename T>
void List<T>::push_back(T data)
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
T& List<T>::operator[](const int index)
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
void List<T>::removeAt(int index)
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