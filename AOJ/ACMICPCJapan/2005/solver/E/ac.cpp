#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
#define MAX 6
#define NMAX 512
#define NON -1

struct Node{
    int left, right;
    double weight;
};

class Tree{
    public:
    Node buffer[NMAX];
    int size;
    vector<int> leaves;
    vector<int> nodes;

    Tree(){
	for ( int i = 0; i < NMAX; i++ ){
	    buffer[i].left = buffer[i].right = NON;
	    buffer[i].weight = 0.0;
	}
    }

    double maxx, minx;

    double getWidth(){
	maxx = minx = 0.0;
	parse(0, 0.0);
	return maxx - minx;
    }

    void parse(int u, double x){
	maxx = max( maxx, x );
	minx = min( minx, x );
	double n, m;
	int left = buffer[u].left;
	int right = buffer[u].right;
	if ( left == NON ) return;
	n = buffer[left].weight;
	m = buffer[right].weight;
	// to left
	parse(left, x - m/(n+m));
	// to right
	parse(right, x + n/(n+m));
    }

    double getWidthTMP(){
	double sum = 0.0;
	double n, m;
	int parent = 0;

	// to left
	while(1){
	    if ( buffer[parent].left == NON ) break;
	    n = buffer[buffer[parent].left].weight;
	    m = buffer[buffer[parent].right].weight;
	    sum += m/(n+m);
	    parent = buffer[parent].left;
	}
	assert( isLeaf(parent) );
	// to right
	parent = 0;
	while(1){
	    if ( buffer[parent].right == NON ) break;
	    n = buffer[buffer[parent].left].weight;
	    m = buffer[buffer[parent].right].weight;
	    sum += n/(n+m);
	    parent = buffer[parent].right;
	}
	assert( isLeaf(parent) );
	//cout << sum << endl;
	return sum;
    }

    bool isLeaf(int u){
	for ( int i = 0; i < leaves.size(); i++ ) if ( leaves[i] == u ) return true;
	return false;
    }

    double getWeight(int u){
	//if ( u == NON ) return buffer[u].weight;
	//	return getWeight(buffer[u].left) + getWeight(buffer[u].right);
	double l, r;
	if ( buffer[u].left == NON ) {
	    assert( buffer[u].right == NON);
	    return buffer[u].weight;
	}
	buffer[u].weight = getWeight(buffer[u].left) + getWeight(buffer[u].right);
	return buffer[u].weight;
    }

    void print(){
	cout << "tree-------------" << endl;
	for ( int i = 0; i < size; i++ ){
	    if ( buffer[i].left == NON ) {
		cout << i << "(" << buffer[i].weight << ") " << ":" << endl;
	    } else {
		cout << i << "(" << buffer[i].weight << ") " << ": " << buffer[i].left  << "-" << buffer[i].right << endl;
	    }
	}
    }
};

double R;
int stones[MAX];
int nstone;

double maxv;

int ntree;
double wsum;

void check(Tree u){
    sort( stones, stones + nstone );
    do {
	for ( int i = 0; i < nstone; i++ ) u.buffer[u.leaves[i]].weight = (double)stones[i];
	assert( wsum == u.getWeight(0));
	u.buffer[0].weight = u.getWeight(0);
	double width = u.getWidth();
	//	u.print();
	//	cout << "width = " << width << endl;
	if ( width < R ) maxv = max( maxv, width );
    } while ( next_permutation( stones, stones + nstone )) ;
}

void makeTree(Tree u){
    if ( u.leaves.size() == nstone && u.nodes.size() == 0 ){
	check(u);
    }

    if ( u.leaves.size() + u.nodes.size()*2 > nstone ) return;

    Tree v;

    for ( int i = 0; i < u.nodes.size(); i++ ){
	int parent = u.nodes[i];

	// leaf - leaf
	v = u;
	v.buffer[parent].left = v.size++;
	v.buffer[parent].right = v.size++;
	v.leaves.push_back(v.size-2);
	v.leaves.push_back(v.size-1);
	v.nodes.erase( v.nodes.begin() + i );
	makeTree(v);

	// leaf - node
	v = u;
	v.buffer[parent].left = v.size++;
	v.buffer[parent].right = v.size++;
	v.leaves.push_back(v.size-2);
	v.nodes.push_back(v.size-1);
	v.nodes.erase( v.nodes.begin() + i );
	makeTree(v);

	// node - leaf
	v = u;
	v.buffer[parent].left = v.size++;
	v.buffer[parent].right = v.size++;
	v.nodes.push_back(v.size-2);
	v.leaves.push_back(v.size-1);
	v.nodes.erase( v.nodes.begin() + i );
	makeTree(v);


	// node - node
	v = u;
	v.buffer[parent].left = v.size++;
	v.buffer[parent].right = v.size++;
	v.nodes.push_back(v.size-2);
	v.nodes.push_back(v.size-1);
	v.nodes.erase( v.nodes.begin() + i );
	makeTree(v);
    }
}

void compute(){
    if ( nstone == 1 ) {
	printf("%.16lf\n", 0);
	return;
    }

    Tree root = Tree();
    root.nodes.push_back(0);
    root.size = 1;
    ntree = 0;
    maxv = -1;
    makeTree(root);
    if ( maxv < 0.0 ) cout << "-1" << endl;
    else printf("%.16lf\n", maxv);
}

void input(){
    cin >> R >> nstone;
    wsum = 0;
    for ( int i = 0; i < nstone; i++ ) cin >> stones[i];
    for ( int i = 0; i < nstone; i++ ) wsum += stones[i];
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}