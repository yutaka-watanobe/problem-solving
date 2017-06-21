// @JUDGE_ID:  17051CA  10015  C++
// @begin_of_source_code
/* 素数 シミュレーション */
/* コーチのエラトステネスを使用 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

/* 
 * エラトステネスの篩 version 1 (The sieve of Eratosthenes)
 * 閉区間[3, x], x>=3, 内の奇数が素数かどうかをvector<bool>に入れる。
 * primes[i] == true が 2*i+3 が素数であることを表す。
 * 要件: なし
 */
void eratos(int x, bit_vector &primes){
  int i, j;
  
  primes = bit_vector((x-1)/2, 1);
  
  for(i=3; i<=sqrt(x); i+=2)
    for(j=3; i*j<=x; j+=2)
      primes[(i*j-3)/2] = 0;
}

/*
 * エラトステネスの篩 version 2 (The sieve of Eratosthenes)
 * 閉区間[min(a, b), max(a, b)], a, b>0, 内の素数をvector<ulong>に入れる。
 * 要件: 関数 eratos (version 1)
 */
void eratos(int a, int b, vector<int> &p){
  bit_vector v;
  int i;
  
  if(a>b) swap(a, b);
  if(b<2) return;
  if(b==2){ p = vector<int>(1, 2); return; }
  
  eratos(b, v);
  
  if(a<=2){ p.push_back(2); a = 2; }
  for(i=(a-2)/2; i<=(b-3)/2; i++)
    if(v[i]) p.push_back(2*i+3);
}

int n;
vector<int> prime;

int read(){
  cin >> n;
  return n==0 ? false : true;
}

void init(){
  eratos(2, 35000, prime);
}

void work(){
  vector<int> v;
  v.resize(n);
  for(int i=0; i<n; i++) v[i] = i+1;

  int index = 0;
  int pos = 0;
  while(1){
    if(v.size()==1) break;
    pos = pos + prime[index++]-1;
    pos = pos%v.size();
    v.erase(v.begin()+pos);
  }

  cout << v[0] << endl;
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code


