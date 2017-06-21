#include<iostream>
#include<vector>
using namespace std;

main(){
  int tcase; cin >> tcase;
  int s, t;
  
  for ( int i = 0; i < tcase; i++ ){
    cin >> s >> t;
    vector<int> v;
    if ( s < t ){
      for ( int i = s; i <= t; i++ ) v.push_back(i);
    } else if ( s > t ){
      if ( s <= 5 ){
	for ( int i = s; i >= t; i-- ) v.push_back(i);
      } else if ( s >= 6 ){
	for ( int i = s; i <= 9; i++ ) v.push_back(i);
	if ( t <= 5 ){
	  for ( int i = 5; i >= t; i-- ) v.push_back(i);
	} else if ( t >= 6 ){
	  for ( int i = 5; i >= 0; i-- ) v.push_back(i);
	  for ( int i = 1; i <= t; i++ ) v.push_back(i);
	}
      }
    }
    for ( int i = 0; i < v.size(); i++ ){
      if ( i ) cout << " ";
      cout << v[i];
    }
    cout << endl;
  }
}
