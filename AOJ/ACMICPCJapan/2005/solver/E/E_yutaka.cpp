#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 6
#define NON -1
#define ROOT 0
#define TO_LEAF 0
#define TO_NODE 1

struct Node{
    int left, right;
    double weight;
};

class Tree{
    public:
    Node nodes[MAX*2];
    int size;
    vector<int> leaves, internals;

    Tree(){
	for ( int i = 0; i < MAX*2; i++ ){
	    nodes[i].left = nodes[i].right = NON;
	    nodes[i].weight = 0.0;
	}
    }

    double getWidth(){
	double maxx, minx;
	maxx = minx = 0.0;
	parse(0, 0.0, maxx, minx);
	return maxx - minx;
    }

    void parse(int u, double x, double &maxx, double &minx){
	maxx = max( maxx, x );
	minx = min( minx, x );
	double n, m;
	int left = nodes[u].left;
	int right = nodes[u].right;
	if ( left == NON ) return;
	n = nodes[left].weight;
	m = nodes[right].weight;
	parse(left, x - m/(n+m), maxx, minx);
	parse(right, x + n/(n+m), maxx, minx);
    }

    double getWeight(int u){
	if ( nodes[u].left == NON ) return nodes[u].weight;
	nodes[u].weight = getWeight(nodes[u].left) + getWeight(nodes[u].right);
	return nodes[u].weight;
    }
};

double R;
int stones[MAX];
int nstone;

double maxv;

void check(Tree u){
    sort( stones, stones + nstone );
    do {
	for ( int i = 0; i < nstone; i++ ){
	    u.nodes[u.leaves[i]].weight = stones[i];
	}
	u.getWeight(ROOT);
	double width = u.getWidth();
	if ( width < R ) maxv = max( maxv, width );
    } while ( next_permutation( stones, stones + nstone )) ;
}

void makeTree(Tree u){
    if ( u.leaves.size() == nstone && u.internals.size() == 0 ) check(u);
    if ( u.leaves.size() + u.internals.size()*2 > nstone ) return;

    Tree v;

    for ( int i = 0; i < u.internals.size(); i++ ){
	int parent = u.internals[i];
	for ( int a = 0; a < 2; a++ ){
	    for ( int b = 0; b < 2; b++ ){
		v = u;
		v.nodes[parent].left = v.size++;
		v.nodes[parent].right = v.size++;
		if ( a == TO_LEAF ) v.leaves.push_back(v.size-2);
		else v.internals.push_back(v.size-2);
		if ( b == TO_LEAF ) v.leaves.push_back(v.size-1);
		else v.internals.push_back(v.size-1);
		v.internals.erase( v.internals.begin() + i );
		makeTree(v);
	    }
	}
    }
}

void compute(){
    if ( nstone == 1 ) {
	printf("%.9lf\n", 0.0); return;
    }
    Tree root = Tree();
    root.internals.push_back(ROOT);
    root.size = 1;
    maxv = -1;
    makeTree(root);
    if ( maxv < 0.0 ) cout << "-1" << endl;
    else printf("%.9lf\n", maxv);
}

void input(){
    cin >> R >> nstone;
    for ( int i = 0; i < nstone; i++ ) cin >> stones[i];
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}