#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
#define MAX 2000
using namespace std;

class Node{
    public:
    int v, id, prev;
    Node(){}
    Node( int v, int id, int prev ): v(v), id(id), prev(prev){}

    bool operator < ( const Node &node ) const{
	return v < node.v;
    }
};

int size;
int V[MAX];
Node M[MAX];
vector<Node> T;


void lis(){
    T.clear();
    Node newNode;
    T.push_back( Node(V[0], 0, -1) );
    M[0] = Node( V[0], 0, -1 );

    for ( int i = 1; i < size; i++ ){
	if ( T.back().v < V[i] ){
	    newNode = Node( V[i], i, T.back().id);
	    T.push_back( newNode );
	    M[i] = newNode;
	} else {
	    int target = distance( T.begin(),lower_bound( T.begin(), T.end(), Node(V[i], 0, 0) ));
	    if ( T[target].v == V[i] ) continue;
	    newNode = Node( V[i], i, T[target-1].id );
	    T[target] = newNode;
	    M[i] = newNode;
	}
    }
}

void print(){
    /*
    for ( int i = 0; i < size; i++ )
	printf("%3d", M[i].v);
    cout << endl;
    for ( int i = 0; i < size; i++ )
	printf("%3d", M[i].prev);
    cout << endl;
    */

    cout << T.size() << endl;
    cout << "-" << endl;
    vector<int> path;
    for ( int i = T.back().id; i != -1; i= M[i].prev )
	path.push_back( M[i].v );

    for ( int i = path.size() - 1; i >= 0; i-- )
	cout << path[i] << endl;

	    
}

main(){
    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> V[i];
    lis();
    print();
}
