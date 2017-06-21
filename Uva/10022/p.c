// @JUDGE_ID:  17051CA  10022  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

#define UP 0
#define DOWN 1

typedef unsigned long long ullong;

int search(ullong v1, ullong v2, ullong l1, ullong l2, ullong h1, ullong h2);

int search(ullong v1, ullong v2, ullong l1, ullong l2, ullong h1, ullong h2){
  ullong length = h2-h1;
  ullong start = v1-l1;
  ullong end = start+2*length;
  ullong target = v2-l2;
  ullong min = 1000000;

  for(ullong i=start+1; i<=end-1; i+=2){
    if(i>target){
      if(min>i-target) min = i-target;
    }else if(i<target){
      if(min>target-i) min = target-i;
    }else{
      min = 0;
    }
  }
  
  return min;
}

void work(){
  ullong  m, n, v1, v2, l1, l2, h1, h2;
  int direction1, direction2;

  cin >> m >> n;

  if(n==m){
    cout << 0 << endl;
    return;
  }else if(n>m){
    h1 = (ullong)floor(sqrt(m-0.1));
    h2 = (ullong)floor(sqrt(n-0.1));
    v1 = m;
    v2 = n;
  }else if(n<m){
    h1 = (ullong)floor(sqrt(n-0.1));
    h2 = (ullong)floor(sqrt(m-0.1));
    v1 = n;
    v2 = m;
  }

  if(h1==h2){
    if(v1>v2) cout << v1-v2 << endl;
    else cout << v2-v1 << endl;
    return;
  }


  if(h1%2==v1%2) direction1 = DOWN;
  else direction1 = UP;

  if(h2%2==v2%2) direction2 = DOWN;
  else direction2 = UP;

  l1 = h1*h1 + 1;
  l2 = h2*h2 + 1;

  ullong depthL = (h2*2+1) - (h1*2+1) - 1;
  if(direction1==UP){
    cout << depthL + search(v1, v2, l1, l2, h1, h2) << endl;;
  }else{
    int cost1 = search(v1+1, v2, l1, l2, h1, h2) + 1;
    int cost2 = search(v1-1, v2, l1, l2, h1, h2) + 1;
    if(cost1<cost2) cout << depthL + cost1 << endl;
    else cout << depthL + cost2 << endl;
  }

}


main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
