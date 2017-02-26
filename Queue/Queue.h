#ifndef QUEUE_H
#define QUEUE_H

#define MAX 35

template <class T>
class Queue
{
public:
	Queue() : rear(-1), front(-1) {};
	//~Queue();

	bool isEmpty();
	void enqueue(T data);
	T getFront();
	T getBack();
	void dequeue();
	int size();
	void print();

private:
	T data[MAX];
	int front;
	int rear;
};

template <class T>
bool Queue<T>::isEmpty()
{
	if (front == (-1))
	{
		return true;
	}
	
	return false;
}

template <class T>
void Queue<T>::enqueue(T data)
{
	rear = (rear + 1) % MAX;
	if (rear == front)
	{
		throw "Queue is full!";
	}
	else if (isEmpty() == true)
	{
		front = rear;
		this->data[rear] = data;
	}
	else
	{
		this->data[rear] = data;
	}
}

template <class T>
T Queue<T>::getFront()
{
	if (isEmpty() == true)
	{
		throw "Queue is empty!";
	}
	
	return data[front];
}

template <class T>
T Queue<T>::getBack()
{
	if (isEmpty() == true)
	{
		throw "Queue is empty!";
	}

	return data[rear];
}

template <class T>
void Queue<T>::dequeue()
{
	if (isEmpty() == true)
	{
		throw "Queue is empty!";
	}
	else if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % MAX;
	}
}

template <class T>
int Queue<T>::size()
{
	return (rear + MAX - front) % MAX + 1;
}

template <class T>
void Queue<T>::print()
{
	if (isEmpty() == true)
	{
		throw "Queue is empty!";
	}
	
	for (int i = front; i != rear; i = (i + 1) % MAX)
	{
		cout << data[i] << " ";
	}
	cout << data[rear];
}

#endif 
