#include<iostream>
#include<string>
#include<cassert>
#include<map>

using namespace std;

int getNumOfBlow(string num1,string num2){
  int re = 0;

  for(int i = 0;i<num1.size();i++)
    for(int j = 0;j<num2.size();j++)
      if(i != j && num1[i] == num2[j])
	re++;

  return re;
}

int getNumOfHit(string num1,string num2){
  int re = 0;

  for(int i = 0;i<num1.size();i++)
    re += (int)(num1[i] == num2[i]);

  return re;
}

bool isNotMultipleNum(string num){
  map<char,bool> isExist;

  for(int i = 0;i<num.size();i++){
    if(isExist[num[i]])
      return false;
    isExist[num[i]] = true;
  }
  
  return true;
}

main(){
  string num1, num2; 
  while(cin >> num1 >> num2 && num1 != "0"){
    assert(num1.size() == 4 && num2.size() == 4);
    assert(isNotMultipleNum(num1) && isNotMultipleNum(num2));
    cout << getNumOfHit(num1,num2) << " " << getNumOfBlow(num1,num2) << endl;
  }
  return 0;
}
    
