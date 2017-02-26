// DoublyLinkedListDLL.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "iostream"
//using namespace System;

namespace DoublyLinkedListDLL
{
	template <class T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList() : head(NULL), tail(NULL) {};
		DoublyLinkedList(T data);
		~DoublyLinkedList();

		bool isEmpty();

		int getSize() const;

		void addLast(T data);
		void addFirst(T data);

		T getFirst() const;
		T getLast() const;

		T removeFirst();
		T removeLast();

		void print() const;
		void printBackwards() const;

	private:
		template <class T>
		class Node
		{
		public:
			T data;
			Node* next;
			Node* previous;
			Node(T data, Node* next = NULL, Node* previous = NULL)
				: data(data), next(next), previous(previous) {};
		};

		Node<T>* head;
		Node<T>* tail;
	};

	template <class T>
	DoublyLinkedList<T>::DoublyLinkedList(T data)
	{
		Node* node = new Node(data);
		this->head = node;
		this->tail = node;
	}

	template <class T>
	DoublyLinkedList<T>::~DoublyLinkedList()
	{
		Node<T>* node = this->head;
		while (node != NULL)
		{
			node = node->next;
			if (node != NULL)
			{
				delete node->previous;
			}
		}

		delete node;
	}

	template <class T>
	bool DoublyLinkedList<T>::isEmpty()
	{
		if (this->head == nullptr)
		{
			return true;
		}

		return false;
	}

	template <class T>
	int DoublyLinkedList<T>::getSize() const
	{
		Node<T>* node = this->head;
		int size = 0;

		while (node != NULL)
		{
			node = node->next;
			size++;
		}

		delete node;
		return size;
	}

	template <class T>
	void DoublyLinkedList<T>::addLast(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (!isEmpty())
		{
			this->tail->next = newNode;
			newNode->previous = this->tail;
			this->tail = newNode;
		}
		else
		{
			this->head = newNode;
			this->tail = this->head;
		}
	}

	template <class T>
	void DoublyLinkedList<T>::addFirst(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (!isEmpty())
		{
			newNode->next = this->head;
			this->head->previous = newNode;
			this->head = newNode;
		}
		else
		{
			this->head = newNode;
			this->tail = newNode;
		}
	}

	template <class T>
	T DoublyLinkedList<T>::getFirst() const
	{
		if (!isEmpty())
		{
			return this->head->data;
		}

		throw "Linked list is empty!";
	}

	template <class T>
	T DoublyLinkedList<T>::getLast() const
	{
		if (this->head != nullptr)
		{
			return this->tail->data;
		}

		throw "Linked list is empty!";
	}

	template <class T>
	T DoublyLinkedList<T>::removeFirst()
	{
		if (!isEmpty())
		{
			int data = this->head->data;
			this->head = this->head->next;
			if (this->head->previous != NULL)
			{
				delete this->head->previous;
				this->head->previous = NULL;
			}

			return data;
		}

		throw "Linked list is empty!";
	}

	template <class T>
	T DoublyLinkedList<T>::removeLast()
	{
		if (!isEmpty())
		{
			int data = this->tail->data;
			this->tail = this->tail->previous;
			delete this->tail->next;
			this->tail->next = NULL;

			return data;
		}

		throw "Linked list is empty!";
	}

	template <class T>
	void DoublyLinkedList<T>::print() const
	{
		Node<T>* node = this->head;
		while (node != NULL)
		{
			std::cout << node->data << " ";
			node = node->next;
		}

		std::cout << std::endl;
	}

	template <class T>
	void DoublyLinkedList<T>::printBackwards() const
	{
		Node<T>* node = this->tail;
		while (node != NULL)
		{
			std::cout << node->data << " ";
			node = node->previous;
		}

		std::cout << std::endl;
	}
}
#endif
