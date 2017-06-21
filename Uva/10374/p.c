// @JUDGE_ID:  17051CA  10374  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>

void work(){
  int k, m, id;
  string s1, s2;
  map<string, string> party;
  map<string, int> n_i;
  map<int, string> i_n;
  vector<int> v;
  v.resize(25, 0);

  getline(cin, s1);
  getline(cin, s1);

  k = atoi(s1.c_str());

  for(int i=0; i<k; i++){
    getline(cin, s1);
    getline(cin, s2);
    party[s1] = s2;
    n_i[s1] = i+1;
    i_n[i+1] = s1;
  }
  
  getline(cin, s1);
  
  m = atoi(s1.c_str());

  for(int i=0; i<m; i++){
    getline(cin, s1);
    v[ n_i[s1] ]++;
  }

  int max = -1;
  int mi;
  for(int i=1; i<v.size(); i++){
    if(max < v[i] ){
      max = v[i];
      mi = i;
    }
  }
  int cnt = 0;
  for(int i=0; i<v.size(); i++){
    if(v[i]==max) cnt++;
  }

  if(cnt>1) cout << "tie" << endl;
  else cout << party[ i_n[mi] ] << endl;


}

main(){
  int n;
  char buff[1000];
  cin.getline(buff, 1000);
  n = atoi(buff);
  for(int i=0; i<n; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
