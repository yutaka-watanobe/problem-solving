// @JUDGE_ID:  17051CA  460  C++
// @begin_of_source_code
/* Geometory */
/* Overlaping Rectangle */
#include<stdio.h>
#include<iostream>
#include<string>

class Rectangle{
 public:
  int x1, y1, x2, y2;
  Rectangle(){}
  Rectangle(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2){}

  void overlap( Rectangle r ){
    if ( x1 <= r.x1 && r.x1 <= x2 && x2 <= r.x2 ){
      x1 = r.x1;
    }else if ( r.x1 <= x1 && x1 <= r.x2 && r.x2 <= x2 ){
      x2 = r.x2;
    }else if ( x1 <= r.x1 && r.x2 <= x2 ){
      x1 = r.x1;
      x2 = r.x2;
    }else if ( r.x1 <= x1 && x2 <= r.x2 ){
      /* nothing */
    }else{
      cout << "5" << endl;
      return;
    }

    if ( y1 <= r.y1 && r.y1 <= y2 &&  y2 <= r.y2 ){
      y1 = r.y1;
    }else if ( r.y1 <= y1 && y1 <= r.y2 && r.y2 <= y2 ){
      y2 = r.y2;
    }else if ( y1 <= r.y1 && r.y2 <= y2 ){
      y1 = r.y1;
      y2 = r.y2;
    }else if ( r.y1 <= y1 && y2 <= r.y2 ){
      /* nothing */
    }else{
      x1 = y1 = x2 = y2 = 0;
      return ;
    }
  }

  bool operator==(const Rectangle r) const{
    return (x1==r.x1 && y1==r.y1 && x2==r.x2 && y2==r.y2);
  }
};

Rectangle r1, r2;

int read(){
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  r1 = Rectangle(x1, y1, x2, y2);
  cin >> x1 >> y1 >> x2 >> y2;
  r2 = Rectangle(x1, y1, x2, y2);
}

void work(){

  r1.overlap( r2 );

  if( r1.x1 == r1.x2 || r1.y1 == r1.y2 ){
    cout << "No Overlap" << endl;
  }else{
    cout << r1.x1 << " " << r1.y1 << " " << r1.x2 << " " << r1.y2 << endl;
  }

}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
