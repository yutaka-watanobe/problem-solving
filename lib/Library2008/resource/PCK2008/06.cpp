#include<iostream>
using namespace std;
#define MAX 5000

class Tetoris{
    public:
    int stack[MAX+1], top;
    Tetoris(){ stack[0] = 31; top = 0; }

    void insert( int o, int p, int q ){
	int value = (o == 1 ? (((2 << p-1)-1) << (q-1)) : (1 << (q-1))); 
	int target = getTarget( value );
	for ( int i = target;  i < target + ((o == 2) ? p : 1); i++ ){
	    if ( i > top ){
		stack[i] = value;
		top = i;
	    } else {
		stack[i] += value;
	    }
	}
	
	while( erase());
    } 

    bool erase(){
	for ( int i = 1; i <= top; i++ ){
	    if ( stack[i] == 31 ){
		for ( int j = i+1; j <= top; j++ ) stack[j-1] = stack[j];
		top--; return true;
	    }
	}
	return false;
    }

    int getResult(){
	int sum = 0;
	for ( int i = top; i >= 1; i-- ){
	    int val = stack[i];
	    while( val ){
		if ( val%2 ) sum++;
		val /= 2;
	    }
	}
	return sum;
    }

    int getTarget( int value ){
	int target = top;
	while( (stack[target] & value) == 0 ) target--;
	return target + 1;
    }
};

int main(){
    int n, o, p, q;
    while( cin >> n && n ){
	Tetoris tetoris;
	for ( int i = 0; i < n; i++ ) {
	    cin >> o >> p >> q;
	    tetoris.insert(o, p, q);
	}
	cout << tetoris.getResult() << endl;
    }
    return 0;
}
