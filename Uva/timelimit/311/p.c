// @JUDGE_ID:  17051CA  311  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int P1, P2, P3, P4, P5, P6;

int read(){
  cin >> P1 >> P2 >> P3 >> P4 >> P5 >> P6;
  if ( P1 == 0 && P2 == 0 && P3 == 0 && P4 == 0 && P5 == 0 && P6 == 0 ) return 0;
  return 1;
}

void work(){
  int cnt = 0;

  while ( P6 > 0 ) {
    cnt++;
    P6--;
  }

  while( P5 > 0 ){
    cnt++;
    P1 -= 11;
    P5--;
  }
  
  while ( P4 > 0 ){
    cnt++;
    P4--;
    if ( P2 >= 5 ){
      P2 -= 5;
    }else {
      int k = P2;
      P2 -= k;
      P1 -= 20 - 4*k;
    }
  }

  while( P3 > 0 ){
    cnt++;
    if ( P3 == 4 ){
      P3 -= 4;
    }else if ( P3 == 3 ){
      P3 -= 3;
      if ( P2 > 0 ){ P2--; P1 -= 5;}
      else P1 -= 9;
    }else if ( P3 == 2 ){
      P3 -= 2;
      if ( P2 >= 3 ){
	P2 -= 3; P1 -= 6;
      } else if ( P2 == 2 ){
	P2 -= 2; P1 -= 10;
      } else if ( P2 == 1 ){
	P2 -= 1; P1 -= 14;
      } else if ( P2 == 0 ){
	P1 -= 18;
      }
    }else if ( P3 == 1 ){
      P3--;
      if ( P2 >= 5 ){
	P2 -= 5; P1 -= 7;
      }else{
	int k;
	P2 -= k;
	P1 -= 27 - k*4;
      }
    }
  }

  while ( P2 > 0 ){
    cnt++;
    if ( P2 >= 9 ) P2 -= 9;
    else {
      int k = P2;
      P2 = 0;
      P1 -= 36 - k*4;
    }
  }

  while ( P1 > 0 ){
    cnt++;
    P1 -= 36;
  }

  cout << cnt << endl;

}

main(){
  while ( read() ) work();
}
// @end_of_source_code
