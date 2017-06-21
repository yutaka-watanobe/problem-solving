// @JUDGE_ID:  17051CA  656  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#define MAX 11
#define DEPTH_LIMIT 10
#define LIMIT 30000

struct Stack{
  int content[MAX][MAX]; // 2 dimentional stack
  int size[MAX]; // size
};

int ndata, depth;
Stack S;
int A[MAX]; // answer
vector<string> P; // path

bool hasElements(){
  for ( int i = 0; i < ndata; i++ ){
    if ( S.size[i] < 2 ) return false;
  }
  return true;
}

bool reached(){
  for ( int i = 0; i < ndata; i++ ){
    if ( S.content[i][0] != A[i] ) return false;
  }
  return true;
}

bool rec(int pos){
  if ( pos > depth ) return false;
  if ( reached() ) return true;

  Stack tmp = S; 
  bool error = false;
  int a, b, x;

  // ADD
  if ( hasElements() ){
    for ( int i = 0; i < ndata; i++ ){
      a = S.content[i][ S.size[i]-1 ]; b = S.content[i][ S.size[i]-2 ];
      x = a + b;
      S.content[i][ S.size[i]-2 ] = x;
      if ( abs( x ) > LIMIT ) error = true;
      S.size[i]--;
    }
    if ( !error && rec(pos+1) ) {P.push_back("ADD"); return true;}
    else { S = tmp; error = false; }
  }
  // DIV
  if ( hasElements() ){
    for ( int i = 0; i < ndata; i++ ){
      a = S.content[i][ S.size[i]-1 ]; b = S.content[i][ S.size[i]-2 ];
      if ( a == 0 ) {error = true; break;}
      x = b / a;
      S.content[i][ S.size[i]-2 ] = x;
      S.size[i]--;
    }
    if ( !error && rec(pos+1) ) { P.push_back("DIV"); return true;}
    else { S = tmp; error = false; }
  }
  // DUP
  for ( int i = 0; i < ndata; i++ ){
    S.content[i][ S.size[i] ] = S.content[i][ S.size[i]-1 ]; S.size[i]++;
  }
  if ( !error && rec(pos+1) ) { P.push_back("DUP"); return true;}
  else { S = tmp; error = false; }
  // MUL
  if ( hasElements() ){
    for ( int i = 0; i < ndata; i++ ){
      a = S.content[i][ S.size[i]-1 ]; b = S.content[i][ S.size[i]-2 ];
      x = a * b;
      S.content[i][ S.size[i]-2 ] = x;
      if ( abs( x ) > LIMIT ) error = true;
      S.size[i]--;
    }
    if ( !error && rec(pos+1) ) { P.push_back("MUL"); return true;}
    else { S = tmp; error = false; }
  }
  // SUB
  if ( hasElements() ){
    for ( int i = 0; i < ndata; i++ ){
      a = S.content[i][ S.size[i]-1 ]; b = S.content[i][ S.size[i]-2 ];
      x = b - a;
      S.content[i][ S.size[i]-2 ] = x;
      if ( abs( x ) > LIMIT ) error = true;
      S.size[i]--;
    }
    if ( !error && rec(pos+1) ) { P.push_back("SUB"); return true;}
    else { S = tmp; error = false; }
  }

  return false;
}

void printPath(){
  if ( P.size() == 0 ){
    cout << "Empty sequence" << endl;
    return;
  }

  for ( int i = P.size()-1; i >= 0; i-- ){
    cout << P[i];
    if ( i ) printf(" ");
  }
  printf("\n");
}

void work(){

  for ( depth = 1; depth <= DEPTH_LIMIT; depth++ ){
    P.clear();
    //    cout << "tyr " << depth << endl;
    if (rec(0)) { printPath(); return;}
  }

  printf("Impossible\n");
}

bool read(){
  int x, y;
  scanf("%d", &ndata);
  if ( ndata == 0 ) return false;
  for ( int i = 0; i < ndata; i++ ){
    scanf("%d", &x ); S.content[i][0] = x; S.size[i] = 1;
  }
  for ( int i = 0; i < ndata; i++ ) scanf("%d", &A[i] );
  return true;
}

int main(){
  for ( int i = 1; read(); i++ ) {
    printf("Program %d\n", i );
    work();
    printf("\n");
  }
  return 0;
}
// @end_of_source_code
