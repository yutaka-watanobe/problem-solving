#include<stdio.h>
#include<iostream>
#include<map>
#include<queue>
#include<cassert>
#define MAX 10

using namespace std;

class Book{
    public:
    int buffer[MAX+2];
    int size;

    Book(){}
    Book( int size ):size(size){}

    void print(){
	for ( int i = 1; i <= size; i++ ) printf("%2d", buffer[i]);
	printf("\n");
    }
    
    bool checkOrder(){
	for ( int i = 1; i <= size; i++ ){
	    if ( i != buffer[i] ) return false;
	}
	return true;
    }

    bool operator < ( const Book &b ) const{
	for ( int i = 1; i <= size; i++ ){
	    if ( buffer[i] != b.buffer[i] ) 
		return buffer[i] < b.buffer[i];
	}
	return false;
    }
};

int n;
Book init;

int bfs( Book u ){
    queue<Book> Q;
    map<Book, bool> visited;
    map<Book, int> d;

    Q.push(u);
    visited[u] = true;
    d[u] = 0;
    
    Book v;
    int tmp1[MAX+2], tmp2[MAX+2];
    int size1, size2;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();

	if ( u.checkOrder() ) return d[u];
	//		u.print();

	for ( int s = 1; s <= n; s++ ){
	    int end = s;

	    while( end + 1 <= n && u.buffer[end] == u.buffer[end + 1] - 1  ) end++;

	    size2 = end - s + 1;
	    size1 = n - size2;
	    
	    for ( int i = 0, j = s; i < size2; i++, j++ ) tmp2[i] = u.buffer[j];

	    tmp1[0] = 0;
	    for ( int i = 1, j = 1; i <= n; i++ ){
		if ( s <= i && i <= end ) continue;
		tmp1[j++] = u.buffer[i];
	    }
	    tmp1[size1+1] = n + 1;


	    for ( int in = 1; in <= size1 + 1; in++ ){
		int pos = 1;
		v = Book(n);

		if ( !( tmp1[in-1]+1 == tmp2[0] || tmp1[in] == tmp2[size2-1]+1 ) ) continue;

		for ( int t = 1; t <= size1 + 1; t++ ){
		    if ( t == in ){
			for ( int i = 0; i < size2; i++ ) v.buffer[pos++] = tmp2[i];
		    }
		    if ( t < size1 + 1 ) v.buffer[pos++] = tmp1[t];
		}
		assert( pos == n + 1);

		if ( !visited[v] ){
		    visited[v] = true;
		    d[v] = d[u] + 1;
		    Q.push(v);
		}
	    }
	}
    }

    assert(false);
}

int compute(){
    return bfs( init );
}

bool input(){
    scanf("%d", &n);
    if ( n == 0 ) return false;

    init = Book(n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &init.buffer[i]);
    
    return true;
}

main(){
    for ( int i = 1; input(); i++ )
	printf("Case %d: %d\n", i, compute());
}

