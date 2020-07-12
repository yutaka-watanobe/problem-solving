#include<stdio.h>
#define N 6

typedef struct R{
  int h, w;
} Rect;

/* check r1 > r2 ? */
int greater(Rect r1, Rect r2){
  if ( r1.h > r2.h ) return 1;
  if ( r1.h == r2.h && r1.w > r2.w ) return 1;
  return 0;
}

int solve(){
  Rect D[N], rtmp;
  int i, tmp, j;
  for ( i = 0; i < N; i++ ) {
    scanf("%d %d", &D[i].h, &D[i].w);
    if ( D[i].h > D[i].w) {
      tmp = D[i].h; D[i].h = D[i].w; D[i].w = tmp;
    }
  }

  /* bubble sort */
  for ( i = 0; i < N-1; i++ ){
    for ( j = N-2; j >= i; j-- ){
      if ( greater(D[j], D[j+1]) ){
	rtmp = D[j];
	D[j] = D[j+1];
	D[j+1] = rtmp;
      }
    }
  }

  for ( i = 0; i < N; i += 2){
    if ( D[i].h != D[i+1].h || D[i].w != D[i+1].w ) return 0;
  }

  return D[0].h == D[2].h && D[0].w == D[4].h && D[2].w == D[4].w;
}

int main(){
  if ( solve() ) printf("yes\n");
  else printf("no\n");
  return 0;
}


