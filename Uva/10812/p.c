// Simple calculation
#include<iostream>

using namespace std;

void work(){
  int n, d;
  cin >> n >> d;
  if ( n - d < 0 || (n + d) % 2 != 0 || (n - d) % 2 != 0 ){
    cout << "impossible" << endl;
  } else {
    cout << (n + d)/2 << " " << (n - d)/2 << endl;
  }

}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    work();
  }
}
