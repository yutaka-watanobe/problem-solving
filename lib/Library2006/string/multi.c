#include<stdio.h>
#include<string>

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

string multi(string s, char c){
  string result;
  char up, val;
  int carry = 0;
  int mul;

  for(int i=s.size()-1; i>=0; i--){
    mul = (s[i]-'0')*(c-'0');
    up = '0'+(mul/10);
    val = '0'+(mul%10) + carry;
    if(val>'9'){
      up++;
      val-=10;
    }
    carry = up - '0';
    result.insert(result.begin(), val);
  }
  if(carry!=0){
    result.insert(result.begin(), '0'+carry);
  }
  return result;
}

string multi(string s1, string s2){

  int seg = 0;
  if(s1[0]=='-') {seg++; s1.erase(s1.begin());}
  if(s2[0]=='-') {seg++; s2.erase(s2.begin());}

  bool minus;
  if(seg%2==0) minus = false;
  else minus = true;

  string result = "0";

  for(int i=s2.size()-1; i>=0; i--){
    string r = multi(s1, s2[i]);
    for(int j=0; j<s2.size()-i-1; j++){
      r += '0';
    }
    result = add(result, r);
  }

  if(minus) result.insert(result.begin(), '-');
  return result;
}



main(){

  string s1, s2;
  char c;

  cin >> s1 >> s2;

  cout << multi(s1, s2) << endl;



}
