#include<iostream>
using namespace std;

int main(){
  int d;
  cin >> d;
  
  cout << d / 3600      << " ";
  cout << d % 3600 / 60 << " ";
  cout << d % 60        << endl;

  return 0;
}
