#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve(string N){
  if ( N[0] == N[1] && N[1] == N[2] && N[2] == N[3] ) {
    cout << "NA" << endl; return;
  }
  int cnt = 0;
  string L, S;
  for(; N != "6174"; cnt++ ){
    L = S = N;
    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());
    sort(S.begin(), S.end());
    int num = stoi(L.c_str()) - stoi(S.c_str());
    N = to_string(num);
    while( N.size() < 4 ) N = '0' + N;
  }
  cout << cnt << endl;
}

int main(){
  string N;
  while(1){
    cin >> N;
    if ( N == "0000" ) break;
    solve(N);
  }
  return 0;
}
