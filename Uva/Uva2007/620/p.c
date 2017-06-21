// @JUDGE_ID:  17051CA  620  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void work(){
  string line;
  cin >> line;

  int head, tail;
  head = 0;
  tail = line.size()-1;

  int type = 0;
  bool doCheck = false;

  while(1){
    if(line[head]=='B' && line[tail]=='A'){
      head++;
      tail--;
      if(!doCheck)type = 2;
      doCheck = true;
    }else if(tail > 1 && line[tail]=='B' && line[tail-1]=='A'){
      tail -= 2;
      if(!doCheck)type = 1;
      doCheck = true;
    }else if(head==tail && line[head]=='A'){
      if(!doCheck) type = 0;
      break;
    }else{
      if(!doCheck) type = 3;
      break;
    }
    if(tail <=head) break;
  }

  if( tail==head && line[head]=='A'){
    if(type==0){
      cout << "SIMPLE" << endl;
    }else if(type==1){
      cout << "FULLY-GROWN" << endl;
    }else if(type==2){
      cout << "MUTAGENIC" << endl;
    }else if(type==3){
      cout << "MUTANT" << endl;
    }
  }else{
    cout << "MUTANT" << endl;
  }

}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
