// @JUDGE_ID:  17051CA  10131  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<map>

void lis(vector<int> &l, vector<int> &id, vector<int> &x){
  vector<int> p(x.size());
  vector<int> t(x.size());
  int mi = 0;

  p[0] = 1;
  t[0] = -1;

  for(int i=1; i<x.size(); i++){
    int m = 1, mj = -1;
    
    for(int j=0; j<i; j++){
      if(x[i]>x[j] && m<p[j]+1){
	m = p[j]+1;
	mj = j;
      }
    }
    p[i] = m;
    t[i] = mj;
    if(p[i]>p[mi]) mi = i;
  }

  l.clear();
  id.clear();
  for(int i=mi; i>=0; i=t[i]) {
    l.push_back(x[i]);
    id.push_back(i);
  }
//  reverse(l.begin(), l.end());
//  reverse(id.begin(), id.end());
}


void work(){
  int w, q;
  pair<int, int> p;
 
  map<pair<int, int>, int> index;

  vector<pair<int, int> > v;

  int i = 1;

  while(1){
    cin >> w >> q;
    if(cin.eof()) break;
    p.first = w; p.second = q;
    index[p] = i++;
    v.push_back(p);
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  vector<int> iq, iqi, iql;
  for(int i=0; i<v.size(); i++){
    p = v[i];
    iq.push_back(p.second);
  }

  lis(iql, iqi, iq);

  cout << iqi.size() << endl;
  for(int i=0; i<iqi.size(); i++){
    p = v[ iqi[i] ];
    cout << index[p] << endl;
  }
  
}

main(){
  work();
}
// @end_of_source_code



