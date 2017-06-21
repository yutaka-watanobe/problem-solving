// @JUDGE_ID:  17051CA  10101  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

typedef unsigned long long ullong;
void init();
int kuti, lakh, hajar, shata;
void bangla(ullong, int);

void init(){
  kuti = 0;
  lakh = 0;
  hajar = 0;
  shata = 0;
}

main(){
  ullong input;
  int testCase = 1;

  while(1){
    cin >> input;
    if(cin.eof()) break;
    
    init();

    printf("%4d.", testCase);

    bangla(input, 0);

    cout << endl;

    testCase++;
  }
  return 0;
}

void bangla(ullong input, int kutiFlag){
  
  if( input == 0 ) {
    cout << " " << 0 ;
    return;
  }

  if( input/10000000 > 0 ){
      kuti = input/10000000;
      if(kuti>=100) {
	bangla(kuti, 1);
	kuti = -1;
      }
      input = input%10000000;
      if( kuti > 0 ) cout << " " <<kuti << " kuti";
  }

  if( input/100000 > 0 ){
    lakh = input/100000;
    input = input%100000;
    if( lakh > 0 ) cout << " " << lakh << " lakh";
  }

  if( input/1000 > 0 ){
    hajar = input/1000;
    input = input%1000;
    if( hajar > 0 ) cout << " " << hajar << " hajar";
  }

  if( input/100 > 0 ){
    shata = input/100;
    input = input%100;
    if( shata > 0 ) cout << " " << shata << " shata";
  }

  if( input > 0 ) cout << " " << input;
  if(kutiFlag ) {
    cout << " kuti";
  }
}
// @end_of_source_code
