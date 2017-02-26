#ifndef STACK_H
#define STACK_H

#include "DoublyLinkedListDLL.h"

template <class T>
class Stack	
{
public:
	Stack() : nodes(DoublyLinkedListDLL::DoublyLinkedList<T>()) {}
	Stack(T data) : nodes(DoublyLinkedListDLL::DoublyLinkedList<T>(data)) {}
	
	bool isEmpty() { nodes.isEmpty(); }
	int getSize() const { return nodes.getSize(); }

	void push(T data) { nodes.addLast(data); }
	void pop() { nodes.removeLast(); }
	T peak() const { return nodes.getFirst(); }
	
	void print() const { nodes.printBackwards(); }

private:
	DoublyLinkedListDLL::DoublyLinkedList<T> nodes;

};

#endif

