#include<iostream>
using namespace std;

main(){
  string D[] = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"};
  int x; cin >> x;
  cout << D[x%7] << endl;
}
