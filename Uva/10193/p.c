// @JUDGE_ID:  17051CA  10193  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int getNum(string s){
  int p = 1;
  int sum = 0;
  reverse(s.begin(), s.end());
  for(int i=0; i<s.size(); i++, p*=2){
    if(s[i]=='1') sum += p;
  }
  return sum;
}
int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

void work(){
  string line1, line2;
  cin >> line1 >> line2;
  
  int s1, s2;
  s1 = getNum(line1);
  s2 = getNum(line2);

  int m = max(s1, s2);

  if(gcd(s1, s2)!=1){
    cout << "All you need is love!" << endl;
    return;
  }

  cout << "Love is not all you need!" << endl;
}

main(){
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    cout << "Pair #" << i << ": ";
    work();
  }
}
// @end_of_source_code
