// @JUDGE_ID:  17051CA  106  C++
// @begin_of_source_code
/* ©Тою */

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int n;
int sumP, sumNP;
vector<int> n_used;

map<int, int> n_sumP;
map<int, int> n_sumNP;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void countNP(int xx, int yy, int zz){
  int x, y, z;
  x = xx;
  y = yy;
  z = zz;
  while(z<=n){
    sumNP += n_used[x];
    sumNP += n_used[y];
    sumNP += n_used[z];
    n_used[x] = n_used[y] = n_used[z] = 0;
    x+=xx; y+=yy; z+=zz;
  }
}

void create(){
  sumP = sumNP = 0;
  n_used.clear();
  n_used.resize(n+1, 1);

  int x, y, z;
  for(int b=1; 2*b*(b+1)+1<=n; b++){
    for(int a=b+1; (z=a*a+b*b)<=n; a+=2){
      if(gcd(a, b)!=1) continue;
      x = a*a - b*b;
      y =  2*a*b;
      sumP++;
      countNP(x, y, z);
    }
  }
  n_sumP[n] = sumP;
  n_sumNP[n] = sumNP;

  cout << sumP << " " << n - sumNP << endl;
}

void work(){
//  create();
   if(n_sumP[n]==0){
    create();
  }else{
    cout << n_sumP[n] << " " << n - n_sumNP[n] << endl;
  }
}
main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
