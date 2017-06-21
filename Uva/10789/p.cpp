// prime number + count
#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#define MAX 2005

using namespace std;

bool prime[MAX];

void eratos( int n){

  fill(prime, prime+MAX, false);
  /* 奇数を素数候補とする */
  for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
  prime[2] = true;
  
  /* 合成数でない奇数だけを残す */
  for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
    if ( !prime[i] ) continue;
    
    for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
  }
}

void work(){
  int counter[255];

  for ( char i = '0'; i <= '9'; i++ ) counter[i] = 0;
  for ( char i = 'A'; i <= 'z'; i++ ) counter[i] = 0;

  string line; cin >> line;
  
  for ( int i = 0; i < line.size(); i++ ){
    counter[ line[i] ]++;
  }

  bool isEmpty = true;
  for ( char i = '0'; i <= '9'; i++ ) {
    if ( prime[counter[i]] ) { cout << i; isEmpty = false;}
  }
  for ( char i = 'A'; i <= 'z'; i++ ) {
    if ( prime[counter[i]] ) { cout << i; isEmpty = false;}
  }

  if ( isEmpty ) cout << "empty";
  cout << endl;

}

main(){
  eratos( MAX );
  int tcase; cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Case " << i << ": "; work();
  }
}
