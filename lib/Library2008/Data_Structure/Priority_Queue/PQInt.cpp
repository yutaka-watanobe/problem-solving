#include<iostream>
#include<string>
using namespace std;
#define MAX 10000

class PriorityQueue{
    public:
    int size;
    int buffer[MAX + 1];
    
    PriorityQueue(){size = 0;}

    void insert(int x){
	size++;
	buffer[size] = x;
	upHeap(size);
    }
    
    int get(){
        int v = buffer[1];
        buffer[1] = buffer[size];
        size--;
        downHeap(1);
        return v;
    }
    
    private:

    void upHeap( int k ){
        int v;
        v = buffer[k];
        while ( k > 1 && buffer[k/2] <= v ){
            buffer[k] = buffer[k/2];
            k = k/2;
        }
        buffer[k] = v;
    }

    void downHeap( int k ){
        int j, v;
        v = buffer[k];
        while( k <= size/2 ){
            j = k + k;
            if ( j < size && buffer[j] < buffer[j+1] ) j++;
            if ( v >= buffer[j] ) break;
            buffer[k] = buffer[j];
            k = j;
        }
        buffer[k] = v;
    }
};

int main(void){
    PriorityQueue PQ = PriorityQueue();
    int x;
    string command;
 
    while(1){
	cin >> command;
	if ( command == "insert" ){
	    cin >> x;
	    PQ.insert(x);
	} else if ( command == "get" ){
	    cout << PQ.get() << endl;
	} else break;
    }

    return 0;
}
