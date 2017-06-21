// @JUDGE_ID:  17051CA  10041  C++
// @begin_of_source_code
/* backtrack */
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

void work(){
  int street[505];
  int n;
  long d;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> street[i];
  }

  long min = INT_MAX;

  for(int i=0; i<n; i++){
    d = 0;
    /* left */
    for(int j=i-1; j>=0; j--){
      d += abs(street[i]-street[j]);
    }
    /* right */
    for(int j=i+1; j<n; j++){
      d += abs(street[i]-street[j]);
    }
    if(d < min) min = d;
  }
  
  cout << min << endl;
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
