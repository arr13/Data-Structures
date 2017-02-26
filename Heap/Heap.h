#ifndef HEAP_H
#define HEAP_H

class Heap
{
public:
	Heap();
	Heap(int size);
	Heap(const int* arr, int size);

	void setSize(int size);
	int getSize();

	int parent(int n);
	int leftChild(int n);
	int rightChild(int n);

	void createHeap();
	void createHeap1();
	void heapify(int element);
	void moveUp(int element);

	void print();

	~Heap();

private:
	int size;
	int* arr;
};

#endif