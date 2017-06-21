#include<stdio.h>
#include<iostream>
typedef unsigned long long ullong;

double power(double x, int n){
  double tmp = 1;

  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

ullong power(ullong x, int n){
  ullong tmp = 1;
  if( n > 0 ){
    tmp = power(x, n/2);
    tmp = (n%2)?tmp*tmp*x:tmp*tmp;
  }
  return tmp;
}

// 11718
llong power(llong x, llong n, llong m){
  llong tmp = 1;
  if( n > 0 ){
    tmp = power(x, n/2, m);
    tmp = (n%2)?(((tmp*tmp)%m)*x)%m:(tmp*tmp)%m;
  }
  return tmp;
}

main(){
  while(1){
    ullong x;
    int n;
    cin >> x >> n;
    if(cin.eof()) return 0;
    cout << power(x, n) << endl;
  }
}
