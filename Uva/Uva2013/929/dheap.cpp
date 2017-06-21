#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
#define MAX 999
#define SIZE 1000000
#define INFTY (1<<21)

class Heap{
    public:
    int size;
    int *H; // heap buffer
    int *index; // index of v in the heap buffer
    int *key; // keys for heap condition
    
    Heap(){}
    Heap( int size, int d[] ): size(size){
        key = d;
	H = (int *)malloc(size*sizeof(int *));
	index = (int *)malloc((size+1)*sizeof(int *));
    }
    
    void construct(){
        for ( int i = 0; i < size; i++ ){
            H[i + 1] = i; // heap is 1 base not 0
            index[i] = i + 1;
        }
        for ( int i = size / 2; i >= 1; i-- ) downheap( i );
    }
    
    int extractMin(){
        int v = H[1];
        H[1] = H[size];
        index[ H[size] ] = 1;
        size--;
        downheap(1);
        return v;
    }
    
    int update( int v ){
        upheap( index[v] );
    }
    
    private:
    void downheap( int k ){
        int j, v;
        v = H[k];
        while( k <= size/2 ){
            j = k + k;
            if ( j < size && key[ H[j] ] > key[ H[j+1] ] ) j++;
            if ( key[v] <= key[ H[j] ] ) break;
            H[k] = H[j];
            index[ H[j] ] = k;
            k = j;
        }
        H[k] = v;
        index[ v ] = k;
    }
    
    void upheap( int k){
        int v;
        v = H[k];
        while ( k > 1 && key[ H[k/2] ] >= key[v] ){
            H[k] = H[k/2];
            index[ H[k/2] ] = k;
            k = k/2;
        }
        H[k] = v;
        index[v] = k;
    }
};

int G[MAX+2][MAX+2];
int N, M;

int dijkstra(){
    bool visited[SIZE];
    int d[SIZE];

    for ( int i = 0; i < M*N; i++ ){
	visited[i] = false;
	d[i] = INFTY;
    }

    d[0] = 0;

    Heap heap = Heap( N*M, d );
    heap.construct();

    int di[4] = {0, -1, 0, 1};
    int dj[4] = {1, 0, -1, 0};

    int i, j, ni, nj, next;
    int u, v;

    while( heap.size >= 1 ){
	cout << heap.size << endl;
	u = heap.extractMin();
	
	visited[u] = true;

	i = u/M;
	j = u%M;

	for ( int r = 0; r < 4; r++ ){
	    ni = i + di[r];
	    nj = j + dj[r];
	    if ( ni < 0 || nj < 0 || ni >= N || nj >= M ) continue;
	    v = ni*M+nj;

	    if ( !visited[v] && d[v] > d[u] + G[ni][nj] ){
		visited[v] = true;
		d[v] = d[u] + G[ni][nj];
		heap.update(v);
	    }
	}
    }

    return d[N*M-1];
}

void input(){
    scanf("%d %d", &N, &M);
    for ( int i = 0; i < N; i++ ){
	for ( int j = 0; j < M; j++ ){
	    scanf("%d", &G[i][j]);
	}
    }
}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	input();
	printf("%d\n", dijkstra());
    }
}
