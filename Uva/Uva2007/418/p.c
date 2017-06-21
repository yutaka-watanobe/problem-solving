// @JUDGE_ID:  17051CA  418  C++
// @begin_of_source_code
/* Search Max Value Recursion */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<string> S;
string s1, s2, s3, s4;
int max_area;
int s1_1, s1_2, s2_1, s2_2, s3_1, s3_2, s4_1, s4_2;

void cross1();
void cross2();
void cross3();

int read(){
  
  S.resize(4);
  for ( int i = 0; i < 4; i++ ){
    S[i].resize(12);
  }
  
  for ( int i = 0; i < 12; i++ ){
    cin >> S[0][i];
    if ( i == 0 && S[0][0] == 'Q' ) return false;
  }
  for ( int i = 1; i <= 3; i++ ){
    for ( int j = 0; j < 12; j++ ) cin >> S[i][j];
  }

  return 1;
}

void cross1(){
  for ( int i = 1; i < 11; i++ ){
    for ( int j = 1; j < 11; j++ ){
      if ( s1[i] == s2[j] ){
	s1_1 = i; s2_1 = j;
	cross2();
      }
    }
  }
}

void cross2(){
  for ( int i = s2_1+1; i < 11; i++ ){
    for ( int j = 1; j < 11; j++ ){
      if ( s2[i] == s3[j] ){
	s2_2 = i; s3_1 = j;
	cross3();
      }
    }
  }
}

void cross3(){
  int i1 = s1_1 + 1;
  int i2 = s3_1 + 1;
  int  w = s2_2 - s2_1;
  int h = 0;
  for ( ; i1 < 11 && i2 < 11; i1++, i2++ ){
    for ( int j = 1; j+w < 11; j++ ){
      if ( s4[j] == s1[i1] && s4[j+w] == s3[i2] ){
	max_area = max( max_area, (w-1)*(h) );
      }
    }
    h++;
  }

}

void work(){
  sort ( S.begin(), S.end() );

  max_area = 0;

  do {
    s1 = S[0];
    s2 = S[1]; 
    s3 = S[2];
    s4 = S[3];

    cross1();
    
  }while ( next_permutation( S.begin(), S.end() ) );

  cout << max_area << endl;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
