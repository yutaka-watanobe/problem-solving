// @JUDGE_ID:  17051CA  432  C++
// @begin_of_source_code
/* Logic */
#include<stdio.h>
#include<iostream>

void print(int x1, int y1, int x2, int y2){
  cout << "(" << x1 << "," << y1 << ")";
  cout << "(" << x2 << "," << y2 << ")" << endl;
}

void work( int x, int y, int p, int q ){
  if ( p == 0 && q == 0 ){
    print(x, y, 0, 0); 
    print(0, 0, 2*x, 0);
    print(x*2, 0, x, y);
    return;
  }

  
  print(x, y, 0, 0);
  int bottom = x;
  int height = y;
  for ( int i = 0; i < p-1; i++ ) bottom /= 2;
  for ( int i = 0; i < p; i++ ) height /= 2;

  print(0, 0, bottom, 0 );
  for ( int i = 1; i <= p-1; i++ ){
    print(bottom, 0, bottom - bottom/2, height);
    print(bottom - bottom/2, height, bottom + bottom/2, height);
    print(bottom + bottom/2, height, bottom, 0 );
    print(bottom, 0, bottom*2, 0);
    bottom *= 2;
    height *= 2;
  }

  print( x, 0, x/2, y/2 );
  print( x/2, y/2, x + x/2, y/2 );
  print( x + x/2, y/2, x, 0 );

  int width = x/2;
  bottom = x;
  height = y/4;

  for ( int i = 1; i <= q-1; i++ ){
    print( bottom, 0, bottom + width, 0 );
    print( bottom + width, 0, bottom + width/2, height);
    print( bottom + width/2, height, bottom + width/2 + width, height );
    print( bottom + width/2 + width, height, bottom + width, 0 );
    bottom += width;
    width /= 2;
    height /= 2;
  }
  
  print( bottom, 0, x*2, 0 );
  print( x*2, 0, x, y );

}

main(){
  int t, p, q, x, y;
  cin >> t;
  for ( int i = 0; i < t; i++ ) {
    cin >> p >> q >> x >> y;
    work(x, y, p, q);
    cout << endl;
  }
}
// @end_of_source_code
