// @JUDGE_ID:  17051CA  440  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>


int n;
map<int, int> mp;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void parse(){
  int m = 2;
  
  vector<int> l, tmp;
  tmp.resize(n);
  for(int i=0; i<n; i++) tmp[i] = i+1;

  l = tmp;

  int index = -1;

  while(1){

    index = index + m -1;
    index = index%l.size();

    if(l[index]==2){
      if(l.size()==1) break;
      else{
	l = tmp;
	m++;
	index = 0-m+1;
      }
    }else{
      l.erase(l.begin()+index);
    }

  }
  mp[n] = m;
  cout << m << endl;
}

void work(){
  if(mp[n]==0) parse();
  else cout << mp[n] << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
