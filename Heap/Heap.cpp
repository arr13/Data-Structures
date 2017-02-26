#include "Heap.h"
#include <cmath>
#include <iostream>

Heap::Heap() : Heap(100)
{
}

Heap::Heap(int size)
{
	setSize(size);
	this->arr = new int[size];
}

Heap::Heap(const int* arr, int size): Heap(size)
{
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
}

void Heap::setSize(int size)
{
	if (this->size < 0)
	{
		throw ("Ooops... Try again with non-negative number for the size of the heap");
	}

	this->size = size;
}

int Heap::getSize()
{
	return this->size;
}

int Heap::parent(int n)
{
	if (n > size)
	{
		throw ("n has to be less than size");
	}

	return floor(n / 2);
}

int Heap::leftChild(int n)
{
	if (n > size)
	{
		throw ("n has to be less than size");
	}

	return 2 * n;
}

int Heap::rightChild(int n)
{
	if (n > size)
	{
		throw ("n has to be less than size");
	}

	return 2 * n + 1;
}

void Heap::createHeap()
{
	for (int i = this->parent(size) - 1; i >= 0; i--)
	{
		this->heapify(i);
	}
}

void Heap::createHeap1()
{
	for (int i = 0; i < this->size; i++)
	{
		this->moveUp(i);
	}
}

void Heap::heapify(int element)
{
	while (element < this->size && element >= 0)
	{
		int largest = element;

		if (leftChild(element + 1) <= size && this->arr[element] < this->arr[leftChild(element + 1) - 1])
		{
			largest = leftChild(element + 1) - 1;
		}
		if (rightChild(element + 1) <= size && this->arr[largest] < this->arr[rightChild(element + 1) - 1])
		{
			largest = rightChild(element + 1) - 1;
		}

		if (largest == element)
		{
			break;
		}

		int temp = this->arr[largest];
		this->arr[largest] = this->arr[element];
		this->arr[element] = temp;
		element = largest;
	}
}

void Heap::moveUp(int element)
{
	while (element < this->size && element >= 0)
	{
		int parent = this->parent(element + 1) - 1;
		if (parent < 0 || this->arr[parent] >= this->arr[element])
		{
			break;
		}

		int temp = this->arr[parent];
		this->arr[parent] = this->arr[element];
		this->arr[element] = temp;
		element = parent;
	}
}

void Heap::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}

	std::cout << std::endl;
}

Heap::~Heap()
{
	delete[] arr;
}
