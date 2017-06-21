#include<iostream>
#include<string>
#include<cassert>
using namespace std;
char com;
string tree1, tree2;
int p1, p2;

void parse( string &tree, int &p, bool printable ){
    for ( int i = 0; i < 2; i++ ){
	if ( tree[p] == '(' ) {
	    if ( printable ) cout << '(';
	    p++; parse(tree, p, printable); p++;
	    if ( printable ) cout << ')';
	} else {
	    p++;
	}
	if ( i == 0 && printable ) cout << ',';
    }
}

void parseI(){
    for ( int i = 0; i < 2; i++ ){
	if ( tree1[p1] == '(' && tree2[p2] == '(' ){
	    cout << '('; p1++; p2++;
	    parseI(); 
	    p1++; p2++; cout << ')';
	} else if ( tree1[p1] == '(' ){
	    p1++; parse( tree1, p1, false ); p1++;
	    p2++;
	} else if ( tree2[p2] == '(' ){
	    p2++; parse( tree2, p2, false ); p2++;
	    p1++;
	} else {
	    p1++; p2++;
	}
	if ( i == 0 ) cout << ',';
    }
}

void parseU(){
    for ( int i = 0; i < 2; i++ ){
	if ( tree1[p1] == '(' && tree2[p2] == '(' ){
	    cout << '('; p1++; p2++;
	    parseU();
	    p1++; p2++; cout << ')';
	} else if ( tree1[p1] == '(' ){
	    cout << "(";
	    p1++; parse( tree1, p1, true ); p1++;
	    p2++;
	    cout << ")";
	} else if ( tree2[p2] == '(' ){
	    cout << "(";
	    p2++; parse( tree2, p2, true ); p2++;
	    p1++;
	    cout << ")";
	} else {
	    p1++; p2++;
	}
	if ( i == 0 ) cout << ',';
    }
}

int main(){
    while( cin >> com ){
	cin >> tree1 >> tree2;
	p1 = p2 = 1;
	if ( com == 'i' ){ cout << '(' ; parseI(); cout << ')' << endl;}
	else { cout << '(' ; parseU(); cout << ')' << endl;}
    }
    return 0;
}

