// @JUDGE_ID:  17051CA  10650  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stl.h>
#include<vector>
#define MAX 32001

class Determinate{
 public:
  int length, maxValue, dist;
  Determinate(){}
  Determinate(int length, int maxValue, int dist): length(length), maxValue(maxValue), dist(dist){}
  
  void setValues(int l, int m, int d ){
    length = l;
    maxValue = m;
    dist = d;
  }
};

class DeterminatePrime{
 public:
  bool prime[MAX+1];
  vector<int> pList;
  bool used[MAX+1];

  Determinate determinate[MAX];
  
  int x, y;

  void eratos(int n){
    pList.clear();
    prime[0] = prime[1] = false;
    fill(prime, prime+MAX, false);
    /* 奇数を素数候補とする */
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    /* 合成数でない奇数だけを残す */
    for ( int i = 3, limit = (int)sqrt(n); i <= limit; i += 2 ) {
      if ( !prime[i] ) continue;
      for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
    }
    for ( int i = 0; i < MAX; i++ ){
      if ( prime[i] ) pList.push_back(i);
    }
  }

  void init(){
    eratos( MAX );

    for( int p = 0; p < pList.size()-1; p++ ){
      determinate[ pList[p] ] = Determinate(0, 0, 0);
    }

    for( int p = 0; p < pList.size()-1; p++ ){
      int d = pList[p+1] - pList[p];
      int l = 0;
      int current = p;
      while(1){
	if ( pList[current+1] - pList[current] != d ) break;
	current++;
      }
      l = current - p + 1;

      for ( int i = 0; i < l; i++ ){
	if ( determinate[ pList[p+i] ].length > l ) continue;
	determinate[ pList[p+i] ].setValues(l, pList[current], d);
      }
    }
  }

  bool read(){
    int a, b;
    cin >> a >> b;
    if ( a == 0 && b == 0 ) return false;
    x = min( a, b );
    y = max( a, b );
    return true;
  }

  void work(){
    int maxV = 0;
    int cnt = 0;

    int mV, len, dist;
    for ( int i = x; i <= y; i++ ){
      if ( !prime[i] ) continue;

      Determinate det = determinate[i];
      dist = determinate[i].dist;
      mV = determinate[i].maxValue;
      len = determinate[i].length;

      if ( len < 3 ) continue;
      if ( mV > y ) continue;
      if ( (mV - i)/dist + 1 < len ) continue;

      for ( int p = i; p <= mV; p += dist ){
	if ( p != i ) printf(" ");
	printf("%d", p);
      }
      printf("\n");
    }
  }
};

main(){
  DeterminatePrime DP;
  DP.init();
  while ( DP.read() ){
    DP.work();
  }
}

// @end_of_source_code


