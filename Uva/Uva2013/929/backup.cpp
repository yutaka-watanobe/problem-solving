#include<stdio.h>
#include<iostream>
#include<climits>
#include<queue>
using namespace std;
#define MAX 999
#define SIZE 1000000
#define INFTY INT_MAX

class Node{
    public:
    int id, cost;
    Node(){}
    Node( int id, int cost):id(id), cost(cost){}
};

class PriorityQueue{
    public:
    int size;
    Node *H;//[SIZE];

    PriorityQueue( int limit){ 
	size = 0;
	H = (Node *)malloc(limit*sizeof(Node *));
    }
    
    void insert( Node node ){
	H[++size] = node;
	upheap(size);
    }

    int extractMin(){
        Node v = H[1];
        H[1] = H[size];
        size--;
        downheap(1);
        return v.id;
    }
    
    private:
    void downheap( int k ){
        int j;
	Node v;
        v = H[k];
        while( k <= size/2 ){
            j = k + k;
            if ( j < size && H[j].cost > H[j+1].cost ) j++;
            if ( v.cost <= H[j].cost ) break;
            H[k] = H[j];
            k = j;
        }
        H[k] = v;
    }

    void upheap( int k ){
        Node v;
        v = H[k];
        while ( k > 1 && H[k/2].cost >= v.cost ){
            H[k] = H[k/2];
            k = k/2;
        }
        H[k] = v;
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

    d[0] = G[0][0];

    PriorityQueue heap = PriorityQueue(N*M);
    heap.insert(Node( 0, G[0][0] ));

    int di[4] = {0, -1, 0, 1};
    int dj[4] = {1, 0, -1, 0};

    int i, j, ni, nj, next;
    int u, v;

    while( heap.size >= 1 ){
	u = heap.extractMin();

	//		if ( visited[u] ) continue;
	visited[u] = true;

	i = u/M;
	j = u%M;

	for ( int r = 0; r < 4; r++ ){
	    ni = i + di[r];
	    nj = j + dj[r];
	    if ( ni < 0 || nj < 0 || ni >= N || nj >= M ) continue;
	    v = ni*M+nj;

	    if ( !visited[v] && d[v] > d[u] + G[ni][nj] ){
		//visited[v] = true;
		d[v] = d[u] + G[ni][nj];
		heap.insert(Node(v, d[v]));
	    }
	}
    }

    free(heap.H);
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
