#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<queue>
#include<map>
#define SPACE 100

struct State{
  unsigned char M[32]; /* grid */
  unsigned char P[32]; /* position of card ( 0 --> 11, 1 --> 12 ,, ) */
  unsigned char S[4]; /* space */
  unsigned short cost;
};

class Card{
 public:
  unsigned char M[32];
  Card(){}
  
  bool operator < ( const Card &c ) const{
    for ( int i = 31; i >= 0; i-- ){
      if ( M[i] == c.M[i] ) continue;
      return M[i] > c.M[i];
    }
  }
};

class Gap{
 public:
  State initial;
  map<Card, bool> used;

  bool valid( State &s ){
    if ( s.M[1] != 1 || s.M[2] != 2 || s.M[3] != 3 || s.M[4] != 4 || s.M[5] != 5 || s.M[6] != 6 ) return false;
    if ( s.M[9] != 11 || s.M[10] != 12 || s.M[11] != 13 || s.M[12] != 14 || s.M[13] != 15 || s.M[14] != 16 ) return false;
    if ( s.M[17] != 21 || s.M[18] != 22 || s.M[19] != 23 || s.M[20] != 24 || s.M[21] != 25 || s.M[22] != 26 ) return false;
    if ( s.M[25] != 31 || s.M[26] != 32 || s.M[27] != 33 || s.M[28] != 34 || s.M[29] != 35 || s.M[30] != 36 ) return false;
    return true;
  }

  bool getNext ( State &v, int sp ){
    int source = (int)v.M[ v.S[sp] - 1 ];

    if ( source == SPACE ) return false;
    if ( source % 10 == 6 ) return false;

    int target = source + 1;
    int targetPos = (int)v.P[ target ];

    v.M[ v.S[sp] ] = target;
    v.S[ sp ] = targetPos;
    v.M[ targetPos ] = SPACE;
  }

  void print( State  s ){
    for ( int i = 0; i < 32; i++ ){
      cout << (int)s.M[i] << " " ;
      if ( (i+1) % 8 == 0 ) cout << endl;
    }
  }

  int bfs(){
    queue<State> q;
    initial.cost = 0;
    q.push( initial );

    State u, v;

    used.clear();
    Card c;
    c.M = initial.M;

    used[ c ] = true;

    while ( !q.empty() ){
      u = q.front(); q.pop();

      if ( valid( u ) ) return u.cost;
      
      for ( int s = 0; s < 4; s++ ){
	v = u;
	if ( getNext( v, s ) ){
	  v.cost++;
	  for ( int i = 0; i < 32; i++ ) c.M[i] = v.M[i];

	  if ( !used[ c ] ){
	    used[ c ] = true;
	    q.push( v );
	  }
	}
      }

    }
    
    return -1;
  }

  void work(){
    cout << bfs() << endl;
  }

  void read(){
    int k;
    int sp = 0;
    for ( int i = 0; i < 32; i++ ){
      if ( i % 8 == 0 ) {
	initial.M[i] = SPACE;
      } else {
	cin >> k;
	k -= 11;
	initial.M[i] = (char)k;
	initial.P[(int)k] = i;
      }
    }

    for ( int i = 0; i < 32; i++ ){
      if ( i % 8 == 0 ) continue;
      int k = (int)initial.M[i];
      int p = initial.P[ k ];

      if ( k % 10 == 0 ){
	initial.M[p] = SPACE;
	initial.S[ sp++ ] = p;
	initial.M[ (k/10)*8 ] = k;
      }
    }
  }

};

main(){
  int tcase;
  Gap G;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    G.read();
    G.work();
    cout << endl;
  }
}
