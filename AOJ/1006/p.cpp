#include<iostream>
#define MAX 1441
using namespace std;

int n, start, end;
int T[MAX];

int getValue( int x ){
  int h = x / 100;
  int m = x % 100;
  return h*60 + m;
}


void init(){
  for ( int i = 0; i < MAX; i++ ){
    T[i] = 0;
  }
}

void watch(int s, int e){
  for ( int i = s; i <= e; i++ ){
    T[i] = 1;
  }
}

bool read(){
  cin >> n >> start >> end;
  if ( n == 0 && start == 0 && end == 0 ) return false;
  start = getValue(start);
  end = getValue(end);

  int s,e,k;

  init();

  for ( int c = 0; c < n; c++ ){
    cin >> k;
    cin >> s;
    watch(start, getValue(s)-1);
    for ( int i = 0; i < k-1; i++ ){
      cin >> e >> s;
      watch(getValue(e), getValue(s)-1);
    }
    cin >> e;
    watch(getValue(e), end-1);
  }

  return true;
}

void work(){
  int sum = 0;
  int maxSum = 0;
  for ( int i = 0; i < MAX; i++ ){
    if ( T[i] == 1){
      sum++;
      if ( maxSum < sum ) maxSum = sum;
    } else {
      sum = 0;
    }
  }
  cout << maxSum << endl;
}

main(){
  while ( read() ){
    work();
  }
}
