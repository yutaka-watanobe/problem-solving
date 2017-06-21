// @JUDGE_ID:  17051CA  493  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
/*
 * a > b > 0 を保証すること。
 */
int gcd(int a, int b){
  int tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    
    tmp = a;
    a = b;
    b = tmp;
  }
  return a;
}
/**
 * かなり遅いがシンプル
 */
bool is_prime(int k){
  if(k<2) return false;
  else if(k==2) return true;
  if(k%2 == 0) return false;
  for(int i=3; i*i <= k; i+=2) if(k%i==0) return false;
  return true;
}

int n;
int MAX;
vector<int> inlist;
vector<pair<int, int> > v;

void init(){
  v.push_back(pair<int, int>(1, 1));
  v.push_back(pair<int, int>(0, 1));
  v.push_back(pair<int, int>(-1, 1));

  bool neg;
  bool isP;
  int a, b, i, j;
  int g;
  a = 1;
  b = 2;
  while(1){
    isP = is_prime(b);
    /* top left area */
    for(i=a; i>=1; i--){
      j = b;
      if(isP || gcd(i, j)==1){
	v.push_back(pair<int, int>(-j, i));
      }
    }
    
    /* top right area 1 */
    for(i=1; i<b; i++){
      j = b;
      if(isP || gcd(i, j)==1){
	v.push_back(pair<int, int>(j, i));
      }
    }
      
    /* top right area 2 */
    for(j=a; j>=1; j--){
      i = b;
      if(isP || gcd(i, j)==1){
	v.push_back(pair<int, int>(j, i));
      }
    }

    /* bottom right area */
    for(j=1; j<b; j++){
      i = b;
      if(isP || gcd(i, j)==1){
	v.push_back(pair<int, int>(-j, i));
      }
    }
    
    if(v.size()>MAX) break;

    a++; b++;
  }
  
}

void read(){
  int k;
  MAX = 5;
  while(1){
    cin >> k;
    if(cin.eof()) return;
    MAX = max(MAX, k);
    inlist.push_back(k);
  }
}

void work(int m){
  cout << v[m].first << " / " << v[m].second << endl;
}

main(){
  read();
  init();
  for(int i=0; i<inlist.size(); i++){
    work(inlist[i]);
  }
}
// @end_of_source_code
