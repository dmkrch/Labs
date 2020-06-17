#ifndef ListH
#define ListH

#endif

#include <iostream>
#include <stddef.h>



template <typename T> class Node      // nodes for 2-linked list
{
	public:
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
				this->data = data;
				this->pNext = pNext;
				this->pPrev = pPrev;
		}

		T data;
		Node* pNext;
		Node* pPrev;
};


template <typename T> class List   // class List(2-linked)
{
public:

	int GetSize() { return Size; }

	void clear();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();


	void insert(T data, int index);
	void removeAt(int index);

	T& operator [] (const int index);


	List <T>();
	~List <T>();

private:
	Node <T>* head;
	Node <T>* tail;
	int Size;
};

template <typename T> List <T>::List()
{
	head = NULL;
	tail = NULL;
	Size = 0;
}

template <typename T> List <T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template <typename T>
void List <T>::push_front(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = head;
		head = new Node <T>(data, head);
		temp->pPrev = head;
	}
	else if (Size == 1)
	{
		head = new Node <T>(data, head);
		tail->pPrev = this->head;
	}
	else
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}

template <typename T>
void List <T>::push_back(T data)
{
	if (Size > 1)
	{
		Node <T>* temp = tail;
		tail = new Node <T>(data, NULL, tail);
		temp->pNext = tail;
	}
	else if (Size == 1)
	{
		tail = new Node <T>(data, NULL, tail);
		head->pNext = this->tail;
	}
	else
	{
		head = tail = new Node <T>(data, head, tail);
	}
	Size++;
}

template <typename T>
void List <T>::pop_front()
{
	if (Size > 1)
	{
		Node <T>* temp = head;
		head = head->pNext;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = head;
		tail = head = head->pNext;
		delete temp;
	}

	Size--;
}

template <typename T>
void List <T>::pop_back()
{
	if (Size > 1)
	{
		Node <T>* temp = tail;
		tail = tail->pPrev;
		delete temp;
	}
	else if (Size == 1)
	{
		Node <T>* temp = tail;
		tail = head = tail->pPrev;
		delete temp;
	}

	Size--;
}

template <typename T>
void List <T>::insert(T data, int index)
{
	if (index == 0) push_front(data);

	else if (index == Size || index > Size) push_back(data);

	else if (index <= Size / 2)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext, previous);

		previous->pNext = newNode;
		Node<T>* next = newNode->pNext;
		next->pPrev = newNode;

		Size++;
	}

	else if (index > Size / 2)
	{
		Node<T>* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node<T>* newNode = new Node<T>(data, next, next->pPrev);

		next->pPrev = newNode;
		Node<T>* previous = newNode->pPrev;
		previous->pNext = newNode;

		Size++;
	}
}

template <typename T>
void List <T>::removeAt(int index)
{
	if (index == 0) pop_front();

	else if (index == Size || index > Size) pop_back();

	else if (index <= Size / 2)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		Node<T>* next = toDelete->pNext;
		delete toDelete;
		next->pPrev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		Node<T>* next = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next = next->pPrev;
		}

		Node<T>* toDelete = next->pPrev;
		next->pPrev = toDelete->pPrev;
		Node<T>* previous = toDelete->pPrev;
		delete toDelete;
		previous->pNext = next;

		Size--;
	}
}

template <typename T>
T& List <T>::operator[] (const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		Node <T>* current = this->head;

		while (current != NULL)
		{
			if (counter == index) return current->data;
			current = current->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		Node <T>* current = this->tail;

		while (current != NULL)
		{
			if (counter == index) return current->data;
			current = current->pPrev;
			counter--;
		}
	}
}
