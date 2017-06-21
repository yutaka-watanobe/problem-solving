// @JUDGE_ID:  17051CA  10490  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

long long P[32];
bool isP[32];

bool is_prime(long long k){
  if(k<2) return false;
  else if(k==2) return true;
  if(k%2 == 0) return false;
  for(long long i=3; i*i <= k; i+=2) if(k%i==0) return false;
  return true;
}

int n;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void init(){
  for(int i=1; i<=31; i++){
    if(is_prime((long long)pow(2, i)-1)){
      P[i] = (long long)pow(2, (i-1))*((long long)pow(2, i)-1);
    }else{
      P[i] = -1;
    }
    isP[i] = is_prime(i);
  }
}

void work(){
  
  if(P[n]>=0) cout << "Perfect: " << P[n] << "!" << endl;
  else if(P[n]==-1 && isP[n]) cout << "Given number is prime. But, NO perfect number is available." << endl;
  else{
    cout << "Given number is NOT prime! NO perfect number is available." << endl;
  }

  
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code

