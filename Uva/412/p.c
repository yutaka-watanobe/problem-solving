// @JUDGE_ID:  17051CA  412  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<stl.h>

/*
 * Greatest Common Divisor
 * requirement: a > b > 0 
 */
int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int n;
int v[51];

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  int k, cnt;
  for(int i=0; i<n; i++){
    cin >> k;
    v[i] = k;
  }

  sort(v, v+n-1);

  cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if( gcd( v[j], v[i] ) == 1) cnt++;
    }
  }

  if(cnt==0) cout << "No estimate for this data set." << endl;
  else{
    printf("%.6lf\n", sqrt((double)3*n*(n-1)/cnt) );
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
