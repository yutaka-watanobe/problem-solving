#include<iostream>
using namespace std;

int main(){
  int i = 0, s, total = 0;
  while ( i < 10 ) {           // 繰り返し処理の範囲始まり 
    cin >> s;
    total += s;
    i++;
  }                            // 繰り返し処理の範囲終わり 
  cout << total << endl;
  return 0;
}
