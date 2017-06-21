// filling board
#include<stdio.h>
#include<algorithm>
#define MAX 502

using namespace std;

int W, H, N;
bool M[MAX][MAX];

void fillOut(int x1, int y1, int x2, int y2){
  int si = min(y1, y2);
  int ei = max(y1, y2);
  int sj = min(x1, x2);
  int ej = max(x1, x2);
  for ( int i = si; i <= ei; i++ ){
    for ( int j = sj; j <= ej; j++ ){
      M[i][j] = true;
    }
  }
}

void compute(){
  int x1, y1, x2, y2;
  for ( int i = 0; i < N; i++ ){
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    fillOut(x1, y1, x2, y2);
  }

  int sum = 0;
  for ( int i = 1; i <= H; i++ ){
    for ( int j = 1; j <= W; j++ ){
      if ( !M[i][j] ) sum++;
    }
  }

  if ( sum == 0 ){
    printf("There is no empty spots.\n");
  } else if ( sum == 1 ){
    printf("There is one empty spot.\n");
  } else {
    printf("There are %d empty spots.\n", sum);
  }

}

bool read(){
  scanf("%d %d %d", &W, &H, &N);
  if ( W == 0 && H == 0 && N == 0 ) return false;
  
  for ( int i = 1; i <= H; i++ ){
    for ( int j = 1; j <= W; j++ ){
      M[i][j] = false;
    }
  }
  return true;
}

main(){
  while ( read() ){
    compute();
  }
}
