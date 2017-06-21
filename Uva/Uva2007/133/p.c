// @JUDGE_ID:  17051CA  133  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n, k, m;

int read(){
  cin >> n >> k >> m;
  if(n==0 && k==0 && m==0) return 0;
  return 1;
}

void work(){
  vector<int> v;
  int p1, p2;

  v.resize(n);
  for(int i=0; i<n; i++) v[i] = i+1;
  p1 = 0; 
  p2 = n-1;

  while(v.size()>0){
    
    /*
    p1 += k;
    p1 = p1%v.size();
    p2 -=  m;
    p2 = (0-p2)%v.size();
    */

    for(int j=0; j<k-1; j++){
      p1++;
      if(p1 == v.size()) p1 = 0;
    }

    for(int j=0; j<m-1; j++){
      p2--;
      if(p2 == -1 ) p2 = v.size()-1;
    }

    printf("%3d", v[p1]);
    if(p1!=p2) printf("%3d", v[p2]);

    if(p1==p2){
      v.erase(v.begin()+p1);
      if(p1 >= v.size()) p1 = 0;
    }else if(p2 < p1){
      v.erase(v.begin()+p2);
      p1--;
      v.erase(v.begin()+p1);
      if(p1 >= v.size()) p1 = 0;
    }else if(p1 < p2){
      v.erase(v.begin()+p1);
      p2--;
      v.erase(v.begin()+p2);
    }
    p2--;
    if(p2 == -1) p2 = v.size()-1;

    if(v.size()>0) cout << ",";
  }
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
