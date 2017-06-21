// @JUDGE_ID:  17051CA  755  C++
// @begin_of_source_code
/* Count + Mapping + Calculation */
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

int transrated[ 26 ];

class TelephoneNumber{
 public:
  map<int, int> M;

  void work(){
    map<int, int>::iterator pos;
    bool duplicated = false;

    for ( pos = M.begin(); pos != M.end(); pos++ ){
      int number = (*pos).first;
      int cnt = (*pos).second;
      if ( cnt > 1 ) {
	int pre = number / 10000;
	int post = number % 10000;
	if ( pre < 10 ) cout << "00";
	else if ( pre < 100 ) cout << "0";
	printf("%d-", pre );
	if ( post < 10 ) cout << "000";
	else if( post < 100 ) cout << "00";
	else if ( post < 1000 ) cout << "0";
	printf("%d %d\n", post, cnt );
	  
	duplicated = true;
      }
    }

    if ( !duplicated ){
      printf("No duplicates.\n");
    }
  }

  void getNumber(){
    char buffer[1000]; 
    char ch;
    int p = 1000000;
    int number = 0;

    scanf("%s", buffer );
    int len = strlen( buffer );

    for ( int i = 0; i < len; i++ ){
      ch = buffer[i];
      if ( isdigit( ch ) ) {
	number += p * ( ch - '0' );
	p /= 10;
      } else if ( ch != '-' ){
	number += p * transrated[ ch - 'A' ];
	p /= 10;
      } 
    }

    M[ number ]++;
  }

  void read(){
    int n;
    scanf("%d", &n );
    M.clear();

    for ( int i = 0; i < n; i++ ){
      getNumber();
    }
  }

};

void init(){
  transrated[0] = transrated[1] = transrated[2] = 2;
  transrated[3] = transrated[4] = transrated[5] = 3;
  transrated[6] = transrated[7] = transrated[8] = 4;
  transrated[9] = transrated[10] = transrated[11] = 5;
  transrated[12] = transrated[13] = transrated[14] = 6;
  transrated[15] = transrated[17] = transrated[18] = 7;
  transrated[19] = transrated[20] = transrated[21] = 8;
  transrated[22] = transrated[23] = transrated[24] = 9;
}

main(){
  init();
  TelephoneNumber TN;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    TN.read();
    TN.work();
  }
}


// @end_of_source_code


