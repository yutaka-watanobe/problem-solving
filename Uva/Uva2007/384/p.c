// @JUDGE_ID:  17051CA  384  C++
// @begin_of_source_code
/* πΩ ∏≤Ú¿œ Recursion */ 
#include<stdio.h>
#include<iostream>
#include<string>

string line;

bool isSlump(string str){
  if ( !(str[0] == 'E' || str[0] == 'D') ) return false;
  if ( str.size() >=2 && str[1] != 'F' ) return false;

  int i = 2;
  while ( i < str.size() && str[i] == 'F' ){
    i++;
  }

  if ( i >= str.size() ) return false;

  if ( i == str.size()-1 && str[i] == 'G' ) return true;

  return  isSlump( str.substr(i, str.size()-i)) ;

}

bool isSlimp(string str){
  if ( str[0] != 'A' ) return false;
  if ( str.size()==2 ){
    if ( str != "AH" ) return false;
    return true;
  }

  if ( str.size() >= 4 ){
    if ( str[0] == 'A' && str[1] == 'B' && str[ str.size()-1 ] == 'C'){
      if ( isSlimp( str.substr(2, str.size()-3 ) ) ) return true;
    }
  }

  if ( str.size() >= 3 ){
    if ( str[0] == 'A' && str[ str.size()-1 ] == 'C' ){
      if ( isSlump( str.substr(1, str.size()-2) ) ) return true;
    }
  }

  return false;
}

void work(){
  string s1, s2;

  for ( int i = 0; i < line.size(); i++ ){
    s1 = line.substr( 0, i + 1 );
    s2 = line.substr( i+1, line.size()-i );
    if ( isSlimp( s1 ) && isSlump( s2 ) ){
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

main(){
  cout << "SLURPYS OUTPUT" << endl;
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    cin >> line;
    work();
  }
  cout << "END OF OUTPUT" << endl;
}
// @end_of_source_code
