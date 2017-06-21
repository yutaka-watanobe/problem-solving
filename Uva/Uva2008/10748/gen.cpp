#include<iostream>
using namespace std;

void pri(int n){
  cout << n << endl;

  for ( int i = 0; i < n; i++ ){
    int x = rand()%1000000000;
    int y = rand()%1000000000;

    if ( rand()%3 == 0 || rand()%7 == 0 ) x *= -1;
    if ( rand()%5 == 0 || rand()%11 == 0 ) y *= -1;
    cout << x << " " << y << " " << 25 + rand()%25 << endl;
  }


}

main(){

  pri(20);
  pri(23);
  pri(24);
  pri(30);
  pri(30);
  pri(30);
  pri(30);
  pri(30);
  cout << 0 << endl;
}
