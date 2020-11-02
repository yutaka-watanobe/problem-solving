#include<iostream>
using namespace std;

int main(){
  int t, n;
  int V[5] = {0, 6000, 4000, 3000, 2000};

  for ( int i = 0; i < 4; i++ ){
    cin >> t >> n;
    cout << V[t] * n << endl;
  }

  return 0;
}
