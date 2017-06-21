#include<stdio.h>
#include<iostream>
#include<cassert>
#include<string>
#define MAX 52

using namespace std;

int row, column;

char G[MAX][MAX];

bool check(int si, int sj, string word){

  int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
  int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

  
  for ( int d = 0; d < 8; d++ ){
    int i, j;


    for ( int w = 0; w < word.size(); w++ ){
      i = si + di[d]*w;
      j = sj + dj[d]*w;
      if ( 0 <= i && 0 <= j && i < row && j < column ){
	if ( word[w] != G[i][j] ) goto next;
      } else goto next;
    }

    return true;

    next:;
  }

  return false;
}

void search(string word){


  for ( int i = 0; i < row; i++ ){
    for ( int j = 0; j < column; j++ ){
      if ( check( i, j, word ) ){
	cout << i+1 << " " << j+1 << endl;
	return;
      }
    }
  }

  cout << "fail" << endl;
}



void work(){
  string line;
  int n; cin >> n;
  getline( cin , line );

  for ( int i = 0; i < n ;i++ ){
    getline( cin, line );

    for ( int w = 0; w < line.size(); w++ ) line[w] = tolower(line[w]);
    search( line );
  }
}

void read(){
  string line;
  cin >> row >> column;
  getline ( cin, line );

  for ( int i = 0; i <row; i++ ){
    getline( cin, line );
    
    assert( line.size() == column );

    for ( int j = 0; j < line.size(); j++ ){
      G[i][j] = tolower(line[j]);
    }
  }
}

main(){
  string line;
  int tcase; cin >> tcase;
  getline( cin, line );

  for ( int i = 0; i < tcase; i++ ){
    getline( cin, line );

    if ( i ) cout << endl;
    read();
    work();
  }
  
}
