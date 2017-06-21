#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 100
#define INFTY (1<<21)

class Cut{
public:
  int x1, y1, x2, y2;
  Cut(){}
};

static const int dy[4] = {0, 1, 0, -1};
static const int dx[4] = {1, 0, -1, 0};

int n, cnt;
Cut C[MAX];

/*
void fillX(int y, int x, int H, int W, vector<vector<char> > &G){
  G[y][x] = 'X';
  int ny, nx;
  rep(r, 4){
    ny = y + dy[r];
    nx = x + dx[r];
    if ( ny < 0 || nx < 0 || H <= ny || W <= nx ) continue;
	 if ( G[ny][nx] == '.' ) fillX(ny, nx, H, W, G);
    }
    }
*/

void fillX(int y, int x, int H, int W, vector<vector<char> > &G){
  queue<pair<int, int> > Q;
  Q.push(make_pair(y, x));
  G[y][x] = 'X';
  pair<int, int> u, v;
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    //    G[u.first][u.second] = 'X';
    int ny, nx;
    rep(r, 4){
      ny = u.first + dy[r];
      nx = u.second + dx[r];
      if ( ny < 0 || nx < 0 || H <= ny || W <= nx ) continue;
	   if ( G[ny][nx] == '.' ) {
	     G[ny][nx] = 'X';
	     Q.push(make_pair(ny, nx));
	   }
   }
  }
}

bool compH(){
  vector<int> row;
  rep(i, n) {
      row.push_back(C[i].x1);
      row.push_back(C[i].x2);
  }
  sort( row.begin(), row.end());

  rep(i, n-1){
    int d = row[i+1] - row[i];
    if ( d >= 4 ){
      int l = row[i+1]-2 - (row[i]+2) + 1;
      rep(k, n){
	if ( C[k].x1 > row[i+1] &&
	     C[k].x2 > row[i+1] ){
	  C[k].x1 -= l;
	  C[k].x2 -= l;
	}


      }
      return true;
    }
  }
  return false;
}

void compute(){
  for ( int f = 0; f < n-1; f++ ){
    int mini = f;
    for ( int b = f+1; b < n; b++ ){
      if ( C[mini].x1 > C[b].x1 ) mini = b;
    }
    swap(C[f], C[mini]);
  }

  for ( int i = 1; i < n; i++ ){
    int d = INFTY;
    for ( int j = 0; j <= i-1; j++ ){
      d = min(d, C[i].x1 - C[j].x2);
    }
    if ( d <= 2 ) continue;
    int l = d-2;
    for ( int k = i; k < n; k++ ) { C[k].x1 -= l; C[k].x2 -= l; }
  }


  for ( int f = 0; f < n-1; f++ ){
    int mini = f;
    for ( int b = f+1; b < n; b++ ){
      if ( C[mini].y1 > C[b].y1 ) mini = b;
    }
    swap(C[f], C[mini]);
  }

  for ( int i = 1; i < n; i++ ){
    int d = INFTY;
    for ( int j = 0; j <= i-1; j++ ){
      d = min(d, C[i].y1 - C[j].y2);
    }
    if ( d <= 2 ) continue;
    int l = d-2;
    for ( int k = i; k < n; k++ ) { C[k].y1 -= l; C[k].y2 -= l; }
  }

  while( compH() );




  int X1, Y1, X2, Y2;

  X1 = Y1 = INFTY;
  X2 = Y2 = 0;
  rep(i, n){
    X1 = min(X1, C[i].x1);
    X2 = max(X2, C[i].x2);
    Y1 = min(Y1, C[i].y1);
    Y2 = max(Y2, C[i].y2);
  }

  //  cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;

  int H = Y2 - Y1 + 4;
  int W = X2 - X1 + 4;
  vector<vector<char> > G(H);
  for ( int i = 0; i < G.size(); i++ ){
    G[i] = vector<char>(W);
    for ( int j = 0; j < G[i].size(); j++ ) G[i][j] = '.';
  }

  rep(c, n){
    if ( C[c].x1 == C[c].x2 ){
      for ( int i = C[c].y1; i <= C[c].y2; i++ ){
	G[i-Y1+2][C[c].x1-X1+2] = 'X';
      }
    } else {
      for ( int j = C[c].x1; j <= C[c].x2; j++ ){
	G[C[c].y1-Y1+2][j-X1+2] = 'X';
      }
    }
  }

  /*
  for ( int i = H-1; i >= 0; i--){
    rep(j, W){
      cout << G[i][j];
    }
    cout << endl;
    }
  cout << endl;
  */

  fillX(0, 0, H, W, G);

 

  cnt = 0;
  rep(i, H) rep(j, W){
    if ( G[i][j] == '.' ){
      cnt++;
      fillX(i, j, H, W, G);
    }
  }
  cout << cnt << endl;


  /*
  
 for ( int i = H-1; i >= 0; i--){
    rep(j, W){
      cout << G[i][j];
    }
    cout << endl;
  }
  */
}

main(){
  int y1, x1, y2, x2;
  while( cin >> n && n ){
    rep(i, n){
      cin >> x1 >> y1 >> x2 >> y2;
      C[i].x1 = min(x1, x2)*2;
      C[i].x2 = max(x1, x2)*2;
      C[i].y1 = min(y1, y2)*2;
      C[i].y2 = max(y1, y2)*2;
    }
    compute();
  }
}
