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

int size, length;
int V[MAX];
Node M[MAX];
Node T[MAX];


void lis(){
    Node newNode;
    T[0] = Node(V[0], 0, -1);
    M[0] = Node(V[0], 0, -1);
    length = 1;

    for ( int i = 1; i < size; i++ ){
	if ( T[length -1].v < V[i] ){
	    newNode = Node( V[i], i, T[length-1].id);
	    T[length++] = newNode;
	    M[i] = newNode;
	} else {
	    int target = distance( T, lower_bound( T, T + length, Node(V[i], 0, 0) ));
	    if ( T[target].v == V[i] ) continue;
	    newNode = Node( V[i], i, T[target-1].id );
	    T[target] = newNode;
	    M[i] = newNode;
	}
    }
}

void print(){
    cout << length << endl;
    cout << "-" << endl;
    vector<int> path;
    for ( int i = T[length-1].id; i != -1; i= M[i].prev )
	path.push_back( M[i].v );

    for ( int i = path.size() - 1; i >= 0; i-- )
	cout << path[i] << endl;
    
}

main(){
  while(cin >> size){
    for ( int i = 0; i < size; i++ ) cin >> V[i];
    lis();
    print();
  }
}
