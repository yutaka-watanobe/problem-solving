#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int compute(string num){

  if ( num[0] == num[1] &&
       num[1] == num[2] &&
       num[2] == num[3] ) return -1;

  int cnt = 0;
  string L, S;
  while(1){
    if ( num == "6174" ) break;
    L = num;
    S = num;
    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());
    sort(S.begin(), S.end());
    int x = atoi(L.c_str()) - atoi(S.c_str());
    num[0] = '0' + x/1000; x %= 1000;
    num[1] = '0' + x/100; x %= 100;
    num[2] = '0' + x/10; x %= 10;
    num[3] = '0' + x;
    cnt++;
  }
  return cnt;
}

main(){
  string num;
  int tcase = 0;
  while(1){
    cin >> num;
    if ( num == "0000" ) break;
    tcase++;
    int a = compute(num);
    if ( a< 0 ) cout << "NA" << endl;
    else cout << a << endl;
  }
}
