#include<iostream>
using namespace std;

main(){
  int n;
  cin >> n;
  cout << n << endl;
  for ( int i = 0; i < n; i++ ){
    cout << rand()%10 << " " << rand()%10 << endl;
  }
}
