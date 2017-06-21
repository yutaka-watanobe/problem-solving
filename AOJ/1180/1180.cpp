#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void simulate(string s, int l){
  string L, S;
  set<string> M;
  map<string, int> I;
  int b = 1;
  while( s.size() < l ) s = "0" + s;
  for ( int i = 0; i < l-1; i++ ) b *= 10;
  
  for ( int cur = 0; ; cur++ ){
    M.insert(s);
    I[s] = cur;
    L = S = s;
    sort(L.begin(), L.end(), greater<char>());
    sort(S.begin(), S.end());
    int x = atoi(L.c_str()) - atoi(S.c_str());
    for ( int i = 0, p = b; i < l; i++, p /= 10 ){
      s[i] = '0' + x/p;
      x %= p;
    }
    if ( M.find(s) != M.end() ) {
      cout << I[s] << " " << atoi(s.c_str()) << " " << cur - I[s]+1<< endl;
      break;
    }
  }
}

main(){
  string s;
  int l;
  while(1){
    cin >> s >> l;
    if ( s == "0" && l == 0 ) break;
    simulate(s, l);
  }
}
