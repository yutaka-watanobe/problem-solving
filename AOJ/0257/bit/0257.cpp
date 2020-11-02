#include<iostream>
using namespace std;

int main(){
  int st = 0;
  int b;
  for ( int i = 0; i < 3; i++ ){
    cin >> b;
    if ( b == 1 ) st += (1<<i);
  }
  if ( st >= 3 ) cout << "Open" << endl;
  else cout << "Close" << endl;
  return 0;
}
