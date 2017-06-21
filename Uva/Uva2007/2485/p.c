// @JUDGE_ID:  17051CA  2485  C++
// @begin_of_source_code
/* Simplest Calculation */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>

class Vowel{
 public:
  int frequency;
  char name;
  Vowel(){
    frequency = 0;
  }

  void init( char ch ){
    name = ch;
    frequency = 0;
  }

  bool operator < ( const Vowel &v ) const{
    if ( frequency == v.frequency ){
      return name < v.name;
    } else {
      return frequency > v.frequency;
    }
  }
};

string line;
Vowel V[5];

void compute(){

  V[0].init( 'a' );
  V[1].init( 'i' );
  V[2].init( 'u' );
  V[3].init( 'e' );
  V[4].init( 'o' );

  for ( int i = 0; i < line.size(); i++ ){
    char ch = tolower( line[i] );
    
    if ( ch == 'a' ){
      V[0].frequency++;
    } else if ( ch == 'i' ){
      V[1].frequency++;
    } else if ( ch == 'u' ){
      V[2].frequency++;
    } else if ( ch == 'e' ){
      V[3].frequency++;
    } else if ( ch == 'o' ){
      V[4].frequency++;
    }
  }

}

void printResult(){
  sort ( V, V + 5 );
  for ( int i = 0; i < 5; i++ ){
    if ( i ) cout << " ";
    cout << V[i].name << ":" << V[i].frequency;
  }
  cout << "." << endl;
}

void work(){
  compute();
  printResult();
}

bool read(){
  getline( cin, line );
  if ( line == "#" ) return false;
  return true;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
