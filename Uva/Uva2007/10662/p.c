// @JUDGE_ID:  17051CA  10662  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h>
#define MAX 21

class TheWedding{
 public:
  int nT, nR, nH;
  int T[MAX][MAX+1], R[MAX][MAX+1], H[MAX][MAX+1];

  void work(){
    int minValue = INT_MAX;
    int minT, minR, minH;
    int value;

    for ( int t = 0; t < nT; t++ ){
      for ( int r = 0; r < nR; r++ ){
	if ( T[t][r+1] == 1 ) continue;


	for ( int h = 0; h < nH; h++ ){
	  if ( R[r][h+1] == 1 ) continue;


	  for ( int t2 = 0; t2 < nT; t2++ ){
	    if ( H[h][t2+1] == 1 ) continue;

	    if ( t == t2 ){
	      value = T[t][0] + R[r][0] + H[h][0];
	      if ( minValue > value ){
		minValue = value;
		minT = t;
		minR = r;
		minH = h;
	      }
	    }
	  }
	}
      }
    }
    if ( minValue == INT_MAX ){
      printf("Don't get married!\n");
    } else {
      printf("%d %d %d:%d\n", minT, minR, minH, minValue );
    }

  }

  bool read(){
    if ( scanf("%d %d %d", &nT, &nR, &nH) == EOF ) return false;
    for ( int i = 0; i < nT; i++ )
      for ( int j = 0; j < nR+1; j++ ) scanf("%d", &T[i][j] );
    for ( int i = 0; i < nR; i++ )
      for ( int j = 0; j < nH+1; j++ ) scanf("%d", &R[i][j] );
    for ( int i = 0; i < nH; i++ )
      for ( int j = 0; j < nT+1; j++ ) scanf("%d", &H[i][j] );

    return true;
  }
};

main(){
  TheWedding TW;
  while ( TW.read() ) TW.work();
}

// @end_of_source_code
