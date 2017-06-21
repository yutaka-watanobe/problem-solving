#include<iostream>
#include<cstdlib>
using namespace std;

main(){
  int n = 100;
  for ( int i = 0; i < n ;i++ ){
    int a = rand()%1000;
    int b = rand()%1000;

    if ( rand()%2 ) a *= -1;
    if ( rand()%3 == 0 ) b *= -1;
    cout << a << " " << b << endl;
  }
}
