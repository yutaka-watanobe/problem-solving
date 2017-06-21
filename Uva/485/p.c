// @JUDGE_ID:  17051CA  485  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int read();
void work();

string add(string s1, string s2){
  int dif = s1.size() - s2.size();
  if(dif>0){
    for(int i=0;i<dif;i++){
      s2.insert(s2.begin(),'0');
    }
  }else{
    for(int i=0;i>dif;i--){
      s1.insert(s1.begin(),'0');
    }
  }

  int carry;
  char val;
  carry = 0;

  string sum = "";

  for(int i=s1.size()-1; i>=0; i--){
    val = s1[i] + s2[i] - '0' + carry;
    if(val>'9'){
      carry = 1;
      val -= 10;
    }else{
      carry = 0;
    }
    sum.insert(sum.begin(), val);
  }
  
  if(carry==1) sum.insert(sum.begin(),'1');

  return sum;
}

void work(){
  vector<string> v1, v2;
  v1.resize(1);
  v1[0] = "1";

  cout << "1" << endl;

  while(1){
    v2.resize(v1.size()+1);
    v2[0] = "1";
    cout <<  "1 ";
    bool f = false;
    for(int i=1; i<v2.size()-1; i++){
      v2[i] = add(v1[i] , v1[i-1]);
      if(v2[i].size()>= 61) {
	f = true;
      }
      cout << v2[i] << " "; 
    }
    v2[v2.size()-1] = "1";
    cout << "1";
    v1 = v2;
    cout << endl;
    if(f) return;
  }
}

main(){
  work();
}
// @end_of_source_code
