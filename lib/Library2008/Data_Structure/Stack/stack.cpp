#include<iostream>
#define MAX 100
using namespace std;
//begin_of_source
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

    void push( int x ){
	if ( top + 1 >= MAX ){
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
	    top--;
	    return buffer[top+1];
	}
    }
};

main(){
    Stack stack;
    stack.push(1);
    stack.push(7);
    stack.push(3);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    stack.push(5);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
}

//end_of_source
