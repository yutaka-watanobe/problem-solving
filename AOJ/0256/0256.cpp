#include<iostream>
using namespace std;

int main(){
  int i = 0, s, total = 0;
  while ( i < 10 ) {
    cin >> s;
    total += s;
    i++;
  }
  cout << total << endl;
  return 0;
}
