#include<iostrem>
using namespace std;
#define MAX 10000

class Heap{
    public:
    int size;
    int buffer[MAX + 1]; // heap buffer
    
    Heap(){}
    Heap( int s, int array[] ){
	size = s;
	buffer = array;
    }

    void construct(){
	for ( int i = size / 2; i >= 1; i-- ) downheap( i );
    }
    
    int extractMin(){
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
        while ( k > 1 && buffer[k/2] >= v ){
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
            if ( j < size && buffer[j] > buffer[j+1] ) j++;
            if ( v <= buffer[j] ) break;
            buffer[k] = buffer[j];
            k = j;
        }
        buffer[k] = v;
    }
};

int main(void){
    Heap heap;
    int size;
    int data[MAX + 1];
    
    cin >> size;
    for ( int i = 1; i <= size; i++ ) cin >> data[i];
    
    heap = Heap( size, data );
    heap.construct();
    
    for ( int i = 1; i <= size; i++ ){
	cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}