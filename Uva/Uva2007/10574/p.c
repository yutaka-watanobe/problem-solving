// @JUDGE_ID:  17051CA  10574  C++
// @begin_of_source_code
/* Counting */
/* 1.094 sec */
#include<stdio.h>
#include<stl.h>
#define MAX 5001

struce point{
 public:
  int x, y;
  point(){}
  point( int x, int y ): x(x), y(y){}

  bool operator < ( const point &p ) const {
    if ( x == p.x ){
      return y < p.y;
    } else {
      return x < p.x;
    }
  }
};

class CountingRectangles{
 public:
  int N;
  point P[ MAX ];
  int start[ MAX ];
  int nstart;

  void createStart(){
    nstart = 0;
    int pre = -1;
    for ( int i = 0; i < N; i++ ){
      if ( pre != P[i].x ){
	start[nstart] = i;
	nstart++;
      }

      pre = P[i].x;
    }
    start[nstart] = N;
  }

  void work(){
    createStart();

    int total = 0;

    for ( int p1 = 0; p1 < nstart - 1; p1++ ){
      for ( int p2 = p1 + 1; p2 < nstart; p2++ ){

	int n = 0;

	int j = start[p2];
	int end1 = start[p1+1];
	int end2 = start[p2+1];

	for ( int i = start[p1]; i < end1; i++ ){
	  while ( P[i].y > P[j].y ){
	    j++;
	    if ( j >= end2 ) goto next;
	  }
	  if ( P[i].y == P[j].y ) n++;
	}

      next:;
	total += n*(n-1)/2;

      }
    }

    printf("%d\n", total );
  }

  void read(){
    scanf("%d", &N);
    int x, y;
    for ( int i = 0; i < N; i++ ){
      scanf("%d %d", &x, &y );
      P[i] = point( x, y );
    }

    sort ( P, P + N );
  }

};

main(){
  CountingRectangles CR;
  int tcase;
  scanf("%d", &tcase);
  for ( int i = 0; i < tcase; i++ ){
    printf("Case %d: ", i+1 );
    CR.read();
    CR.work();
  }
}


// @end_of_source_code


