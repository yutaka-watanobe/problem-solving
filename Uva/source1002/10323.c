// @JUDGE_ID:  17051CA  10323  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

typedef unsigned long long ullong;

int read();
void work();
void fac(ullong);

long long n;
ullong f;

ullong over; 
const ullong under = 10000;

int read(){
  cin >> n;
  if( cin.eof() ) return 0;
  else return 1;
}

void work(){
  f = 1;

  if( n==0 ) {
    f = 1;
    goto END;
  }
  if( n <= -2){
    f = 1;
    cout << n << " -2" << endl;
    goto END;
  }
  if( n == -1 ){
    cout << "Overflow!" << endl;
    return ;
  }

  fac(n);

 END:
  if( f > over ){
    cout << "Overflow" << f <<  endl;
  }else if( f < under ){
    cout << "Underflow" << f << endl;
  }else{
    cout << f << endl;
  }
}

void fac(ullong x){
  if( x == 1 ) return;
  if( f > over ) return;
  f = f*x;
  fac(x-1);
}

main(){
  /* ?????????????????????????????? */
  over = 1;
  over = over*62270208;
  over = over*100;
  /* ?????????????????????????????? */
  while(read()){
    work();
  }
}
// @end_of_source_code
