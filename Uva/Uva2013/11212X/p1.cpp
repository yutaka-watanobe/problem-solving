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
    int buffer[MAX];
    int size;

    Book(){}
    Book( int size ):size(size){}

    void print(){
	for ( int i = 0; i < size; i++ ) printf("%2d", buffer[i]);
	printf("\n");
    }
    
    bool operator < ( const Book &b ) const{
	for ( int i = 0; i < size; i++ )
	    if ( buffer[i] != b.buffer[i] ) 
		return buffer[i] < b.buffer[i];
	return false;
    }
};

int N;
Book init;
map<Book, bool> visitedG;
map<Book, int> dG;

map<Book, bool> bufferV[10];
map<Book, int> bufferD[10];

int MID;

int bfs( Book u, int mode, int level, int n ){
    queue<Book> Q;
    map<Book, bool> visited;
    map<Book, int> d;

    Q.push(u);
    visited[u] = true;
    d[u] = 0;
    
    Book v;
    int move[MAX], remain[MAX];
    int moveSize, remainSize;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();

	if ( mode == MODE_INIT ){
	    if ( d[u] >= MID ) {
		bufferV[level] = visited;
		bufferD[level] = d;
		return -1;
	    }
	} else {
	    //	    u.print();
	    if ( visitedG[u] ) return dG[u] + d[u];
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

		    if ( !visited[v] ){
			visited[v] = true;
			d[v] = d[u] + 1;
			Q.push(v);
		    }
		}
	    }
	}
    }

    assert(false);
}

void initM(){

    for ( int l = 1; l <= 9; l++ ){
	Book goal = Book(l);
	for ( int i = 0; i < l; i++ ) goal.buffer[i] = i+1;
	MID = max( 0, l/2  );
	bfs(goal, MODE_INIT, l, l);
    }
}

int compute(){
    visitedG = bufferV[N];
    dG = bufferD[N];
    return bfs( init, MODE_COMP, -1, N );
}

bool input(){
    scanf("%d", &N);
    if ( N == 0 ) return false;

    init = Book(N);
    for ( int i = 0; i < N; i++ ) scanf("%d", &init.buffer[i]);
    
    return true;
}

main(){
    initM();
    for ( int i = 1; input(); i++ )
	printf("Case %d: %d\n", i, compute());
}

