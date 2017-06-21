#include<iostream>
#include<cmath>
using namespace std;

#define MAX 20000

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    // 奇数を素数の候補とする
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    // 合成数でない奇数だけを残す
    for ( int i = 3; i <= limit; i += 2 ){
        if ( !prime[i] ) continue;
        for ( int j = i * i, k = i * 2; j <= n; j += k )
        prime[j] = false;
    }
}

main(){
  bool p[MAX+1];
  eratos(MAX, p);
  for ( int i = MAX - 100; i <= MAX; i++ ) {
    if ( p[i] ) cout << i << endl;
  }
}
