#include<iostream>
#include<vector>
using namespace std;

int m, n;
vector<int> w;

bool isStorable( int width ) {
  int row = 0, c = 0, i = 0;
  while ( i < n ) {
    if ( c + w[i] <= width ) {
      c += w[i];
      ++i;
    }
    else if ( ++row < m ) c = 0;
    else return false;
  }
  return true;
}

int main() {

  while ( cin >> m >> n && m && n ) {

    w.resize( n );
    for ( int i = 0; i < n; ++i ) cin >> w[i];

    int minw = 1;
    int maxw = 1500000;
    if ( !isStorable(maxw) ) cout << "NA" << endl;

    while ( maxw > minw ) {
      int mid = (maxw + minw) / 2;
      if ( isStorable(mid) ) maxw = mid;
      else                   minw = mid + 1;
    }

    cout << minw << endl;
  }
  return 0;
}
