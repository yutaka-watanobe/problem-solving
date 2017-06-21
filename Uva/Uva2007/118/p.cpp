#include<iostream>
#include<string>
#define MAX 60
#define LEFT -1
#define RIGHT 1
using namespace std;

char T[4] = {'E','N','W','S'};

int X, Y;
int currentX, currentY;
int direction;
string command;
bool scent[MAX][MAX];
bool isLost;

void rotate( int angle ){
  direction += angle;
  if ( direction == -1 ) direction = 3;
  else if ( direction == 4 ) direction = 0;
}

void forward(){
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx, ny;

  nx = currentX + dx[direction];
  ny = currentY + dy[direction];
  
  if ( 0 <= nx && 0 <= ny && nx <= X && ny <= Y ){
    currentX = nx;
    currentY = ny;
  } else {
    if ( !scent[currentX][currentY] ) {
      isLost = true;
      scent[currentX][currentY] = true;
    }
  }
}

void move( char com ){
  if ( com == 'L' ){
    rotate(1);
  } else if ( com == 'R' ){
    rotate(-1);
  } else if ( com == 'F' ){
    forward();
  }
}

void compute(){
  isLost = false;

  for ( int i = 0; i < command.size(); i++ ){
    if ( isLost ) continue;
    
    /*
    cout << endl;
    for ( int j = 0; j < Y; j++ ){
      for  ( int k = 0; k < X; k++ ){
	if ( scent[j][k] ) cout << "1";
	else cout << "0";
	
      }
      cout << endl;
      }*/


    move( command[i] );
  }

  cout << currentX << " " << currentY << " " << T[direction];
  if ( isLost ) cout << " LOST";
  cout << endl;
}

void init(){
  for ( int i = 0; i <= Y; i++ ){
    for ( int j = 0; j <= X; j++ ) scent[i][j] = false;
  }
  
}

int getDirection( char d){
  for ( int i = 0; i < 4; i++ ){
    if ( T[i] == d ){
      return i;
    }
  }
}

main(){
  char d;
  cin >> X >> Y;
  init();
  while ( cin >> currentX >> currentY >> d ){
    direction = getDirection(d);
    cin >> command;
    compute();
  }
}
