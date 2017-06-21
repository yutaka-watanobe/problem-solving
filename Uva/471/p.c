// @JUDGE_ID:  17051CA  471  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

string itoa(long long x){
  char a[20];
  
  sprintf(a, "%lld", x);

  return string(a);
}

long long n;

bool check(long long x){
  map<char, bool> used;
  string s = itoa(x);
  for(long i=0; i<s.size(); i++){
    if(used[s[i]]) return false;
    else used[ s[i] ] = true;
  }
  return true;
}

void work(){
  cin >> n;
  
  long long s1;
  long long s2 = 1;
  s1 = n;
  while(1){
    s1 = n*s2;
    if(s1 > 9999999999LL) return;
    if( check(s1) && check(s2) ){
      cout << s1 << " / " << s2 << " = " << n << endl;
    }
    s2++;
  }
}

main(){
  long testCase;
  cin >> testCase;
  for(long i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
