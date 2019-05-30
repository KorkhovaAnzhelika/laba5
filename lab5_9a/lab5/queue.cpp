#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include "queue.h"

using namespace std;

/*
* Node Declaration
*/
struct node
{
	int name;
	struct node* next;
};

node* tail, * head;

void createList(int count);
void addNode(int element);
void removeNode(int value);

Queue::Queue(int count)
{
	createList(count);
}

Queue::Queue(const Queue& other)
{
	count = other.count;
	createList(0);
	for (int i = 0; i < count; i++) {
		Push(other.Pop());
	}
}

Queue::~Queue()
{
	while (GetSize() > 0) {
		Pop();
	}
	delete tail;
	delete head;
}


void Queue::Push(int element)
{
	addNode(element);
}

int Queue::Peek()
{
	if (head == NULL) {
		return 0;
	}

	node* n = head;

	do {
		n = n->next;
	} while (n != head);
	return n->name;
}

int Queue::Pop() const
{
	if (head == NULL) {
		return 0;
	}

	node* n = head;

	do {
		n = n->next;
	} while (n != head);
	int value = n->name;
	removeNode(value);
	return value;
}

void addNode(int sname)
{
	node* n = new node;
	n->name = sname;

	if (head == NULL) {
		head = n;
		tail = n;
	}
	else {
		tail->next = n;    // connects the nodes
		tail = tail->next; // moves the connecter to the t= last
	}
	tail->next = head;
}


/*
* Deletion of element from the list
*/
void removeNode(int value)
{
	// no elements
	if (head == NULL) {
		return;
	}

	node* n = head;
	node* prev = tail;

	// 1 element
	if (n == prev) {
		if (n->name == value) {
			delete n;
			head = tail = NULL;
		}
		return;
	}

	bool found = false;
	// search
	do {
		if (n->name == value) {
			found = true;
			break;
		}
		prev = n;
		n = n->next;
	} while (n != head);

	// no such element
	if (!found) {
		return;
	}

	prev->next = n->next;
	if (n == head) {
		head = n->next;
	}
	else if (n == tail) {
		tail = prev;
	}
	delete n;
}

int Queue::GetSize() const
{
	int count = 0;
	if (head == NULL) {
		return 0;
	}

	node* n = head;

	do {
		n = n->next;
		++count;
	} while (n != head);
	return count;
}

void displayList()
{
	if (head == NULL) {
		cout << "empty!" << endl;
		return;
	}

	node* n = head;

	do {
		cout << n->name << "\n";
		n = n->next;
	} while (n != head);
	cout << endl;
}

void createList(const int count)
{
	for (int i = 0; i < count; ++i) {
		addNode(i);
	}
}
