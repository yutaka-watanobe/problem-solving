// @JUDGE_ID:  17051CA  147  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int coin[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned long long T[30001];
int doll, cent;
string line;

int read(){
  char op;
  string scent = "";

  cin >> doll >> op >> scent;
 
  //assert( op == '.' );

  if ( scent.size() == 1 ){
    cent = atoi( scent.c_str() ) * 10;
  } else if ( scent.size() ==2 ) {
    cent = atoi( scent.c_str() );
  } else {
    assert ( false );
  }

  if ( doll == 0 && cent == 0 ) return 0;
  return 1;
}

void work(){
  /* sscanf(line.c_str(), "%d.%d", &doll, &cent); */
  int money = 100*doll + cent;
  printf("%3d.", doll );
  if ( cent < 10 ) printf("0");
  printf("%d", cent );
  printf("%17lld\n", T[money] );
}

void init(){
  for(int i=0; i<=30000; i++) T[i] = 1;
  for(int k=1; k<11; k++){
    for(int n=coin[k]; n<=30000; n++){
      T[n] += T[n-coin[k]];
    }
  }
}

main(){
  init();
  while(read()){
    work();
  }
}

// @end_of_source_code
