#include<stdio.h>
#include<vector>
#include<iostream>

main(){
  vector<int> v;
  vector<int>::iterator it;
  int pos;

  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  
  it = v.begin() + 2;
  pos = 2;

  v.erase(v.begin()+2);
  cout << *it << "   " << v[pos] << endl;

  cout << endl;
}
