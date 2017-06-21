// @JUDGE_ID:  17051CA  394  C++
// @begin_of_source_code
/* シミュレーション */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

class Mapmaker{
 public:
  int B, CD, D;
  vector<int> L, U, C;
  Mapmaker(){}
  Mapmaker(int b, int cd, int d, vector<int> l, vector<int> u){
    B = b;
    CD = cd;
    D = d;
    L = l;
    U = u;
    makeC();
  }
  
  void makeC(){
    C.resize(D+1);
    C[0] = -1;

    C[D] = CD;
    for(int d=D-1; d>=1; d--){
      C[d] = C[d+1]*(U[d+1]-L[d+1]+1);
    }

    C[0] = B;
    for(int d=1; d<=D; d++){
      C[0] -= C[d]*L[d];
    }
  }
  
};

int N, R;
map<string, Mapmaker> mp;

int read(){
  int B, CD, D, l, u;
  vector<int> U, L;
  string name;
  cin >> N >> R;
  for(int i=0; i<N; i++){
    cin >> name >> B >> CD >> D;
    U.clear(); L.clear();
    U.push_back(-1); L.push_back(-1);
    for(int j=0; j<D; j++){
      cin >> l >> u;
      L.push_back(l);
      U.push_back(u);
    }
    Mapmaker m = Mapmaker(B, CD, D, L, U);
    mp[name] = m;
  }
}

void MapmakerMake(string name){
  vector<int> A;
  Mapmaker m = mp[name];
  A.push_back(-1);
  int k;
  for(int j=0; j<m.D; j++){
    cin >> k;
    A.push_back(k);
  }
  
  int v;
  v = m.C[0];

  for(int i=1; i<=m.D; i++){
    v += m.C[i]*A[i];
  }

  cout << name << "[";
  for(int i=1; i<=m.D; i++){
    if(i!=1) cout << ", ";
    cout << A[i];
  }
  cout << "] = " << v << endl;
}

void work(){
  vector<int> A;
  string name;
  for(int i=0; i<R; i++){
    cin >> name;
    MapmakerMake(name);
  }
}

main(){
  read();
  work();
}
// @end_of_source_code
