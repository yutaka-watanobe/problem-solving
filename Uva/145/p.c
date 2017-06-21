// @JUDGE_ID:  17051CA  145  C++
// @begin_of_source_code
/* Calculation  ( Simulation ) */ 
/* PE! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MORNING 0
#define DAY 1
#define EVENING 2
#define NIGHT 3

double T[5][4];
char Step;
string number;
int start, end, start_pos, end_pos;
int C[4];
int Upper[4];
int Lower[4];

int read(){
  cin >> Step;
  int h, m;
  if ( Step == '#' ) return false;
  cin >> number;
  cin >> h >> m;
  start = h*60 + m;
  cin >> h >> m;
  end = h*60 + m;

  if ( 0 <= start && start <= 479 ) start_pos = MORNING;
  if ( 480 <= start && start <= 1079 ) start_pos = DAY;
  if ( 1080 <= start && start <= 1319 ) start_pos = EVENING;
  if ( 1320 <= start && start <= 1439 ) start_pos = NIGHT;

  if ( 0 <= end && end <= 479 ) end_pos = MORNING;
  if ( 480 <= end && end <= 1079 ) end_pos = DAY;
  if ( 1080 <= end && end <= 1319 ) end_pos = EVENING;
  if ( 1320 <= end && end <= 1439 ) end_pos = NIGHT;

  return true;
}

void calculate(){

  if ( start_pos == end_pos ){
    if ( start < end ){
      C[ start_pos ] += end - start;
    }else{
      for ( int i = 0; i < 4; i++ ){
	C[i] = Upper[i] - Lower[i];
      }
      C[ start_pos ] -= start - end;
    }
    return;
  }

  int pos = start_pos;
  
  C[ pos ] = Upper[ pos ] - start;
  pos = (pos+1)%4;
  while ( 1 ){
    if ( pos == end_pos ){
      C[pos] = end - Lower[pos];
      return;
    } else {
      C[pos] = Upper[pos] - Lower[pos];
    }
    pos = (pos+1)%4;
  }
  
}

void work(){
  fill ( C, C + 4,  0 );
  calculate();

  while ( number.size()<10 ) number = ' ' + number;
  cout << number;
  printf("%7d", C[DAY] );
  printf("%7d", C[EVENING] );
  printf("%7d", C[NIGHT] + C[MORNING] );
  double rate = 0;

  cout << " " << Step << " ";
  for ( int i = 0; i < 4; i++ ){
    rate += T[ Step - 'A' ][i] * C[i];
  }

  printf("%10.2f\n", rate );

}

void init(){
  T[0][0] = 0.02; T[0][1] = 0.1; T[0][2] = 0.06; T[0][3] = 0.02;
  T[1][0] = 0.05; T[1][1] = 0.25; T[1][2] = 0.15; T[1][3] = 0.05;
  T[2][0] = 0.13; T[2][1] = 0.53; T[2][2] = 0.33; T[2][3] = 0.13;
  T[3][0] = 0.17; T[3][1] = 0.87; T[3][2] = 0.47; T[3][3] = 0.17;
  T[4][0] = 0.3; T[4][1] = 1.44; T[4][2] = 0.8; T[4][3] = 0.3;
  Upper[0] = 480;
  Upper[1] = 1080;
  Upper[2] = 1320;
  Upper[3] = 1440;
  Lower[0] = 0;
  Lower[1] = 480;
  Lower[2] = 1080;
  Lower[3] = 1320;
}

main(){
  init();
  while ( read() ) work();
}
// @end_of_source_code

