#include<stdio.h>
#include<iostream>
#include<map>
#include<queue>
#include<cassert>
#include<algorithm>
#define MAX 10
#define MODE_INIT 0
#define MODE_COMP 1

using namespace std;

class Book{
    public:
    int buffer[MAX], size, value;

    Book(){}
    Book( int size ):size(size){}
    
    void makeValue(){
	value = 0;
	int p = 1;
	for ( int i = 0; i < size; i++ ){
	    value += buffer[i]*p;
	    p *= 10;
	}
    }
};

int N, MID;
Book init;
map<int, bool> bufferV[10]; // goal state
map<int, int> bufferD[10];  // goal state

int bfs( Book u, int mode, int n){
    queue<Book> Q;
    map<int, bool> visited;
    map<int, int> d;

    u.makeValue();

    Q.push(u);
    visited[u.value] = true;
    d[u.value] = 0;
    
    Book v;
    int move[MAX], remain[MAX];
    int moveSize, remainSize;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();

	u.makeValue();

	if ( mode == MODE_INIT ){
	    if ( d[u.value] >= MID ) {
		bufferV[n] = visited;
		bufferD[n] = d;
		return 0;
	    }
	} else {
	    if ( bufferV[n][u.value] ) return bufferD[n][u.value] + d[u.value];
	}
 
	for ( int s = 0; s < n; s++ ){ // start
	    for ( int e = s; e < n; e++ ){ // end
		moveSize = e - s + 1;
		remainSize = n - moveSize;
		for ( int i = 0, j = s; i < moveSize; i++, j++ ) move[i] = u.buffer[j];
		for ( int i = 0, j = 0; j < n; j++ ){
		    if ( s <= j && j <= e ) continue;
		    remain[i++] = u.buffer[j];
		}
		
		for ( int in = 0; in <= remainSize; in++ ){
		    v = Book(n);

		    for ( int p = 0, t = 0; t <= remainSize; t++ ){
			if ( t == in ){
			    for ( int i = 0; i < moveSize; i++ ) v.buffer[p++] = move[i];
			}
			if ( t < remainSize ) v.buffer[p++] = remain[t];
		    }

		    v.makeValue();
		    if ( !visited[v.value] ){
			visited[v.value] = true;
			d[v.value] = d[u.value] + 1;
			Q.push(v);
		    }
		}
	    }
	}
    }

    assert(false);
}

void initialize(){
    for ( int l = 1; l <= 9; l++ ){
	Book goal = Book(l);
	for ( int i = 0; i < l; i++ ) goal.buffer[i] = i+1;
	MID = max( 0, l/2 - 1 );
	bfs(goal, MODE_INIT, l);
    }
}

int compute(){
    return bfs( init, MODE_COMP, N );
}

bool input(){
    scanf("%d", &N);
    if ( N == 0 ) return false;

    init = Book(N);
    for ( int i = 0; i < N; i++ ) scanf("%d", &init.buffer[i]);
    
    return true;
}

main(){
    initialize();
    for ( int i = 1; input(); i++ )
	printf("Case %d: %d\n", i, compute());
}

