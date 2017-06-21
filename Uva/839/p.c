// @JUDGE_ID:  17051CA  839  C++
// @begin_of_source_code
/* Recursion */

#include<stdio.h>
#include<iostream>
#include<string>

string line;
bool ismobile;

int rec(){
  int Wl, Dl, Wr, Dr;
  cin >> Wl >> Dl >> Wr >> Dr;

  if(Wl==0) Wl = rec();
  if(Wr==0) Wr = rec();

  if(Wl*Dl!=Wr*Dr) ismobile = false;
  return Wl + Wr;

}

void work(){

  ismobile = true;
  rec();

  if(ismobile) cout << "YES" << endl;
  else cout << "NO" << endl;
}

main(){
  getline(cin, line);
  int t = atoi(line.c_str());

  for(int i=0; i<t; i++){
    if(i) cout << endl;
    work();
  }
  
}
// @end_of_source_code
