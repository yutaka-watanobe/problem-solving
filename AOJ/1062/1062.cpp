#include<iostream>
#include<cassert>
#include<string>
using namespace std;

bool isOK(int C, int M){
  if ( M < C ) M += 60;
  return (M - C) <= 8;
}

void print(string str, int r, int n){
  if ( n == 0 ){
    cout << str << " no guest" << endl;
  } else {
    cout << str << " " << 100*r/n << endl;
  }
}

main(){
  int n, hh, mm, C, T;
  char ch;

  while( cin >> n, n){
    int nL, nD, nM, L, D, M;
    nL = nD = nM = L = D = M = 0;
    for ( int i = 0; i < n; i++ ){
      cin >> hh >> ch >> mm >> T;
      if ( hh <= 2 ) hh += 24;
      C = 60*hh + mm;
      if ( 660 <= C && C < 900 ){
	if ( isOK(mm, T) ) L++;
	nL++;
      } else if ( 1080 <= C && C < 1260 ){
	if ( isOK(mm, T) ) D++;
	nD++;
      } else if ( 1260 <= C && C < 1560){
	if ( isOK(mm, T) ) M++;
	nM++;
      }
    }

    print("lunch", L, nL);
    print("dinner", D, nD);
    print("midnight", M, nM);
  }
}
