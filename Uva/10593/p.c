// @JUDGE_ID:  17051CA  10593  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 501

class Kites{
 public:
  int n;

  char M[ MAX ][ MAX ];
  int T[ MAX ][ MAX ];

  bool read(){
        cin >> n;
        if ( cin.eof() ) return false;

    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
		cin >> M[i][j];
      }
    }

    return true;
  }

  void createTable(){
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	T[i][j] = 0;
      }
    }

    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	int k;
	for ( k = j; k < n; k++ ){
	  if ( M[i][k] == '.' ) goto next;
	}
      next:
	T[i][j] = k - j;
      }
    }

  }

  int getSqure(){

    int v;
    int cnt = 0;

    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	v = T[i][j];
	if ( v < 2 ) continue;
	
	int height;
	int height_limit = min( n - i, T[i][j] );
	for ( height = height_limit; height >= 2; height-- ){
	  for ( int k = i; k < i + height; k++ ){
	    if ( T[k][j] < height ) goto next;
	  }
	  cnt += (height - 1);
	  goto end;
	next:;
	}
      end:;
      }
    }

    return cnt;
  }

  int getDiamond(){
    
    int v;
    int cnt = 0;
    
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	v = T[i][j];
	if ( v < 3  ) continue;
	
	int width;
	int width_limit = min( v, min( 2*(n - i - 1) + 1, 2*i + 1) );
	if ( width_limit % 2 == 0 ) width_limit--;

	for ( width = width_limit; width >= 3; width -= 2 ){
	  for ( int p = 1, lim = width/2; p <= lim; p++ ){
	    int upper = width - 2*p;
	    if ( T[i-p][j+p] < upper ) goto next;
	    if ( T[i+p][j+p] < upper ) goto next;
	  }
	  cnt += ( width / 2 );
	  goto end;
	next:;
	}
      end:;
      }
    }
    
    return cnt;
  }

  void work(){
    createTable();
    //    cout << getSqure() + getDiamond() << endl;
    printf("%d\n", getSqure()+getDiamond());
  }

};

main(){
  Kites K;
  while ( K.read() ){
    K.work();
  }
}

// @end_of_source_code


