// @JUDGE_ID:  17051CA  10326  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>
#include<math.h>

#define MAX 60
typedef long long llong;

int N;
llong p[MAX], p1[MAX], p2[MAX];

void init();
void initP12();
void set(llong );
int read();
void work();

void init(){
  for(int i=0; i<MAX; i++){
    p[i] = 0;
  }
}

void initP12(){
  for(int i=0; i<MAX; i++){
    p1[i] = 0;
    p2[i] = 0;
  }
}

int read(){
  if( scanf("%d", &N) == EOF ) return 0;
  else return 1;
}

void work(){
  if( N == 0 ){
    cout<< "+ 0 = 0" << endl;
    return;
  }

  init();
  llong a;
  cin >> a;
  a = 0 - a;
  p[1] = 1;
  p[0] = a;
  for(int i=1; i<N; i++){
    cin >> a;
    a = 0 - a;
    set(a);
  }

  for( int i=MAX-1; i>=1; i--){
    if( p[i] != 0 ){
      if( i == N ){
	if( p[i] != 1 && p[i] != -1){
	  if( p[i] >= 0 ) cout << p[i] << "x";
	  else cout << 0-p[i] << "x";
	}else cout << "x";
	if( i > 1 ) cout << "^" << i;
      }else{
	if( p[i] > 0 ){
	  cout << " + ";
	}else if(p[i] < 0 ){
	  cout << " - ";
	}
	if( p[i] != 1 && p[i] != -1){
	  if( p[i]>=0 ) cout << p[i] << "x";
	  else cout << 0-p[i] << "x";
	}else cout << "x";
	if( i > 1 ) cout << "^" << i;
      }
    }
  }
  if( p[0] >= 0 ) cout << " + ";
  else cout << " - ";
  if( p[0] >= 0 ) cout << p[0] << " = 0" << endl;
  else cout << 0-p[0] << " = 0" << endl;
}

void set(llong a){
  /* *x */
  initP12();
  for(int i=MAX-1; i>=0; i--){
    if( p[i] != 0 ){
      p1[i+1] = p[i];
    }
  }
  p1[0] = 0;
  /* *a */
  for(int i=0; i<MAX; i++){
    p2[i] = p[i]*a;
  }
  
  /* merge */
  for(int i=0; i<MAX; i++){
    p[i] = p1[i] + p2[i];
  }

}
main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
