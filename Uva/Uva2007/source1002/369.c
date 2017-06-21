// @JUDGE_ID:  17051CA  369  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

typedef unsigned long long ullong;

int N[101];
int M[101];

int n, m, inN, inM;

void init();
void dev(int );
ullong prodN();
ullong prodM();
int gcd(int ,int);

void init(){
  for(int i=0; i<101; i++){
    N[i] = 1;
    M[i] = 1;
  }
}

main(){
  
  while(1){
    scanf("%d %d", &inN, &inM);
    if( inN == 0 && inM == 0 ) break;
    init();

    if( inN-inM <= inM ){
      m = inN - inM;
    }else{
      m = inM;
    }
    n = inN;

    int nn = n;
    int mm = m;
    for(int i=0; i<m; i++){
      N[i] = nn--;
    }

    for(int i=0; i<m; i++){
      M[i] = mm--;
    }

    for(int i=0; i<m; i++){
      dev( i );
    }

    cout << inN << " things taken " << inM << " at a time is " << prodN()/prodM() << " exactly." << endl;
  }
  return 0;
}

void dev(int i){
  for(int j=0; j<n; j++){
    int g = gcd(N[j], M[i]);
    N[j] = N[j]/g;
    M[i] = M[i]/g;
  }

}

ullong prodN(){
  ullong p = 1;
  for(int i=0; i<n; i++){
    p *= N[i];
  }
  return p;
}

ullong prodM(){
  ullong p = 1;
  for(int i=0; i<m; i++){
    p *= M[i];
  }
  return p;
}

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b, a%b);
}

// @end_of_source_code
