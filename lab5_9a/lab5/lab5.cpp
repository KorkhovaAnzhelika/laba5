// lab5.cpp : Defines the entry point for the application.
//

#include "lab5.h"
#include "queue.cpp"

using namespace std;

int main()
{	
	Queue q = Queue(3);
	cout << "Peek: " << q.Peek() << endl;

	cout << "Pop: " << q.Pop() << endl;
	cout << "Pop: " << q.Pop() << endl;
	cout << "Pop: " << q.Pop() << endl << endl;

	cout << "Push 10, 11, 12: " << endl << endl;
	q.Push(10); q.Push(11); q.Push(12);

	//cout << "Peek: " << q.Peek() << endl;

	cout << "Peek: " << q.Peek() << endl;
	cout << "Peek: " << q.Peek() << endl;
	cout << "Peek: " << q.Peek() << endl;

	Queue q2 = Queue(q);

	cout << "Pop: " << q2.Pop() << endl;
	cout << "Pop: " << q2.Pop() << endl;
	cout << "Pop: " << q2.Pop() << endl;
	system("pause");
	return 0;
}
