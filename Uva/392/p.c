// @JUDGE_ID:  17051CA  392  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int A[9];

int read(){
  for(int i=0; i<9; i++){
    cin >> A[i];
    if(cin.eof()) return 0;
  }
  return 1;
}

void work(){
  bool isFirst = true;
  int zero = 0;

  for(int i=0; i<9; i++){
    int c = A[i];
    if(c!=0){
      if(isFirst){
	if(c<0) cout << "-";
	isFirst = false;
      }else{
	if(c>0) cout << " + ";
	else cout << " - ";
      }
      
      if(i<8 && abs(c)!=1) cout << abs(c);
      if(i==8) cout << abs(c);

      if(i!=8) cout << "x";
      if(i!=8 && 8-i>1) cout << "^" << 8-i;
    }
    if(c==0) zero++;
  }

  if(zero==9) cout << "0";

  cout << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
