// @JUDGE_ID:  17051CA  457  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int DNA[10];
int dish[40], next[40];

void read(){
  for(int i=0; i<10; i++){
    cin >> DNA[i];
  }
}

void printDish(){
  for(int i=0; i<40; i++){
    if(dish[i]==0) cout << " ";
    else if(dish[i]==1) cout << ".";
    else if(dish[i]==2) cout << "x";
    else if(dish[i]==3) cout << "W";
  }
  cout << endl;
}

void work(){

  for(int i=0; i<40; i++) dish[i] = 0;
  dish[19] = 1;
  
  int left, right, k;

  for(int i=0; i<50; i++){

    printDish();

    for(int j=0; j<40; j++){

      if(j-1 < 0 ) left = 0;
      else left = dish[j-1];
      if(j+1 >= 40) right = 0;
      else right = dish[j+1];
      k = dish[j] + left + right;
      next[j] = DNA[k];
    }
    dish = next;
  }
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
