// @JUDGE_ID:  17051CA  10140  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

void eratos(int x, bit_vector &primes){
  int i, j;
  
  primes = bit_vector((x-1)/2, 1);
  
  for(i=3; i<=sqrt(x); i+=2)
    for(j=3; i*j<=x; j+=2)
      primes[(i*j-3)/2] = 0;
}

void eratos(int a, int b, vector<bool> &p){
  bit_vector v;
  int i;
  
  if(a>b) swap(a, b);
  if(b<2) return;
  if(b==2){ p = vector<bool>(1, true); return; }
  
  eratos(b, v);
  
  if(a<=2){ p.push_back(2); a = 2; }
  for(i=(a-2)/2; i<=(b-3)/2; i++){
    if(v[i]) p.push_back(true);
    else p.push_back(false);
  }
}

vector<pair<int, int> > input;
int L, U;

int read(){
  cin >> L >> U;
  return cin.eof() ? false : true;
}

void work(){

  vector<bool> v;
  eratos(L, U, v);


//  for(int i=0; i<v.size(); i++) cout << i << " ";
//  cout << endl;
//  for(int i=0; i<v.size(); i++) cout << v[i] << " ";
//  cout << endl;


  pair<int, int> minP, maxP;
  int maxV, minV;
  int v1, v2;
  maxV = -1;
  minV = INT_MAX;
  for(int i=0; i<v.size()-1; i++){
    v1 = v[i]; v2 = v[i+1];
    if(v2-v1<minV){
      minV = v2-v1;
      minP.first = v1; minP.second = v2;
    }
    if(v2-v1>maxV){
      maxV = v2 - v1;
      maxP.first = v1; maxP.second = v2;
    }
  }


  if(maxV == -1 && minV == INT_MAX){
    cout << "There are no adjacent primes." << endl;
  }else{
    cout << minP.first << "," << minP.second << " are closest, ";
    cout << maxP.first << "," << maxP.second << " are most distant." << endl;
  }

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
