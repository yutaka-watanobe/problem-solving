// @JUDGE_ID:  17051CA  10667  C++
// @begin_of_source_code
#include<stdio.h>
#include<algorithm>
#define MAX 101

class LargestBlock{
 public:
  bool V[MAX][MAX];
  int T[MAX][MAX];
  int size;

  void createTable(){
    for ( int j = 0; j < size; j++ ){
      int cnt = 0;      
      for ( int i = size-1; i >= 0; i--){
	if ( !V[i][j] ){
	  cnt++;
	  T[i][j] = cnt;
	} else {
	  cnt = 0;
	}
      }
    }
  }

  int compute(){
    int maxValue = 0;

    for (int i = 0; i < size; i++ ){
      for ( int j = 0; j < size; j++ ){
	int cnt = 0;
	int value = T[i][j];
	if( T[i][j]==0) goto next;
	for (int jj = j; jj < size; jj++ ){
	  value = min( value, T[i][jj] );
	  cnt++;
	  maxValue = max( maxValue, cnt*value );
	}
      next:;
      }
    }
    return maxValue;
  }

  void work(){
    createTable();
    printf("%d\n", compute());
  }

  void read(){
    scanf("%d", &size);
    for ( int i = 0; i < size; i++ )
      for ( int j = 0; j < size; j++ ) { V[i][j] = false; T[i][j] = 0;}

    int n;
    scanf("%d", &n );
    int sx, sy, ex, ey;

    for ( int i = 0; i < n; i++ ){
      scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

      for ( int x = sx; x <= ex; x++ ){
	for ( int y = sy; y <= ey; y++ ){
	  V[x-1][y-1] = true;
	}
      }

    }

  }
};

main(){
  LargestBlock LB;

  int tcase;
  scanf("%d", &tcase );
  for ( int i = 0; i < tcase; i++ ){
    LB.read(); LB.work();
  }
}
// @end_of_source_code
