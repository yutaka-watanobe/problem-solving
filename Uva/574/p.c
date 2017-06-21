// @JUDGE_ID:  17051CA  574  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<stl.h>
#include<vector>
#include<map>
#include<set>

int t, n;
vector<int> v;
vector<vector<int> > g;
map<int, int> cnt;

int read(){
  cin >> t >> n;
  if(n==0) return 0;
  v.resize(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  cnt = map<int, int>();
  set<int> s;

  for(int i=0; i<v.size(); i++){
    s.insert(v[i]);
    cnt[v[i]]++;
  }

  v.clear();
  v.resize(s.size());
  copy(s.begin(), s.end(), v.begin());

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  /* for(int i=0; i<v.size(); i++) cout << v[i] << " ";  */
/*   cout << endl;  */
/*   for(int i=0; i<v.size(); i++) cout << cnt[v[i]] << " ";  */
/*   cout << endl;  */
  
  return 1;
}

void rec(int s, int p, vector<int> path){
  if(p>v.size()) return;

  if(s==t){
    g.push_back(path);
    return;
  }

  if(s>t) return;

  vector<int> tmp;
  for(int i=0; i<=cnt[v[p]]; i++){
    tmp = path;
    for(int j=0; j<i; j++) tmp.push_back(v[p]);
    rec( s + (i*v[p]), p+1, tmp);
  }
}

void work(){
  g.clear();
  vector<int> tmp;

  rec(0, 0, tmp);

  if(g.size()==0){ cout << "NONE" << endl; return;}

  reverse(g.begin(), g.end());

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g[i].size(); j++){
      if(j!=0) cout << "+";
      cout << g[i][j];
    }
    cout << endl;
  }

}

main(){
  while(read()){
    cout << "Sums of " << t << ":" << endl;
    work();
  }
}
// @end_of_source_code
