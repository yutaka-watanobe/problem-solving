#include<iostream>
#define MAX 100
using namespace std;
// begin_of_source
class Queue{
    private:
    int buffer[MAX];
    int head, tail;

    public:
    Queue(){
	initialize();
    }

    void initialize(){
	head = tail = 0;
    }

    bool isEmpty(){
	return ( head == tail );
    }

    void enqueue( int x ){
	buffer[tail] = x;
	if ( tail + 1 == MAX ) tail = 0; // èzä¬Ç≥ÇπÇÈ
	else tail++;
    }

    int dequeue(){
	if ( isEmpty() ){
	    cout << "empty" << endl;
	    return -1;
	} else {
	    int x = buffer[head];
	    if ( head + 1 == MAX ) head = 0; // èzä¬Ç≥ÇπÇÈ
	    else head++;
	    return x;
	}
    }
};

main(){
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(7);
    queue.enqueue(3);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    queue.enqueue(5);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
}

// end_of_source
