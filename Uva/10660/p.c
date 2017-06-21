// @JUDGE_ID:  17051CA  10660  C++
// @begin_of_source_code
#include<stdio.h>
#include<climits>

struct point{
  int x, y, v;
};

class Citizen{
 public:
  point C[25];
  int n;

  int dist( int x1, int y1, int x2, int y2 ){
    return abs(x1-x2) + abs(y1-y2);
  }

  int compute(int p1, int p2, int p3, int p4, int p5){
    
    int sum = 0;
    for ( int i = 0; i < n; i++ ){
      int minimumDistance = INT_MAX;
      int d;
      if ( (d = dist(C[i].x, C[i].y, p1/5, p1%5)) < minimumDistance ) minimumDistance = d;
      if ( (d = dist(C[i].x, C[i].y, p2/5, p2%5)) < minimumDistance ) minimumDistance = d;
      if ( (d = dist(C[i].x, C[i].y, p3/5, p3%5)) < minimumDistance ) minimumDistance = d;
      if ( (d = dist(C[i].x, C[i].y, p4/5, p4%5)) < minimumDistance ) minimumDistance = d;
      if ( (d = dist(C[i].x, C[i].y, p5/5, p5%5)) < minimumDistance ) minimumDistance = d;
      sum += minimumDistance * C[i].v;
    }
    return sum;
  }

  void work(){
    int opt1, opt2, opt3, opt4, opt5;
    int minValue = INT_MAX;
    
    for ( int p1 = 0; p1 <= 20; p1++ ){
      for ( int p2 = p1+1; p2 <= 21; p2++ ){
	for ( int p3 = p2+1; p3 <= 22; p3++ ){
	  for ( int p4 = p3+1; p4 <= 23; p4++ ){
	    for ( int p5 = p4+1; p5 <= 24; p5++ ){
	      int cost = compute(p1, p2, p3, p4, p5);
	      if ( cost < minValue ){
		minValue = cost;
		opt1 = p1;
		opt2 = p2;
		opt3 = p3;
		opt4 = p4;
		opt5 = p5;
	      }
	    }
	  }
	}
      }
    }
    printf("%d %d %d %d %d\n", opt1, opt2, opt3, opt4, opt5);
  }

  void read(){
    scanf("%d", &n);
    int x, y, v;
    for ( int i = 0; i < n; i++ ){
      scanf("%d %d %d", &x, &y, &v );
      C[i].x = x;
      C[i].y = y;
      C[i].v = v;
    }
  }
};

main(){
  Citizen C;
  int tcase;
  scanf("%d", &tcase );
  for (int i = 0; i < tcase; i++ ){
    C.read();
    C.work();
  }
}
// @end_of_source_code
