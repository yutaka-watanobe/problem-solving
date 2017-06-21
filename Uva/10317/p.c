// @JUDGE_ID:  17051CA  10317  C++
// @begin_of_source_code
/* Equation Backtrack */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#define POSITIVE 0
#define NEGATIVE 1

void split( vector<string> &d, const string &s, char c = ' ' ){
  string t = "";  vector<int> path;

  for ( int i = 0; i < s.size(); i++ ){
    if ( s[i] == c ){
      if ( t != "" ) { d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( t );
}

string line;
int c_lim, lim;
vector<int> terms;
vector<int> sign;
bool able;
int mode, n_mode;

int read(){
  getline( cin, line );
  if ( cin.eof() ) return 0;
  return 1;
}

bool rec( int index, int cnt, int sum ){
  if ( cnt == c_lim ){
    if( sum == lim ){
      return true;
    }else {
      return false;
    }
  }

  if ( cnt > c_lim ) return false;
  if ( terms.size() - index + cnt < c_lim ) return false;
  if ( terms.size() <= index ) return false;

  sign[ index ] = mode;
  if ( !rec( index + 1, cnt + 1, sum + terms[ index ] ) ){
    
    sign[ index ] = n_mode;
    
    /* not get */
    return rec( index + 1, cnt, sum );
  } else {
    return true;
  }

}

void work(){
  if ( line.size() == 0 ) return ;
  int positive, negative;
  int terms_sum = 0;
  positive = negative = 1;
  
  terms.clear();
  sign.clear();
  vector<string> operators;

  vector<int> PV, NV;
  vector<string> com;

  split( com, line );

  for ( int i = 0; i < com.size(); i+=2 ){
    int k = atoi(com[i].c_str());
    terms.push_back( k );
    terms_sum += k;
    if( i ) operators.push_back( com[i-1] );
  }

  bool left = true;;
  
  for ( int i = 0; i < operators.size(); i++ ){
    if ( operators[i] == "=" ) {
      left = false;
      continue;
    }
    if ( left ){
      if ( operators[i] == "+" ) positive++;
      else negative++;
    }else{
      if ( operators[i] == "-" ) positive++;
      else negative++;
    }
  }

//  terms_sum = abs( terms_sum );

  if ( terms_sum % 2 != 0 ) {
    cout << "no solution" << endl;
    return;
  }

  if( positive < negative ){
    mode = POSITIVE;
    n_mode = NEGATIVE;
  }else{
    mode = NEGATIVE;
    n_mode = POSITIVE;
  }

  sign.resize( terms.size(), n_mode );

  c_lim = min(positive, negative);
  lim = terms_sum/2;

//  cout << "c_lim = " << c_lim << "  lim = " << lim << endl;
  able = false;

  able = rec( 0, 0, 0 );

  if ( !able ){
    cout << "no solution" << endl;
    return;
  }

  for ( int i = 0; i < terms.size(); i++ ){
    if ( sign[i] == POSITIVE ) PV.push_back( terms[i] );
    else NV.push_back( terms[i] );
  }

  left = true;
  int pc, nc;
  pc = nc = 0;
  string pre = "+";

  for ( int i = 0; i < operators.size(); i++ ){
    if ( left ){
      if( pre == "+" ) {
	cout << PV[pc++];
      }else{
	cout << NV[nc++];
      }
    }else{
      if( pre == "+" ) {
	cout << NV[nc++];
      }else{
	cout << PV[pc++];
      }
    }

    cout << " " << operators[i] << " ";
    if ( operators[i] == "=" ) {pre = "+"; left = false; }
    else pre = operators[i];
  }

  if ( pc < PV.size() ) cout << PV[pc] << endl;
  if ( nc < NV.size() ) cout << NV[nc] << endl;
  
}

main(){
  while ( read() ) {
    work();
  }
}
// @end_of_source_code
