// @JUDGE_ID:  17051CA  413  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define NON 0
#define UP 1
#define DOWN 2

vector<int> v;

int read(){
  v.clear();

  int k;
  cin >> k;
  if(k==0) return 0;
  v.push_back(k);
  while(1){
    cin >> k;
    if(k==0) break;
    v.push_back(k);
  }
  return 1;
}

void work(){
  int pre, upLen, downLen, upSum, downSum;
  int state1, state2;
  
  vector<int> up, down;

  pre = v[0];
  state1 = state2 = NON;
  upLen = downLen = 0;
  upSum = downSum = 0;
  for(int i=1; i<v.size(); i++){
    int k = v[i];
    /* up sequence */
    if(pre==k && state1!= DOWN){
      upLen++;
    }else if(pre<k){
      upLen++;
      state1 = UP;
    }else if(pre>k){
      if(upLen>0 && state1==UP) {up.push_back(upLen); upSum += upLen;}
      upLen = 0;
      state1 = DOWN;
    }

    if(i==v.size()-1){
      if(upLen>0 && state1==UP){ up.push_back(upLen); upSum += upLen;}
    }

     /* down sequence */
    if(pre==k && state2!= UP){
      downLen++;
    }else if(pre>k){
      downLen++;
      state2 = DOWN;
    }else if(pre<k){
      if(downLen>0 && state2==DOWN){ down.push_back(downLen); downSum += downLen;}
      downLen = 0;
      state2 = UP;
    }

    if(i==v.size()-1){
      if(downLen>0 && state2==DOWN) {down.push_back(downLen); downSum += downLen;}
    }

    pre = k;
  }

  double upA, downA;
  if(up.size()==0) upA = 0;
  else upA = 1.0*upSum/up.size();

  if(down.size()==0) downA = 0;
  else downA = 1.0*downSum/down.size();

  cout << "Nr values = " << v.size() << ":  ";
  printf("%.6f %.6f\n", upA, downA);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
