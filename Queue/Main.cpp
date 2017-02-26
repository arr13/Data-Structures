#include <iostream>

#include "Queue.h"

using namespace std;

int main(int argc, char* argv[])
{
	Queue<int> q = Queue<int>();

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	std::cout << q.size() << std::endl;

	//q.print();
	//std::cout << endl;
	//std::cout << q.getFront();
	//std::cout << q.getBack();
	q.dequeue();
	//std::cout << q.size();
	//std::cout << q.getBack();
	//std::cout << q.getFront();
	//std::cout << q.size();
	q.dequeue();
	q.print();
	q.dequeue();
	//std::cout << q.getBack();
	return 0;
}