// @JUDGE_ID:  17051CA  10592  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<iostream>
#define MAX 51

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

class point{
 public:
  int x, y;
  point(int x, int y ): x(x), y(y){}
};

class Fighter{
 public:
  vector<point> body;
  bool isFighting;

  Fighter(){
    body.clear();
    isFighting = false;
  }
};

class FreedomFighter{
 public:
  int n;
  char M[MAX][MAX];
  bool visited[MAX][MAX];
  bool visitedF[MAX][MAX];
  bool isFighting;
  int sector, freedom, enemy;
  Fighter currentF;
  Fighter currentE;
  vector<Fighter> F;
  vector<Fighter> E;

  bool read(){
    cin >> n;
    if ( n == 0 ) return false;

    F.clear();
    E.clear();
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	cin >> M[i][j];
	visited[i][j] = false;
	visitedF[i][j] = false;
      }
    }

    return true;
  }

  void parseSector(int i, int j ){

    int x, y;

    if( M[i][j] == 'B' && !visitedF[i][j] ){
      freedom++;
      visitedF[i][j] = true;
      currentF = Fighter();
      parseFreedom( i, j );
      F.push_back( currentF );
    } else if ( M[i][j] == 'P' && !visitedF[i][j] ){
      enemy++;
      visitedF[i][j] = true;
      currentE = Fighter();
      parseEnemy( i, j );
      E.push_back( currentE );
    }

    for ( int r = 0; r < 4; r++ ){
      x = i + dx[r];
      y = j + dy[r];
      if ( check(x, y) && M[x][y] != '.' && !visited[x][y] ){
	visited[x][y] = true;
	parseSector( x, y );
      }
    }
  }

  void parseFreedom( int i, int j ){

    currentF.body.push_back( point(i, j) );
    int x, y;
    
    for ( int r = 0; r < 4; r++ ){
      x = i + dx[r];
      y = j + dy[r];
      if ( check(x, y) && M[x][y] == 'B' && !visitedF[x][y] ){
	visitedF[x][y] = true;
	parseFreedom( x, y );
      } 
    }
  }
  
  void parseEnemy( int i, int j ){
    currentE.body.push_back( point(i, j) );
    int x, y;
    
    for ( int r = 0; r < 4; r++ ){
      x = i + dx[r];
      y = j + dy[r];
      if ( check(x, y) && M[x][y] == 'P' && !visitedF[x][y] ){
	visitedF[x][y] = true;
	parseEnemy( x, y );
      } 
    }

  }

  bool check( int x, int y ){
    return ( 0 <= x && 0 <= y && x < n && y < n );
  }

  bool fighting( Fighter fighter1, Fighter fighter2 ){
    int i, j, x, y;
    for ( int f = 0; f < fighter1.body.size(); f++ ){
      for ( int e = 0; e < fighter2.body.size(); e++ ){
	i = fighter1.body[f].x;
	j = fighter1.body[f].y;
	x = fighter2.body[e].x;
	y = fighter2.body[e].y;

	if ( i==x && abs(j-y) == 1 ) return true;
	if ( j==y && abs(i-x) == 1 ) return true;
      }
    }
    return false;
  }

  int getFighting(){

    int cnt = 0;

    for ( int f = 0; f < F.size(); f++ ){
      for ( int e = 0; e < E.size(); e++ ){
	if ( fighting( F[f], E[e] ) ) {
	 if ( !F[f].isFighting ){
	   F[f].isFighting = true;
	   cnt++;
	 }
	 if ( !E[e].isFighting ){
	   E[e].isFighting = true;
	   cnt++;
	 }
	 goto next;
	}
      }
    next:;
    }

    return cnt;
  }

  void work(){
    sector = 0;
    
    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < n; j++ ){
	if ( visited[i][j] ) continue;


	if ( M[i][j] != '.' ){
	  sector++;
	  freedom = enemy = 0;
	  visited[i][j] = true;
	  parseSector(i, j);
	  cout << "Sector #" << sector << ": ";
	  cout << "contain " << freedom << " freedom fighter group(s)";
	  cout << " & " << enemy << " enemy group(s)" << endl;
	}
      }
    }
    cout << "Total " << getFighting() << " group(s) are in fighting position." << endl;
    cout << endl;
  }

};

main(){
  FreedomFighter FF;

  while ( FF.read() ){
    FF.work();
  }
}

// @end_of_source_code


