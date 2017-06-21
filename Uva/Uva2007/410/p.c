// @JUDGE_ID:  17051CA  410  C++
// @begin_of_source_code
/* シミュレーション 総当たり */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

int c, s;
int cap;
vector<int> S;
vector<int> minV;
double IMB;
double AM;
int SUM;

int read(){
  cin >> c >> s;
  if(cin.eof()) return false;
  SUM = 0;
  cap = c*2;
  S.clear();
  int k;
  for(int i=0; i<s; i++){
    cin >> k;
    SUM += k;
    S.push_back(k);
  }

  while(S.size()<cap) S.push_back(0);

  return true;
}

void rec(vector<int> used, vector<int> v, double imb, int t){
  if(imb>IMB) return;

  if(t==cap){
    if(imb<IMB){
      IMB = imb;
      minV = v;
    }
    return;
  }
  int s = -1;
  for(int i=0; i<cap; i++){
    if(!used[i]){s = i; break;}
  }
  
  v[t] = S[s];
  used[s] = 1;
  
  vector<int> tu, tv;
  double tm;

  for(int j=s+1; j<cap; j++){
    if(!used[j]){
      tu = used;
      tv = v;
      tm = imb;
      tv[t+1] = S[j];
      tu[j] = 1;
      double sum = (double)tv[t] + tv[t+1];
      tm += max(sum, AM) - min(sum, AM);
      rec(tu, tv, tm, t+2);
    }
  }
}

void work(){

  IMB = INT_MAX;
  AM = (double)SUM/c;

  vector<int> used(cap, 0);
  vector<int> v(cap, 0);

  rec(used, v, 0, 0);
  
  int m1, m2;
  for(int i=0; i<cap; i+=2){
    cout << " " << i/2 << ":";
    m1 = minV[i];
    m2 = minV[i+1];
    if(m1!=0) cout << " " << m1;
    if(m2!=0) cout << " " << m2;
    cout << endl;
  }

  cout << "IMBALANCE = ";
  printf("%.5lf\n", IMB);
}

main(){
  for(int i=1; read(); i++){
    cout << "Set #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
