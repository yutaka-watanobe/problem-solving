// @JUDGE_ID:  17051CA  10000  C++
// @begin_of_source_code
// Longest path on a non cyclic graph --> floyd
#include<stdio.h>
#include<vector>
#define MAX 100

int n;
int M[MAX][MAX];

bool read(){
  scanf("%d", &n);
  if(n==0) return false;
  return true;
}

void floyd(){
  for ( int k = 0; k < n; k++ ){
    for ( int i = 0; i < n; i++ ){
      if ( M[i][k] == 0 ) continue;
      for ( int j = 0; j < n; j++ ){
	if ( M[k][j] == 0 ) continue;
	
	if ( M[i][j] == 0 ||  M[i][k] + M[k][j] > M[i][j] ){
	  M[i][j] = M[i][k] + M[k][j];
	}
      }
    }
  }
}

void work(){
  int start, i, j;

  scanf("%d", &start); start--;

  for ( int i = 0; i < n ; i++ ){
    for ( int j = 0; j < n ; j++ ){
      M[i][j] = 0;
    }
  }

  while(1){
    scanf("%d %d", &i, &j);
    if(i==0 && j==0) break;
    M[i-1][j-1] = 1;
  }

  floyd();

  int max = INT_MIN;
  int index;
  for(int i=0; i < n; i++){
    if(M[start][i] > max) {
      max = M[start][i];
      index = i;
    }
  }

  printf("The longest path from %d has length %d, finishing at %d.\n", start+1, max, index+1);
}

main(){
  for(int i=1; read(); i++){
    printf("Case %d: ", i);
    work();
    printf("\n");
  }
}



// @end_of_source_code
