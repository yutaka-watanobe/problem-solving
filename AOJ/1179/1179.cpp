#include<iostream>
using namespace std;

int compute(int y, int m, int d){
  int sum = 1;
  for ( int i = y+1; i < 1000; i++ ) sum += (i%3==0)?(10*20):(5*19+5*20);
  for ( int i = m+1; i <= 10; i++ ) {
    if ( y%3 == 0 ) sum += 20;
    else  sum += (i%2)?20:19;
  }
  if ( y%3 == 0 ) sum += 20-d;
  else sum += (m%2)?(20-d):(19-d);
  return sum;
}

main(){
  int n, y, m, d; cin >> n;
  for ( int i = 0; i < n; i++ ){
    cin >> y >> m >> d;
    cout << compute(y, m, d) << endl;
  }
}
