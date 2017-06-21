#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define LIMIT 151200
main(){
  vector<int> s1, s2;
  int i = 0;
  while( i*i*i <= LIMIT ){ s1.push_back(i*i*i); i++; }
  i = 0;
  while( i*(i+1)*(i+2)/6 <= LIMIT ){ s2.push_back(i*(i+1)*(i+2)/6); i++; }

  int n, m;
  while( cin >> n && n ){
    m = 0;
    for ( int i = 0; i < s1.size(); i++ ){
      for ( int j = 0; j < s2.size(); j++ ){
	if ( s1[i] + s2[j] > n ) continue;
	m = max(m, s1[i] + s2[j] );
      }
    }
    cout << m << endl;
  }
}
