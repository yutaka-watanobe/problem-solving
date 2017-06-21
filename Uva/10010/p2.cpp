#include<stdio.h>
#include<iostream>
#include<cassert>
#include<string>
#define MAX 52
#define EMPTY '0'
using namespace std;

int row, column;

char G[MAX][MAX];

bool check(int si, int sj, string word){
    
    int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
  int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  
  for ( int direction = 0; direction < 8; direction++ ){
      int i, j;

      for ( int w = 0; w < word.size(); w++ ){
	  i = si + di[direction] * w;
	  j = sj + dj[direction] * w;
	  if ( word[w] != G[i][j] ) goto next;
      }
      
      return true;
  next:;
  }
  
  return false;
}

void search(string word){
    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= column; j++ ){
	    if ( check( i, j, word ) ){
		cout << i << " " << j << endl;
		return;
	    }
	}
    }
    assert( false );
}

void work(){
    string word;
    int n; cin >> n;
    
    for ( int i = 0; i < n ;i++ ){
	cin >> word;
	for ( int w = 0; w < word.size(); w++ ) word[w] = tolower(word[w]);
	search( word );
    }
}

void read(){
    for ( int i = 0; i < row + 2; i++ ) G[i][0] = G[i][column+1] = EMPTY;
    for ( int j = 0; j < column + 2; j++ ) G[0][j] = G[row+1][j] = EMPTY;
    cin >> row >> column;
    char ch;
    for ( int i = 1; i <= row; i++ ){
	for ( int j = 1; j <= column; j++ ){
	    cin >> ch;
	    G[i][j] = tolower(ch);
	}
    }
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
      if ( i ) cout << endl;
      read();
      work();
  }
}
