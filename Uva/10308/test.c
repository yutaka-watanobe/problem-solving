#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<stl.h>

main(){
  pair<int, int> key;
  map<pair<int, int>, string> mp;
  key.first = 1; key.second = 2;
  mp[key] = "test";
  cout << mp[key] << endl;
}
