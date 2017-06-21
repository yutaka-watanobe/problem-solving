#include<iostream>
using namespace std;

void gen(int N){
  int n = 3*N;
  int n1, n2, n3;

  cout << n << endl;
  for ( int i = 0; i < n; i+=3 ){
    n1 = i;
    n2 = i+1;
    n3 = i+2;
    
    if ( rand()%2 == 0 ){
      cout << n2 << " 2 " << n3 << " 2" << endl;
      cout << n1 << " 2 " << n3 << " 1" << endl;
      cout << n1 << " 2 " << n2 << " 1" << endl;
    } else {
      cout << n2 << " 2 " << n3 << " 1" << endl;
      cout << n1 << " 2 " << n3 << " 2" << endl;
      cout << n1 << " 1 " << n2 << " 2" << endl;
    }

  }
}

main(){
  gen(2);
  gen(3);
  gen(4);
  gen(5);
  gen(10);
  gen(20);
  gen(31);
  gen(32);
  gen(33);
  cout << 0 << endl;


}
