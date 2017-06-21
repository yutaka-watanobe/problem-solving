// @JUDGE_ID:  17051CA  446  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

void createBit( int a, vector<int> &bit, int l ){
  bit.clear();
  int next;
  while( 1 ){
    bit.push_back( a%2 );
    next = a/2;
    a = next;
    if(next==0 ) break;
  }

  while( bit.size() < l ){
    bit.push_back(0);
  }

  reverse(bit.begin(), bit.end());
}


void work(){
  int a, b;
  char c;
  vector<int> v1, v2;

  scanf("%x", &a);
  cin >> c;
  scanf("%x", &b);

  createBit(a, v1, 13);
  createBit(b, v2, 13);
  
  for(int i=0; i<v1.size(); i++){
    cout << v1[i];
  }
  cout << " " << c << " ";
  for(int i=0; i<v2.size(); i++){
    cout << v2[i];
  }

  cout << " = ";

  if(c=='+') cout << a + b <<endl;
  else cout << a - b << endl;
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
