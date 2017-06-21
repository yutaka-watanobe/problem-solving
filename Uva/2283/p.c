// @JUDGE_ID:  17051CA  2283  C++
// @begin_of_source_code
/* Can you create valid shape by given 3 shadows ? */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#define MAX 25
#define LIGHT 0
#define SHADOW 1
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int N;
vector<vector<int> > T; /* top face */
vector<vector<int> > F; /* front face */
vector<vector<int> > R; /* right face */
vector<vector<int> > U; /* used talbe for DFS */
int TC, FC, RC; /* counter of each block */
int counter;

int Cube[MAX][MAX][MAX];

void init(){
  T.clear();
  F.clear();
  R.clear();
  U.clear();
  T.resize( N );
  F.resize( N );
  R.resize( N );
  U.resize( N );
  for ( int i = 0; i < N; i++ ){
    T[i].resize( N );
    F[i].resize( N );
    R[i].resize( N );
    U[i].resize( N );
  }
  TC = FC = RC = 0;
}

int read(){
  cin >> N;
  if ( N == 0 ) return 0;
  init();
  char ch;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> ch;
      if ( ch == 'X' ){
	T[i][j] = SHADOW;
	TC++;
      }
      else T[i][j] = LIGHT;
    }
  }
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> ch;
      if ( ch == 'X' ){
	F[i][j] = SHADOW;
	FC++;
      }
      else F[i][j] = LIGHT;
    }
  }
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> ch;
      if ( ch == 'X' ) {
	R[i][j] = SHADOW;
	RC++;
      }
      else R[i][j] = LIGHT;
    }
  }
  return 1;
}

void rotate( vector<vector<int> > &v ){
  vector<vector<int> > tmp = v;
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      v[j][N-i-1] = tmp[i][j];
    }
  }
}

bool check(){
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      for ( int k = 0; k < N; k++ ){
	Cube[i][j][k] = SHADOW;
      }
    }
  }

  /* front */
  for ( int k = 0; k < N; k++ ){
    for ( int j = 0; j < N; j++ ){
      if ( F[k][j] == LIGHT ){
	for ( int i = 0; i < N; i++ ){
	  Cube[i][j][k] = LIGHT;
	}
      }
    }
  }
  /* top */
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      if ( T[i][j] == LIGHT ){
	for ( int k = 0; k < N; k++ ){
	  Cube[i][j][k] = LIGHT;
	}
      }
    }
  }
  /* right */
  for ( int k = 0; k < N; k++ ){
    for ( int i = 0; i < N; i++ ){
      if ( R[k][i] == LIGHT ){
	for ( int j = 0; j < N; j++ ){
	  Cube[N-i-1][j][k] = LIGHT;
	}
      }
    }
  }

  /* front */
  for ( int k = 0; k < N; k++ ){
    for ( int j = 0; j < N; j++ ){
      if ( F[k][j] == SHADOW ){
	for ( int i = 0; i < N; i++ ){
	  if ( Cube[i][j][k] == SHADOW ) goto next_front;
	}
	return false;
      }
    next_front:;
    }
  }
  /* top */
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      if ( T[i][j] == SHADOW ){
	for ( int k = 0; k < N; k++ ){
	  if ( Cube[i][j][k] == SHADOW ) goto next_top;
	}
	return false;
      }
    next_top:;
    }
  }
  /* right */
  for ( int k = 0; k < N; k++ ){
    for ( int i = 0; i < N; i++ ){
      if ( R[k][i] == SHADOW ){
	for ( int j = 0; j < N; j++ ){
	  if ( Cube[N-i-1][j][k] == SHADOW ) goto next_right;
	}
	return false;
      }
    next_right:;
    }
  }

  return true;
}

void initU(){
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      U[i][j] = 0;
    }
  }
  counter = 0;
}

void rec( vector<vector<int> > &v, int px, int py ){

  counter++;
  U[px][py] = 1;
  int ni, nj;

  for ( int r = 0; r < 4; r++ ){
    ni = px + dx[r];
    nj = py + dy[r];
    if ( 0 <= ni && 0 <= nj && ni < N && nj < N && !U[ni][nj]){
      if ( v[ni][nj] == SHADOW ) rec( v, ni, nj );
    }
  }
}

bool component(){

  initU();
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      if ( T[i][j] == SHADOW ) {
	rec ( T, i, j );
	goto end_com1;
      }
    }
  }
 end_com1:;
  if ( TC != counter ) return false;

  initU();
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      if ( F[i][j] == SHADOW ) {
	rec ( F, i, j );
	goto end_com2;
      }
    }
  }
 end_com2:;
  if ( FC != counter ) return false;

  initU();
  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      if ( R[i][j] == SHADOW ) {
	rec ( R, i, j );
	goto end_com3;
      }
    }
  }
 end_com3:;
  if ( RC != counter ) return false;

  return true;
}

void work(){
  bool able = false;
  
  if ( !component() ) goto next;

  for ( int i = 0; i < 4; i++ ){
    for ( int j = 0; j < 4; j++ ){
      for ( int k = 0; k < 4; k++ ){
	if ( check() ){
	  able = true;
	  goto next;
	}
	rotate( R );
      }
      rotate( F );
    }
    rotate( T );
  }

 next:;
  if ( able ){
    cout << "Valid set of patterns" << endl;
  } else {
    cout << "Impossible combination" << endl;
  }
}

main(){
  for (  int i = 1; read(); i++ ){
    cout << "Data set " << i << ": ";
    work();
  }
}
// @end_of_source_code
