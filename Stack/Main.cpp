#include <iostream>

#include "Stack.h"

int main(int argc, char* argv[])
{
	Stack<int> d = Stack<int>();
	d.push(1);
	d.push(2);
	d.push(3);
	d.push(5);

	d.print();

	std::cout << d.peak() << std::endl;
	
	d.pop();

	d.push(6);

	d.print();
	std::cout << d.getSize() << std::endl;

	return 0;
}