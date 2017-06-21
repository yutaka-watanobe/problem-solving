#include<iostream>
#include<algorithm>
using namespace std;

int cnt;
int n, c;

void rec(int pos, int b ){
  if ( b == c ){
    cnt++;
    return;
  }
  if ( pos >= n ) return;

  rec( pos+1, b+1);
  rec( pos+1, b);
}

main(){
  cnt = 0;
  cin >> n >> c;
  rec(0, 0);
  cout << cnt << endl;
}
