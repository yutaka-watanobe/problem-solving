#include<iostream>
#include<cstdio>
using namespace std;

main(){
  double a, s;
  while( cin >> a ){
    s = a;
    for ( int i = 2; i <= 10; i++ ){
      if ( i % 2 == 0 ) a *= 2;
      else a /= 3;
      s += a;
    } 
    printf("%.8f\n", s);
  }
}
