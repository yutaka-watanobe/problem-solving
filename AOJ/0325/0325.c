#include<stdio.h>
#define N 6

struct Rect{ int h, w; } ;

int solve(){
  struct Rect D[N], tmp;
  for ( int i = 0; i < N; i++ ) {
    scanf("%d %d", &D[i].h, &D[i].w);
    if ( D[i].h > D[i].w) {
      int tmp = D[i].h; D[i].h = D[i].w; D[i].w = tmp;
    }
  }

  /* バブルソート */
  for ( int i = 0; i < N - 2; i++ ){
    for ( int j = N - 2; j >= i; j-- ){
      if ( D[j].h > D[j + 1].h ||
	   D[j].h == D[j + 1].h && D[j].w > D[j + 1].w ){
	   tmp = D[j]; D[j] = D[j + 1]; D[j + 1] = tmp;
      }
    }
  }

  for ( int i = 0; i < N; i += 2 )
    if ( D[i].h != D[i + 1].h || D[i].w != D[i + 1].w ) return 0;

  return D[0].h == D[2].h && D[0].w == D[4].h && D[2].w == D[4].w;
}

int main(){
  printf( solve() ? "yes\n" : "no\n");
  return 0;
}


