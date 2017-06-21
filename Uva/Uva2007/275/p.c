// @JUDGE_ID:  17051CA  275  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

int a, b;

int read(){
  cin >> a >> b;
  if(a==0 && b==0) return 0;
  return 1;
}

void work(){
  int r;
  int q;
  int j;

  cout << ".";
  j = 1;

  map<int, int> mp;

  mp[a%b] = 1;

  int cnt = 1;
  int t = a;
  
  while(1){
    a *= 10;
    r = a%b;
    if(r==0){
      if(j>49){j=0; cout << endl;}
      j++;
      cout << a/b << endl;
      cout << "This expansion terminates." << endl;
      break;
    }else if(mp[r]>0 || r==t) {
      if(j>49){j=0; cout << endl;}
      j++;
      cout << a/b << endl;
      if(r==t) cnt++;
      cout << "The last " << cnt-mp[r] << " digits repeat forever." << endl;
      break;
    }
    if(j>49){j=0; cout << endl;}
    j++;
    cout << a/b; 
    mp[r] = cnt;
    a = r;
    cnt++;
  }

}

main(){
  while(read()){
    work();
    cout << endl;
  }
}
// @end_of_source_code
