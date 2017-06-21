// @JUDGE_ID:  17051CA  776  C++
// @begin_of_source_code
#include<stdio.h>
#include<cmath>
#define MAX 1000

class Monkey{
 public:
  char C[MAX][MAX];
  int T[MAX][MAX];
  int row, column;
  int digit;

  void dfs(int x, int y, char color, int value){
    T[x][y] = value;

    //    printf("%d %d\n", x, y );

    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    int nx, ny;
    for ( int r = 0; r < 8; r++ ){
      nx = x + dx[r];
      ny = y + dy[r];
      if ( 0 <= nx && 0 <= ny && nx < row && ny < column ){
	if ( C[nx][ny] == color && T[nx][ny] == 0){
	  dfs( nx, ny, color, value );
	}
      }
    }
  }

  void printSpace( int x ){
    int d = (int)(log10( x ));
    for ( int i = d; i <= digit; i++ ) printf(" ");
  }

  void work(){
    for ( int i = 0; i < row; i++ ){
      for (int j = 0; j < column; j++ ){
	T[i][j] = 0;
      }
    }

    int current = 1;
    for (int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	if ( T[i][j] == 0 ){
	  dfs(i, j, C[i][j], current++);
	}
      }
    }
    current--;

    digit = (int)(log10( current )) + 1;

    for ( int i = 0; i < row; i++ ){
      for ( int j = 0; j < column; j++ ){
	printSpace(T[i][j]);
	printf("%d", T[i][j] );
      }
      printf("\n");
    }
    printf("%%\n");
  }

  bool read(){
    row = column = 0;
    int c;
    char ch;
    c = 0;

    while ( 1 ){
      
      if ( scanf("%c", &ch ) == EOF) {
	work();
	return false;
      }
      if ( ch == '%' ) {
	scanf("%c",&ch );
	work();
	return true;
      }

      if ( ch == ' ') continue;

      if ( ch == '\n') {
	row++;
	column = c;
	c = 0;
      } else {
	C[row][c++] = ch;
      }
    }
  }
};

main(){
  Monkey M;
  while ( M.read() );
}

// @end_of_source_code
