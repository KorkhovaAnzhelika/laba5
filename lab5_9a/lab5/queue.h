#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:

	Queue(int count);
	~Queue();
	Queue(const Queue& other);
	Queue(Queue&& other);
	Queue &operator= (const Queue& other);
	int GetSize() const;
	void Push(int element);
	int Pop() const;
	int Peek();
private:
	int count;
	
};
#endif
