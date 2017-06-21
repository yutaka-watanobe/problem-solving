#include<iostream>
#include<algorithm>
using namespace std;
main(){
  int n;
  while( cin >> n && n ){
    int sum, x, maxv = 0, minv = (1<<20);
    for ( int i = 0; i < n; i++ ){
      sum = 0;
      for ( int j = 0; j < 5; j++ ){
	cin >> x; sum += x;
      }
      maxv = max(maxv, sum);
      minv = min(minv, sum);
    }
    cout << maxv << " " << minv << endl;
  }
}
