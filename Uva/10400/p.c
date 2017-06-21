// @JUDGE_ID:  17051CA  10400  C++
// @begin_of_source_code
/* DFS !! */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#define UPPER 32000
#define LOWER -32000

unsigned short U[101][64001];
unsigned short PI[101][64001];
unsigned char OP[101][64001];

int current_case;
int n, answer;
int P[101];

void read(){
  cin >> n;
  for ( int i = 0; i < n; i++ ){
    cin >> P[i];
  }
  cin >> answer;
}

bool dfs( int pre_index, int level ){
  int pre_value = pre_index;

  if ( pre_index > UPPER ) pre_value = ( pre_value - UPPER ) * (-1);

  if ( level == n - 1 ){
    if( pre_value == answer ) return true;
    else return false;
  }

  int value, index;
  
  /* + */
  value = pre_value + P[level+1];
  index = ( value >= 0 ) ?  value : abs( value ) + UPPER;
  if ( LOWER <= value && value <= UPPER && U[level+1][index] < current_case){
    U[level+1][index] = current_case;
    OP[level+1][index] = '+';
    PI[level+1][index] = pre_index; 
    if ( dfs( index, level+1 ) ) return true;
  }

  /* - */
  value = pre_value - P[level+1];
  index = ( value >= 0 ) ?  value : abs( value ) + UPPER;
  if ( LOWER <= value && value <= UPPER && U[level+1][index] < current_case){
    U[level+1][index] = current_case;
    OP[level+1][index] = '-';  
    PI[level+1][index] = pre_index; 
    if ( dfs( index, level+1 ) ) return true;
  }
  
  /* * */
  value = pre_value * P[level+1];
  index = ( value >= 0 ) ?  value : abs( value ) + UPPER;
  if ( LOWER <= value && value <= UPPER && U[level+1][index] < current_case){
    U[level+1][index] = current_case;
    OP[level+1][index] = '*';
    PI[level+1][index] = pre_index;
    if ( dfs( index, level+1 ) ) return true;
  }

  /* / */
  if ( !( P[level+1] != 0 && pre_value % P[level+1] == 0) ) return false;

  value = pre_value / P[level+1];
  index = ( value >= 0 ) ?  value : abs( value ) + UPPER;

  if ( LOWER <= value && value <= UPPER && U[level+1][index] < current_case){
    U[level+1][index] = current_case;
    OP[level+1][index] = '/';
    PI[level+1][index] = pre_index;
    if ( dfs( index, level+1 ) ) return true;
  }


  return false;
}

void work(){
  
  if ( !dfs( P[0], 0 ) ){
    cout << "NO EXPRESSION" << endl;
    return;
  }

  vector<char> op;

  int pre = answer;
  int i = n-1;
  while ( 1 ){
    if ( i == 0 ) break;
    op.push_back( OP[i][pre] );
    pre = PI[i][ pre ];
    i--;
  }

  reverse( op.begin(), op.end() );

  for ( int i = 0; i < n-1; i++ ){
    cout << P[i] << op[i];
  }
  cout << P[n-1] << "=" << answer << endl;

}

main(){

 /*  for ( int i = 0; i < 101; i++ ){ */
/*     fill ( U[i], U[i] + 64001, 0 ); */
/*   } */

  int t;
  cin >> t;
  for ( int i = 1; i <= t; i++ ){
    read();
    current_case = i;
    work();
  }
}
// @end_of_source_code
