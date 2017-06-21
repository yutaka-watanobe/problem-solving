// @JUDGE_ID:  17051CA  10076  C++
// @begin_of_source_code
/* Graph ( State ) & BFS ( use Priority Queue ) */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<string>
#define MAX 15
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class Robot{
 public:
  int row, col, time, enegy;

  Robot(int row, int col, int time, int enegy): 
    row(row), col(col), time(time), enegy(enegy) {}

  bool operator < ( const Robot &r ) const{
    return ( r.time < time );
  }

};

int M, N, Rs, Cs, Rt, Ct, E;
double A1, A2, B1, B2;
int R, G;
int H[MAX][MAX];

int read(){
  cin >> M >> N;
  if ( M == 0 && N == 0 ) return 0;

  cin >> A1 >> A2 >> R;
  cin >> B1 >> B2 >> G;

  for ( int i = 0; i < M; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> H[i][j];
    }
  }

  cin >> Rs >> Cs >> Rt >> Ct >> E;
  Rs--; Cs--; Rt--; Ct--; /* zero base */
  return 1;
}

int getEnegy(int h1, int h2){
  if ( h1 > h2 ) return  (int)ceil(A1*(h1 - h2)) + R ;
  if ( h1 < h2 ) return  (int)ceil(A2*(h2 - h1)) + R ;
  return R;
}

int getTime(int h1, int h2 ){
  if ( h1 > h2 ) return  (int)ceil(B1*(h1 - h2)) + G ;
  if ( h1 < h2 ) return  (int)ceil(B2*(h2 - h1)) + G ;
  return G;
}

int bfs(){
  priority_queue< Robot > Q;

  Q.push( Robot( Rs, Cs, 0, 0 ) );
  int n_row, n_col;

  bool U[MAX][MAX][201];
  for ( int i = 0; i < M; i++ ){
    for ( int j = 0; j < N; j++ ){
      for ( int k = 0; k <= E; k++ ) U[i][j][k] = false;
    }
  }

  while ( !Q.empty() ){
    Robot robot = Q.top(); Q.pop();
//    cout << robot.row << " " << robot.col << " " << robot.time << " " << robot.enegy << endl;
    
    int row = robot.row;
    int col = robot.col;
    int time = robot.time;
    int enegy = robot.enegy;

    if ( U[row][col][enegy] ) continue;
    U[row][col][enegy] = true;

    if ( robot.row == Rt && robot.col == Ct ) return robot.time;

    for ( int d = 0; d < 4; d++ ){
      n_row = robot.row + dx[d];
      n_col = robot.col + dy[d];

      if ( 0 <= n_row && 0 <= n_col && n_row < M && n_col < N ){

	int dT = getTime( H[robot.row][robot.col], H[n_row][n_col] );
	int dE = getEnegy( H[robot.row][robot.col],H[n_row][n_col] );

	if ( robot.enegy + dE <= E && ! U[row][col][dE + enegy]){
	  Robot n_robot = Robot( n_row, n_col, robot.time + dT, robot.enegy + dE );
	  /* U[n_row][n_col][n_robot.enegy] = true; */
	  Q.push( n_robot );
	}
      }
    }
  }

  return INT_MAX;
}

void work(){
  int cost = bfs();
  if ( cost == INT_MAX ) cout << "failed" << endl;
  else cout << cost << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
