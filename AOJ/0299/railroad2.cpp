#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, p;
vector<int> dst;

int CWDist (int s, int e) { return (e - s + n) % n; }
int CCWDist (int s, int e) { return (s - e + n) % n; }

int CWNext ( int i ) { return i == m - 1 ? dst[0] : dst[i + 1]; }
int CCWNext ( int i ) { return i == 0 ? dst[m - 1] : dst[i - 1]; }

int CWTurn ( int p, int t, int e ) { return CWDist(p, t) + CCWDist(t, e); }
int CCWTurn ( int p, int t, int e ) { return CCWDist(p, t) + CWDist(t, e); }

int main() {
  cin >> n >> m >> p;
  dst.resize( m );
    
  for ( int i = 0; i < m; ++i ) cin >> dst[i];
  sort(dst.begin(), dst.end());

  int s = 0;
  while ( s < m ) {
    if ( dst[s] > p ) break;
    ++s;
  }
    
  int cwNext  = s == m ? dst[0] : dst[s];
  int ccwNext = s == 0 ? dst[m - 1] : dst[s - 1];
  int dist = min(CCWDist(p, cwNext), CWDist(p, ccwNext));

  for ( int i = 0; i < m; ++i ) {
    dist = min(dist, CWTurn(p, dst[i], CWNext(i)));
    dist = min(dist, CCWTurn(p, dst[i], CCWNext(i)));
  }

  cout << 100 * dist << endl;
  return 0;
}
