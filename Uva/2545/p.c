// @JUDGE_ID:  17051CA  2545  C++
// @begin_of_source_code
/* Recurtion - String encoding */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#define MAX 21

class BlueGene{
 public:
  int N;
  char viralCode[ MAX ];
  char mutatedCode[ MAX ];

  int countChange( int pos ){
    int sum = 0;
    for ( int i = pos ; i < N; i++ ){
      if ( viralCode[i] != mutatedCode[i] ) sum++;
    }
    return sum;
  }
  
  void parse( int pos ){
    if ( viralCode[ pos ] == '0' ) return ;
    
    if ( isdigit( viralCode[ pos ] ) ){
      int value = viralCode[pos] - '0';
      mutatedCode[pos] = (value - 1) + '0';
      int next_pos = pos + value;
      if ( pos == N - 1 ) return;
      
      if ( next_pos < N ){
	parse( next_pos );
      } else {
	parse( pos + 1 );
      }
      
    } else if ( 'A' <= viralCode[pos] && viralCode[pos] <= 'Z' ){
      if ( pos == N - 1 ) {
	mutatedCode[pos] = '0';
      } else {
	parse( pos + 1 );
	mutatedCode[pos] = (countChange( pos + 1 ) % 10 ) + '0';
      }
      
    }
    
  }
  
  void work(){
    for ( int i = 0; i < N; i++ ) mutatedCode[i] = viralCode[i];
    
    parse( 0 );
    
    for ( int i = 0;i < N; i++ ){
      cout << mutatedCode[i];
    }
    cout << endl;
  }
  
  bool read(){
    string line;
    cin >> line;
    if ( line == "ENDOFINPUT" ) return false;
    
    cin >> N;
    
    for ( int i = 0; i < N; i++ ) cin >> viralCode[i];
    cin >> line;
    
    return true;
  }
};

main(){

  BlueGene gene;
  
  while ( gene.read() ){
    gene.work();
  }
}


// @end_of_source_code


