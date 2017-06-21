// @JUDGE_ID:  17051CA  10422  C++
// @begin_of_source_code
/* BFS */
/* start --> BFS  BFS <-- end  technique */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
#include<queue>
typedef unsigned short ushort;
#define WHITE 0
#define BLACK 1
#define SPACE 2

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

vector<ushort> S;
vector<ushort> G;

int sx, sy;

void read(){
  S.clear();
  S.resize( 25 );
  string line;
  for ( int i = 0; i < 5; i++ ){
    getline( cin, line );
    for ( int j = 0; j < 5; j++ ){
      int pos = i*5+j;
      if ( line[j] == '1' ) S[pos] = BLACK;
      else if ( line[j] == '0' ) S[pos] = WHITE;
      else if ( line[j] == ' ' ) {
	S[pos] = SPACE;
	sx = i; sy = j;
      }
    }
  }
}

int bfs(){
  map<vector<ushort>, bool> U;
  map<vector<ushort>, int> D;
  map<vector<ushort>, bool> UG;
  map<vector<ushort>, int> DG;

  vector< pair< vector<ushort>, int> > q1, q2, n1, n2;
  pair<vector<ushort>, int> p;

  U[ S ] = true;
  D[ S ] = 0;

  UG[ G ] = true;
  DG[ G ] = 0;

  vector<ushort> u, v;
  int pos, px, py, tx, ty, target;

  q1.push_back( make_pair( S, sx*5+sy) );
  q2.push_back( make_pair( G, 12) );

  while ( q1.size() && q2.size() ){

    for ( int i = 0; i < q1.size(); i++ ){
      if ( UG[ q1[i].first ] ){
	return DG[ q1[i].first ] + D[ q1[i].first ];
      }
    }
    for ( int i = 0; i < q2.size(); i++ ){
      if ( U[ q2[i].first ] ){
	return DG[ q2[i].first ] + D[ q2[i].first ];
      }
    }

    n1.clear();
    n2.clear();

    /* from begin */
    for ( int i = 0; i < q1.size(); i++ ){
      p = q1[i];
      u = p.first;
      pos = p.second;
      px = pos/5;
      py = pos%5;
      for ( int r = 0; r < 8; r++ ){
	tx = px + dx[r];
	ty = py + dy[r];
	if ( 0 <= tx && 0 <= ty && tx < 5 && ty < 5 ){
	  v = u;
	  target = tx*5+ty;
	  v[px*5+py] = u[target];
	  v[target] = SPACE;

	  if ( !U[ v ] ){
	    int d =  D[ u ] + 1;
	    U[ v ] = true;
	    D[ v ] = d;
	    if ( d < 6 ) n1.push_back( make_pair(v, target) );
	  }
	}
      }
    }
    /* from end */
    for ( int i = 0; i < q2.size(); i++ ){
      p = q2[i];
      u = p.first;
      pos = p.second;
      px = pos/5;
      py = pos%5;
      for ( int r = 0; r < 8; r++ ){
	tx = px + dx[r];
	ty = py + dy[r];
	if ( 0 <= tx && 0 <= ty && tx < 5 && ty < 5 ){
	  v = u;
	  target = tx*5+ty;
	  v[px*5+py] = u[target];
	  v[target] = SPACE;
	  if ( !UG[ v ] ){
	    int d =  DG[ u ] + 1;
	    UG[ v ] = true;
	    DG[ v ] = d;
	    if ( d < 6 ) n2.push_back( make_pair(v, target) );
	  }
	}
      }
    }

    q1 = n1;
    q2 = n2;
  }

  return INT_MAX;
}

void work(){
  int cost = bfs();

  if ( cost > 10 ){
    cout << "Unsolvable in less than 11 move(s)." << endl;
  }else{
    cout << "Solvable in " << cost << " move(s)." << endl;
  }
}

void init(){
  G.resize( 25, BLACK );
  G[5] = WHITE;
  G[10] = G[11] = WHITE;
  G[15] = G[16] = G[17] = G[18] = WHITE;
  G[20] = G[21] = G[22] = G[23] = G[24] = WHITE;
  G[12] = SPACE;
}

main(){
  string line;
  getline( cin, line );
  int t;
  t = atoi( line.c_str() );
  for ( int i = 0; i < t; i++ ){
    init();
    read();
    work();
  }
}
// @end_of_source_code
