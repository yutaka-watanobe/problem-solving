#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <numeric>

#include <cstdlib>
#include <cmath>
#include <cstdio>

#define REP(i,e) for(int i=0;i<(int)(e);i++)
#define FOR(i,b,e) for(int i=(int)(b);i<(int)(e);i++)
#define FORC(i,b,e,c) for(int i=(int)(b);i<(int)(e)&&(c);i++)

using namespace std;

typedef vector<int> vint;
typedef vector<string> vstring;
typedef vector<double> vdouble;
typedef long long ll;

void getNList(vint &v,string s){
  REP(i,s.length()) if(!isdigit(s[i]) && s[i]!='-') s[i]=' ';
  istringstream sin(s);
  int n;
  sin >> n;
  while(sin >> n) v.push_back(n);
}

void getIList(vint &v,string s){
  REP(i,s.length()) if(!isdigit(s[i]) && s[i]!='-') s[i]=' ';
  istringstream sin(s);
  int a,b,c;
  sin >> a >> b >> c;
  REP(i,a) v.push_back(b+c*i);
}

void getRList(vint &v,string s){
  REP(i,s.length()) if(!isdigit(s[i]) && s[i]!='-') s[i]=' ';
  istringstream sin(s);

  ll d;
  ll a,b,c;
  sin >> a >> b >> c >> d;
  REP(i,a){
    d*=17; d+=11; d&=0x00000000ffffffffll;
    v.push_back(d%(c-b+1)+b);
  }
}

main(){
  int n;
  int C=0;
  while(cin >> n && n){
    string line;
    cin >> line;
    vint v;
    REP(i,line.length()) if(line[i]=='+') line[i]=' ';
    istringstream lists(line);
    string l;
    while(lists >> l){
      if(l[0]=='N') getNList(v,l);
      if(l[0]=='I') getIList(v,l);
      if(l[0]=='R') getRList(v,l);      
    }


    sort(v.begin(),v.end());

    printf("Case %d: %d\n",++C,v[n-1]);
  }
}
