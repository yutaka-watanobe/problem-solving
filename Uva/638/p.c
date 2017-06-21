// @JUDGE_ID:  17051CA  638  C++
// @begin_of_source_code
/* Brute Force */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

struct point{
 public:
  char name;
  int x, y;
  point(){}
  point( char name, int x, int y ): name(name), x(x), y(y){}

  bool operator < ( const point &p ) const {
    if ( x == p.x ){
      return y < p.y;
    } else {
      return x < p.x;
    }
  }
};

class FindingRectangles{
 public:
  int N;
  point P[30];
  int start[ 30 ];
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
    
    vector<string> rectangle;
    
    for ( int p1 = 0; p1 < nstart - 1; p1++ ){
      for ( int p2 = p1 + 1; p2 < nstart; p2++ ){
	
	int start1 = start[p1];
	int start2 = start[p2];
	int end1 = start[p1+1];
	int end2 = start[p2+1];

	for ( int i1 = start1; i1 < end1 - 1; i1++ ){
	  for ( int i2 = i1 + 1; i2 < end1; i2++ ){
	    for ( int j1 = start2; j1 < end2 - 1; j1++ ){
	      for ( int j2 = j1 + 1; j2 < end2; j2++ ){
		if ( P[i1].y == P[j1].y && P[i2].y == P[j2].y ){
		  string ans(4, ' ');
		  ans[0] = P[i2].name;
		  ans[1] = P[j2].name;
		  ans[2] = P[j1].name;
		  ans[3] = P[i1].name;
		  rectangle.push_back( ans );
		}
	      }
	    }
	  }
	}
      }
    }

    sort ( rectangle.begin(), rectangle.end() );

    if ( rectangle.size() == 0 ){
      printf(" No rectangles\n");
    } else {
      cout << endl;
      for ( int i = 0; i < rectangle.size(); i++ ){
	printf(" %s", rectangle[i].c_str() );
	if ( (i+1)%10 == 0 && i != rectangle.size() - 1 ) printf("\n");
      }
      printf("\n");
    }
  }

  bool read(){
    char name;
    int x, y;
    cin >> N;
    if ( N == 0 ) return false;
    for ( int i = 0; i < N; i++ ){
      cin >> name >> x >> y;
      P[i] = point( name, x, y );
    }
    sort( P, P + N );
    return true;
  }

};

main(){
  FindingRectangles FR;
  for ( int i = 1; FR.read(); i++ ){
    printf("Point set %d:", i );
    FR.work();
  }
}

// @end_of_source_code


