// @JUDGE_ID:  17051CA  465  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>

string line;

int read(){
  getline(cin, line);
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  long long A1, A2;
  char op;

  sscanf(line.c_str(), "%lld %c %lld", &A1, &op, &A2);

  cout << line << endl;
  
  if(A1>INT_MAX) cout << "first number too big" <<endl;
  if(A2>INT_MAX) cout << "second number too big" <<endl;

  if(op=='+'){
    if(A1+A2>INT_MAX || A1>INT_MAX || A2>INT_MAX) cout << "result too big" << endl;
  }
  else if(op=='*'){
    if( (A1*A2>INT_MAX || A1>INT_MAX || A2>INT_MAX) && !(A1==0 || A2==0)) cout << "result too big" << endl;
  }

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
