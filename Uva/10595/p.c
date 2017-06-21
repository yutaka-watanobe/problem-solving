// @JUDGE_ID:  17051CA  10595  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>

#define MAX 10001
#define C_MAX 150
#define SHIFT 60

int dx[12] = {1, 2, 3, 3, 2, 1, -1, -2, -3, -3, -2, -1};
int dy[12] = {2, 1, -1, -2, -3, -3, -2, -1, 1, 2, 3, 3};

class point{
 public:
  int x, y;
  point(){}
  point(int x, int y ): x(x), y(y){}
};

class KnightOnBee {
 public:
  int N, M;
  bool obstacle[MAX + 1000];
  int coordinate[C_MAX+50][C_MAX+50];
  int source, target;
  point coordinateB[MAX + 1000];
  
  void generateCoordinate(){
    
    coordinateB[1] = point(0 + SHIFT, 0 + SHIFT);
    coordinate[0 + SHIFT][0 + SHIFT] = 1;

    coordinateB[2] = point(0 + SHIFT, -1 + SHIFT);
    coordinate[0 + SHIFT][-1 + SHIFT] = 2;

    int x = 0, y = -1, p = 2;
    int step = 1;

    while ( p < MAX ){
      
      /* upper left */
      for ( int i = 0; i < step; i++ ){
	x--; y++; p++;
	coordinateB[p] = point( x + SHIFT, y + SHIFT );
	coordinate[x +SHIFT][y + SHIFT] = p;
      }

      /* top */
      for ( int i = 0; i < step; i++ ){
	y++; p++;
	coordinateB[p] = point( x + SHIFT, y + SHIFT );
	coordinate[x +SHIFT][y + SHIFT] = p;
      }

      /* right */
      for ( int i = 0; i < step; i++ ){
	x++; p++;
	coordinateB[p] = point( x + SHIFT, y + SHIFT );
	coordinate[x +SHIFT][y + SHIFT] = p;
      }

      /* lower right */
      for ( int i = 0; i < step; i++ ){
	x++; y--; p++;
	coordinateB[p] = point( x + SHIFT, y + SHIFT );
	coordinate[x +SHIFT][y + SHIFT] = p;
      }

      /* down */
      for ( int i = 0; i < step + 1; i++ ){
	y--; p++;
	coordinateB[p] = point( x + SHIFT, y + SHIFT );
	coordinate[x +SHIFT][y + SHIFT] = p;
      }

      /* left */
      for ( int i = 0; i < step; i++ ){
	x--; p++;
	coordinateB[p] = point( x + SHIFT, y + SHIFT );
	coordinate[x +SHIFT][y + SHIFT] = p;
      }

      step++;
    }
  }

  bool read(){
    
    cin >> N;
    if ( cin.eof() ) return false;
    cin >> M;
    int ob;

    for ( int i = 1; i <= N; i++ ) obstacle[i] = false;
    for ( int i = 0; i < M; i++ ){
      cin >> ob;
      obstacle[ob] = true;
    }
    
    cin >> source >> target;
    return true;
  }

  void work(){
    int cost = bfs();
    if ( cost == - 1 ) cout << "Impossible." << endl;
    else cout << cost << endl;
  }

  int bfs(){
    queue<int> q;
    vector<int> d, used;

    int u, v;
    int px, py;

    d.resize(N + 1, 0);
    used.resize( N + 1, 0 );

    q.push(source);
    d[source] = 0;
    used[source] = 1;
    
    while ( !q.empty() ){
      u = q.front(), q.pop();
      if ( u == target ) return d[u];

      for ( int r = 0; r < 12; r++ ){
	px = coordinateB[u].x + dx[r];
	py = coordinateB[u].y + dy[r];
	
	v = coordinate[px][py];

	if ( v <= N && !used[v] && !obstacle[v] ){
	  d[v] = d[u] + 1;
	  used[v] = 1;
	  q.push(v);
	}

      }

    }
    
    return -1;
  }
  
};

main(){
  KnightOnBee KOB;

  KOB.generateCoordinate();

  while ( KOB.read() ){
    KOB.work();
  }
}

// @end_of_source_code


