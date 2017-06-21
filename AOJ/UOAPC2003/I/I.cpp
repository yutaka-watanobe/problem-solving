#include <iostream>

#define REP(i,e) for(int i=0;i<(int)(e);i++)

using namespace std;

typedef basic_string<int> vint;

void out(vint &v){
  REP(i,v.size()) cout << v[i] << ' '; cout << endl;
}


vint riffle(vint &v,int c){
  vint::iterator p=v.begin()+v.size()/2;
  vint A(p,v.end()),B(v.begin(),p),C;

  while(A.size() || B.size()){
    //out(A); out(B); out(C); cout << endl;
    C+=A.substr(0,min(c,(int)A.size()));
    A.erase(0,min(c,(int)A.size()));
    C+=B.substr(0,min(c,(int)B.size()));
    B.erase(0,min(c,(int)B.size()));
  }

  return C;
}

main(){
  int n,r;
  while(cin >> n >> r && n && r){
    vint v(n,n);
    REP(i,n) v[i]=i;
    REP(i,r){
      int c;
      cin >> c;
      v=riffle(v,c);

    }

    cout << v[v.size()-1] << endl;
  }

}
