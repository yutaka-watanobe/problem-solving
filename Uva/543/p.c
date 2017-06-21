// @JUDGE_ID:  17051CA  543  C++
// @begin_of_source_code
/* аг©Т */
/* binary search */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

typedef unsigned long long ullong;

void eratos(ullong x, bit_vector &primes){
  ullong i, j;
  
  primes = bit_vector((x-1)/2, 1);
  
  for(i=3; i<=sqrt(x); i+=2)
    for(j=3; i*j<=x; j+=2)
      primes[(i*j-3)/2] = 0;
}


void eratos(ullong a, ullong b, vector<ullong> &p){
  bit_vector v;
  ullong i;
  
  if(a>b) swap(a, b);
  if(b<2) return;
  if(b==2){ p = vector<ullong>(1, 2); return; }
  
  eratos(b, v);
  
  if(a<=2){ p.push_back(2); a = 2; }
  for(i=(a-2)/2; i<=(b-3)/2; i++)
    if(v[i]) p.push_back(2*i+3);
}

vector<ullong> p;
int n;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  int a;
  for(int i=0; i<p.size(); i++){
    a = p[i];
    if(binary_search(p.begin()+i, p.end(), n-a)){
      cout << n << " = " << a << " + " << n-a << endl;
      return;
    }
  }

  cout << "Goldbach's conjecture is wrong." << endl;
    
}

main(){
  eratos(0, 1000000, p);

  while(read()){
    work();
  }
}
// @end_of_source_code
