// @JUDGE_ID:  17051CA  402  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<list>
#include<stl.h>

int N, X;
int card[20];

int read(){
  cin >> N;
  if(cin.eof()) return 0;
  
  cin >> X;

  for(int i=0; i<20; i++){
    cin >> card[i];
  }
  return 1;
}

void work(){
  int index;
  list<int> l;
  list<int>::iterator pos;

  if(N==1){
    cout << 1 << endl << endl;
    return ;
  }

  for(int i=0; i<N; i++){
    l.push_back(i+1);
  }
  int p = 0;
  index = 0;

  while(1){
    if(l.size()==X || p >= 20) break;

    index = index + card[p] -1;

    if(index >= l.size() ){
      index = 0;
      p++;
    }else{
      pos = l.begin();
      for(int i=0; i<index; i++) pos++;
      l.erase(pos);
    }
  }

  for(pos = l.begin(); pos != l.end(); ++pos){
    if(pos != l.begin()) cout << " ";
    cout << *pos;
  }
  cout << endl;
  cout << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Selection #" << i << endl;
    work();
  }
}
// @end_of_source_code
