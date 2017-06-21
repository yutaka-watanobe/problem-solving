// @JUDGE_ID:  17051CA  10642  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>

class CanYouSolveIt{
 public:
  int x1, y1, x2, y2;
  unsigned long long p;

  bool same_line(){
    return ( x1+y1 == x2 + y2 );
  }

  void work(){
    cin >> x1 >> y1 >> x2 >> y2;
    p = 0;

    if ( x1 == x2 && y1 == y2 ){
      cout << 0 << endl;
      return ;
    }

    if ( same_line()){
      print();
      return;
    } else {
      if ( x1 == 0 && y1 == 0 ){
	x1 = 0; y1= 1;
	p++;
      }else{
	p += (y1+1);
	y1 = (y1 + x1) + 1;
	x1 = 0;
      }
    }

    while ( !same_line() ){
      p += y1 + x1 + 1;
      y1 = (y1 + x1)+1;
      x1 = 0;
    }

    print();
  }

  void print(){
    cout << (x2 - x1) + p<< endl;
  }
};


main(){
  CanYouSolveIt CY;

  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    cout << "Case " << i+1 << ": ";
    CY.work();
  }
}


// @end_of_source_code


