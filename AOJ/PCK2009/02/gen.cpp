#include<iostream>
using namespace std;

void gen(){
  int M = 1000000;
  int L = (rand()%M + rand()%M+rand()%M+rand()%M+rand()%M)%1000000;

  cout << L << endl;
  for ( int i = 0; i < 12; i++ ){
    int N = rand()%40000;
    int M = N + rand()%30000;
    cout << M << " " << N << endl;
  }
}

main(){
  for ( int i = 0; i < 500; i++ ) gen();
  cout << 0 << endl;
}
