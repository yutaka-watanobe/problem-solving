// @JUDGE_ID:  17051CA  437  C++
// @begin_of_source_code
/* LIS */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int lis(vector<int> &v){
  vector<int> l;
  l.resize(v.size());
  l[0] = 0;
  for(int i=0; i<v.size(); i++){
    int m = 0;
    for(int j=0; j<i; j++){
      if(v[j]<v[i] && m<l[j]){
	m = l[j];
      }
    }
    l[i] = m + 1;
  }

  return *max_element(l.begin(), l.end());
}

int n;
vector<pair<pair<int, int>, int> > B;

int read(){
  cin >> n;
  if ( n == 0 ) return 0;

  int x, y, z;
  B.clear();
  for ( int i = 0; i < n; i++ ){
    cin >> x >> y >> z;
    B.push_back( make_pair(make_pair(min(x, y), max(x, y)), z ));
    B.push_back( make_pair(make_pair(min(x, z), max(x, z)), y ));
    B.push_back( make_pair(make_pair(min(y, z), max(y, z)), x ));
  }

  sort ( B.begin(), B.end() );
  
  return 1;
}

void work(){
  vector<int> l;
  l.resize(B.size());
  l[0] = 0;

  for(int i=0; i<B.size(); i++){
    int m = 0;
    for(int j=0; j<i; j++){
      if(B[j].first.first < B[i].first.first &&
	 B[j].first.second < B[i].first.second && m<l[j]){
	m = l[j];
      }
    }
    l[i] = m + B[i].second;
  }

  cout << "maximum height = " << *max_element(l.begin(), l.end()) << endl;;
}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Case " << i << ": ";
    work();
  }
}
// @end_of_source_code
