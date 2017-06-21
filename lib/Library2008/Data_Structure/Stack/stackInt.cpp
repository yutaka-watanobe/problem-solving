#include<iostream>
#include<string>
using namespace std;

#define MAX 100

class Stack{
    private:
    int buffer[MAX];
    int top;

    public:
    Stack(){
	initialize();
    }

    void initialize(){
	top = 0;
    }

    bool isEmpty(){
	return ( top == 0 );
    }

    bool isFull(){
	return  ( top >= MAX );
    }

    void push( int x ){
	if ( isFull() ){
	    cout << "overflow" << endl;
	} else {
	    top++;
	    buffer[top] = x;
	}
    }

    int pop(){
	if ( isEmpty() ) {
	    cout << "underflow" << endl;
	} else {
	    int x = buffer[top];
	    top--;
	    return x;
	}
    }
};

int main(void){
    Stack stack;
    int x;
    string command;

    while (1){
	cin >> command;
	if ( command == "push" ) {
	    cin >> x;
	    stack.push(x);
	} else if ( command == "pop" ){
	    cout << stack.pop() << endl;
	} else break;
    }

    return 0;
}

