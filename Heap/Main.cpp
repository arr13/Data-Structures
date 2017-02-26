#include <iostream>
#include <ctime>
#include "Heap.h"

using namespace std;

int main(int argc, char* argv[])
{
	const int size = 200000;
	int arr[size];
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}

	Heap heap = Heap(arr, size);
	clock_t begin = clock();
	heap.createHeap();
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << endl;
	//heap.print();

	Heap heap1 = Heap(arr, size);
	begin = clock();
	heap1.createHeap1();
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << endl;
	//heap1.print();
	return 0;
}