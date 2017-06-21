#include<iostream>
#include<string>
#include<cassert>
using namespace std;
#define MAX 201000

struct Node{ bool L[2], R[2]; };

Node Tree[MAX];
char com;
string tree1, tree2;

void parse( string &tree, int &pos, int index, int mode ){
    cout << index << endl;
    if ( tree[pos] == '(' ) { pos++; Tree[index].L[mode] = true; parse( tree, pos, index*2, mode); pos++;}
    else pos++;

    if ( tree[pos] == '(' ) { pos++; Tree[index].R[mode] = true; parse( tree, pos, index*2+1, mode); pos++;}
    else pos++;
}

void rec( int index ){
    cout << '(';
    if ( com == 'i' ){
	if ( Tree[index].L[0] && Tree[index].L[1] ) rec( index*2 );
	cout << ',';
	if ( Tree[index].R[0] && Tree[index].R[1] ) rec( index*2+1 );
    } else {
	if ( Tree[index].L[0] || Tree[index].L[1] ) rec( index*2 );
	cout << ',';
	if ( Tree[index].R[0] || Tree[index].R[1] ) rec( index*2+1 );
    }
    cout << ')';
}

int main(){
    while( cin >> com ){
	for ( int i = 0; i < MAX; i++ ) { 
	    for ( int j = 0; j < 2; j++ ) { Tree[i].L[j] = Tree[i].R[j] = false;}
	}
	cin >> tree1 >> tree2;
	int pos = 1;
	parse(tree1, pos, 1, 0);
	pos = 1;
	parse(tree2, pos, 1, 1);
	rec(1);
	cout << endl;
    }
    return 0;
}

