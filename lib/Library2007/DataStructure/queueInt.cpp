#include<iostream>
#include<string>
using namespace std;

#define MAX 3

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

    bool isFull(){
	return ( head == (tail + 1)%MAX );
    }

    void enqueue( int x ){
	if ( isFull() ){
	    cout << "overflow" << endl;
	    return;
	} else {
	    buffer[tail] = x;
	    if ( tail + 1 == MAX ) tail = 0; // zŠÂ
	    else tail++;
	}
    }

    int dequeue(){
	if ( isEmpty() ){
	    cout << "underflow" << endl;
	} else {
	    int x = buffer[head];
	    if ( head + 1 == MAX ) head = 0; // zŠÂ
	    else head++;
	    return x;
	}
    }
};

int main(void){
    Queue queue;
    int x;
    string command;

    while (1){
	cin >> command;
	if ( command == "enqueue" ) {
	    cin >> x;
	    queue.enqueue(x);
	} else if ( command == "dequeue" ){
	    cout << queue.dequeue() << endl;
	} else break;
    }

    return 0;
}
