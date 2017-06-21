// @JUDGE_ID:  17051CA  573  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int H, U, D, F;

int read(){
  cin >> H >> U >> D >> F;
  if(H==0) return 0;
  return 1;
}

void work(){
  int day = 0;
  bool success;

  double h, clim;
  h = 0;
  const double fac = U*F/100.0;

  while(1){
    clim = U - day*fac;

    if(clim>0) h = h + clim;
    
    if(h > H ){
      success = true;
      break;
    }

    h -= D;

    if(h<0){
      success = false;
      break;
    }
    
    day++;
  }

  if(success) cout << "success on day " << day+1 << endl;
  else cout << "failure on day " << day+1 << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
