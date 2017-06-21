#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void compute(int a, int b ){
  int mvalue = INT_MAX;
  for ( int i = 1; i*i <= a; i++ ){
    if ( a % i != 0 ) continue;
    for ( int j = 1; j*j <= b; j++ ){
      if ( b % j != 0 ) continue;
      int v[4];
      v[0] = i;
      v[1] = a / i;
      v[2] = j;
      v[3] = b / j;
      sort( v, v + 4 );
      int sum = 0;
      for ( int i = 1; i < 4; i++ ){
	int d =v[i] - v[i-1] ;
	  sum += d*d;
      }
      mvalue = min(mvalue, sum);
    }
  }
  cout << mvalue << endl;
}

int main(){
  int a, b;
  while( cin >> a >> b && a && b){
    compute(a, b);
  }
  return 0;
}
