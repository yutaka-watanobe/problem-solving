#include<iostream>



main(){
  

  int board[108][108];
  int a[108], b[108];

  int x, x1, xa, xb, y, ya, s, s0;
  int r, c;
  while ( cin >> r >> c ){
    if ( r == 0 && c == 0 ) break;

    for ( x = 0; x <= r+1; x++ ){
      a[x] = 0;
      b[x] = 0;
      board[x][c+1] = 0;
      board[0][x] = 0;
      board[c+1][x] = 0;
    }
    
    for ( y = 1; y <= r; y++ ){
      for ( x = 1; x <= c; x++ ){
	cin >> board[x][y];
      }
    }

    for ( y = 1; y <= r; y++ ){
      xa = 0; xb = 0;
      for ( x = 1; x <=c; x++ ){
	x1 = x+1;
	if (board[x1][y] == 0 ){
	  a[x1] = y; b[x1] = 0; xb = x1;
	} else if ( b[x1] < xb) b[x1] = xb;
	
	if ( board[x][y+1] == 0 ) xa = x;
	if ( a[xa] < a[x1] ){
	  while ( a[xa] < a[x1] ){
	    ya = a[xa]; xa = b[xa]; s = (y-ya)*(x-xa);
	    if ( s > s0 ) s0 = s;
	  }
	  xa = x1;
	}
      }
    }
 
   
  }
}
