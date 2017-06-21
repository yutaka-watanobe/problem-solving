#include<iostream>
using namespace std;


void gen(){
  int n = 100;
  int m = n-1;
  int c = 8;
  int s = rand()%n + 1;
  int d = rand()%n + 1;

  cout << c << " " << n << " " << m << " " << s << " " << d << endl;
  for ( int i = 1; i <= 99; i++ ){
    cout << i << " " << i + 1 << " " << 1000+(rand()%20)*100 << endl;
  }

}

main(){
  for ( int i = 0; i < 10; i++ ) gen();
  cout << "0 0 0 0 0" << endl;
}
