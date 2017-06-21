#include<iostream>
#include<vector>

using namespace std;
#define MAX 100

class Block{
public:
  int c, d, x, y;
  Block(int c=0, int d=0, int x=0, int y=0):c(c), d(d), x(x), y(y){}
};

bool used[MAX][MAX];

bool check( int d, int x, int y, int w, int h){
  int nx, ny;
  if ( d == 0 ){
    for ( int dy = 0; dy < 2; dy++ ){
      for ( int dx = 0; dx < 4; dx++ ){
	ny = dy + y;
	nx = dx + x;
	if ( nx < 0 || ny < 0 || ny >= h || nx >= w ) return false;
	if ( used[ny][nx] ) return false;
      }
    }
  } else {
    for ( int dy = 0; dy < 4; dy++ ){
      for ( int dx = 0; dx < 2; dx++ ){
	ny = dy + y;
	nx = dx + x;
	if ( nx < 0 || ny < 0 || ny >= h || nx >= w ) return false;
	if ( used[ny][nx] ) return false;
      }
    }
  }
  return true;
}

void gen( int w, int h, int r ){
  cout << w << " " << h << endl;



  for ( int y = 0; y < h; y++ ){
    for ( int x = 0; x < w; x++ ){
      used[y][x] = false;
    }
  }

  cout << rand()%w+1 << " " << rand()%h + 1 << endl;
  cout << rand()%w+1 << " " << rand()%h + 1 << endl;

  vector<Block> v;
  for ( int i = 0; i < r; i++ ){
    int c = rand()%5 + 1;
    int d = rand()%2;
    int x = rand()%w;
    int y = rand()%h;

    if ( !check(d, x, y, w, h) ) continue;

    if ( d == 0 ){
      for ( int dy = 0; dy < 2; dy++ )
	for ( int dx = 0; dx < 4; dx++ ) used[y+dy][x+dx] = true;
    } else {
      for ( int dy = 0; dy < 4; dy++ )
	for ( int dx = 0; dx < 2; dx++ ) used[y+dy][x+dx] = true;
    }

    v.push_back(Block(c, d, x+1, y+1));
  }

  cout << v.size() << endl;
  for ( int i = 0; i < v.size(); i++ ){
    cout << v[i].c << " " << v[i].d << " " << v[i].x << " " << v[i].y << endl;
  }
  


}

main(){
  gen(4, 4, 10);
  gen(8, 8, 10);
  gen(8, 8, 10);
  gen(8, 8, 10);
  gen(8, 8, 10);
  gen(8, 8, 10);
  gen(20, 20, 10);
  gen(20, 20, 20);
  gen(20, 20, 20);
  gen(20, 20, 20);
  gen(20, 20, 20);
  gen(20, 20, 30);
  gen(20, 20, 40);
  gen(20, 20, 50);
  gen(20, 20, 50);

  cout << "0 0" << endl;
}
