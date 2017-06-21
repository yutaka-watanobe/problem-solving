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
  long d, dis[505];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> street[i];
    dis[i] = 0;
  }

  long min = INT_MAX;
  int tmp;
  for(int i=0; i<n; i++){
    d = 0;
    for(int j=i+1; j<n; j++){
      tmp = abs(street[i]-street[j]);
      d += tmp;
      dis[j] += tmp;
    }
    d += dis[i];
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
