// begin_of_source
// @author yutaka C++
#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>

using namespace std;

#define CHAR_SIZE 256
#define NODE_SIZE 512
#define TOLEFT '0'
#define TORIGHT '1'

class Node{
    public:
    int id, weight, left, right;
    Node(){ weight = 0; } 
    Node( int id, int w, int l, int r ): id(id), weight(w), left(l), right(r){}

    bool operator < ( const Node &n ) const{
	return weight > n.weight;
    }
};

Node nodes[NODE_SIZE];
int newRootId;

void recursive( int id, string code ){
    if ( id < CHAR_SIZE ){
	printf("%c  %s\n", id, code.c_str()); return;
    }
    recursive( nodes[id].left, code + TOLEFT );
    recursive( nodes[id].right, code + TORIGHT );
}

// input the string to be encoded
void encoding( string text ){
    int w[CHAR_SIZE];

    // Compute the weight of each character
    for ( int i = 0; i < CHAR_SIZE; i++ ) w[i] = 0;
    for ( int i = 0; i < text.size(); i++ ) w[text[i]]++;

    // Output w[]
    for ( int i = 0; i < CHAR_SIZE; i++ ){
	if ( w[i] ) printf("%c : %d times\n", i, w[i]);
    }

    // Construct and initialize the priority queue
    priority_queue<Node> PQ;
    for ( int i = 0; i < CHAR_SIZE; i++ ) {
	if ( w[i] > 0 ){
	    Node node = Node( i, w[i], -1, -1 );
	    PQ.push( node );
	    nodes[ node.id ] = node;
	}
    }

    // Construct the binary tree
    newRootId = CHAR_SIZE;

    while ( PQ.size() > 1 ){
	Node left = PQ.top(); PQ.pop();
	Node right = PQ.top(); PQ.pop();
	int weight = left.weight + right.weight;
	Node newRoot = Node( newRootId, weight, left.id, right.id );
	PQ.push( newRoot );
	nodes[ newRootId++ ] = newRoot;
    }

    // Output the binary tree constructed
    for ( int i = newRootId - 1; i >= CHAR_SIZE; i-- ){
	if ( nodes[i].left >= CHAR_SIZE ) 
	    printf("left  son of %4d is %4d\n", i, nodes[i].left );
	else 
	    printf("left  son of %4d is %4c\n", i, nodes[i].left );
	if ( nodes[i].right >= CHAR_SIZE ) 
	    printf("right son of %4d is %4d\n", i, nodes[i].right );
	else 
	    printf("right son of %4d is %4c\n", i, nodes[i].right );
    }
}

void decoding(){
    recursive( newRootId - 1, "");
}

main(){
    string text; cin >> text;
    encoding( text );
    decoding();
}
// end_of_source
