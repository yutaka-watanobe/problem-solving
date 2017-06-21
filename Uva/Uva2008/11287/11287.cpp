#include<iostream>
#include<cmath>
using namespace std;
typedef long long llong;

bool isPrime(llong k){
  if(k<2) return false;
  else if(k==2) return true;
  if(k%2 == 0) return false;
  for(int i=3; i*i <= k; i+=2) if(k%i==0) return false;
  return true;
}

llong power(llong x, llong n, llong p){
  llong tmp = 1;

  if(n>0){
    tmp = power(x, n/2, p)%p;
    if(n%2==0) tmp = tmp*tmp%p;
    else tmp = ((tmp*tmp)%p)*x%p;
  }
  return tmp;
}

main(){
  llong p, a; 
  while(1){
    cin >> p >> a;
    if ( p == 0 && a == 0 ) break;
    cout << ((power(a, p, p) == a && !isPrime(p) ) ? "yes" : "no") << endl;
  }
}
