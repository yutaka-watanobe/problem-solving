#include<iostream>
#include<string>
#define MAX 50
using namespace std;
string word1, word2, word3, word4;

void search( int &top, int &left, string str1, string str2 ){
    for ( int i = 0; i < str1.size(); i++ ){
	for ( int j = 0; j < str2.size(); j++ ){
	    if ( str1[i] == str2[j] ){
		top = j; left = i; return;
	    }
	}
    }
    top = -1;
}

void print(){
    int t1, t2, l1, l2, b1, b2, W, H;
    search(t1, l1, word1, word2);
    search(t2, l2, word3, word4);
    if ( t1 == -1 || t2 == -1 ) {
	cout << "Unable to make two crosses" << endl; return;
    }
    int row = max( t1, t2 );

    b1 = word2.size() - t1 - 1;
    b2 = word4.size() - t2 - 1;

    H = max( row+b1, row+b2 ) + 1;
    W = word1.size() + word3.size() + 3;

    char T[MAX][MAX];
    int R[MAX];

    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    T[i][j] = ' ';
	}
    }
    
    for ( int j = 0; j < word1.size(); j++ ) T[row][j] = word1[j];
    for ( int j = 0; j < word3.size(); j++ ) T[row][j + word1.size() + 3] = word3[j];    
    for ( int i = 0; i < word2.size(); i++ ) T[row-t1+i][l1] = word2[i];
    for ( int i = 0; i < word4.size(); i++ ) T[row-t2+i][word1.size() + 3 + l2] = word4[i];

    for ( int i = 0; i < H; i++ ) R[i] = 0;
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    if ( T[i][j] != ' ' ) R[i] = j+1;
	}
    }


    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < R[i]; j++ ){
	    cout << T[i][j];
	}
	cout << endl;
    }

}

bool input(){
    cin >> word1;
    if ( word1 == "#" ) return false;
    cin >> word2 >> word3 >> word4;
    return true;
}

int main(){
    for( int i = 0; input(); i++ ) {
	if ( i ) cout << endl;
	print();
    }
    return 0;
}
