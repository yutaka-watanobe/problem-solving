#include<iostream>
using namespace std;

int main(){
  int c1, c5, c10, c50, c100, c500, sum;
  cin >> c1 >> c5 >> c10 >> c50 >> c100 >> c500;

  sum = c1 + c5*5 + c10*10 + c50*50 + c100*100 + c500*500;

  if (sum >= 1000)  cout << 1 << endl;
  else cout << 0 << endl;

  return 0;
}
