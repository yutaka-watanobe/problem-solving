#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#define MAX 10000

static const int INFTY = 100000000;

int buffer[MAX], size, stack[MAX], top;

bool parseDown( int target, int &pos, int &width ){
    width = 0;
    pos = top;
    while(1){
	if ( stack[pos] == target ) return true;
	if ( stack[pos] < 0 ) return false;
	width += stack[pos];
	pos--;
    }
}

bool check(){
    top = 0;
    stack[top] = INFTY*(-1);

    for ( int i = 0 ; i < size; i++ ){
	int cur = buffer[i];
	if ( cur < 0 ){
	    if ( stack[top] < 0 && stack[top] > cur ) return false;
	    stack[++top] = cur;
	} else {
	    int pos, width;
	    if ( !parseDown(cur*(-1), pos, width) ) return false;
	    if ( cur <= width ) return false;
	    top = pos;
	    stack[top] = cur;
	}
    }

    return (top == 0 && stack[top] == INFTY );
}

int main(){
    string line;
    while(1){
	getline( cin, line );
	if ( cin.eof() ) break;
	if ( line.size() == 0 ) continue;
	stringstream sin(line);
	int v;
	size = 0;
	while( sin >> v ){
	    buffer[size++] = v;
	}
	buffer[size++] = INFTY;
	if ( check() ) cout << ":-) Matrioshka!" << endl;
	else cout << ":-( Try again." << endl;
    }

    return 0;
}
