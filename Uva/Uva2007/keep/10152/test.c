#include<stdio.h>
#include<vector>
#include<iostream>
#include<stl.h>
main(){
  vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(5);
  v.push_back(4);

  sort ( v.begin(), v.end(), less<int>() );
  for ( int i = 0; i < v.size() ; i++ ){
    cout << v[i] << " ";
  }
  cout << endl;
  sort ( v.begin(), v.end(), greater<int>() );

  for ( int i = 0; i < v.size() ; i++ ){
    cout << v[i] << " ";
  }
cout << endl;
}
