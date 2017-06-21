// @JUDGE_ID:  17051CA  390  C++
// @begin_of_source_code
/* Counter and Simulation  */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<stl.h>
#include<string>

class Sequence{
 public:
  int length;
  map<string, int> frequency;
  map<int, vector<string> > contents;

  Sequence(){}
  Sequence( int length ): length( length ){}
  
  void addSequence( string str ){
    for ( int i = 0; i < length; i++ ) 
      if ( !isalpha( str[i] ) ) return;
    frequency[ str ]++;
  }

  void setContents(){
    map<string, int>::iterator pos;
    for ( pos = frequency.begin(); pos != frequency.end(); pos++ ){
      contents[ (*pos).second ].push_back( (*pos).first );
    }
  }

  void print(){
    cout << "Analysis for Letter Sequences of Length " << length << endl;
    cout << "-----------------------------------------" << endl;
    map<int, vector<string> >::iterator pos;
    int counter = 0;
    for ( pos = --contents.end(); ; pos-- ){
      cout << "Frequency = " << (*pos).first << ", ";
      vector<string> wordList = (*pos).second;
      cout << "Sequence(s) = (";
      for ( int i = 0; i < wordList.size(); i++ ){
	if ( i ) cout << ',';
	cout << wordList[i];
      }
      cout << ")" << endl;
      if ( pos == contents.begin() ) break;
      counter++;
      if ( counter >= 5 ) break;
    }
  }
};

class LetterSequenceAnalysis{
 public:
  string input;
  Sequence sequences[5];

  void work(){
    for ( int i = 0; i < 5; i++ ){
      sequences[i] = Sequence( i + 1 );
    }

    for ( int len = 1; len <= 5; len++ ){
      for ( int i = 0; i < input.size() - len + 1; i++ ){
	sequences[len - 1].addSequence( input.substr(i, len ) );
      }
    }

    for ( int len = 0; len < 5; len++ ){
      /* if ( len ) cout << endl; */
      sequences[len].setContents();
      sequences[len].print();
      cout << endl;
    }
  }

  void read(){
    char ch;
    input = "";
    while( scanf("%c", &ch ) != EOF ){
      if ( isalpha( ch ) ) ch = toupper( ch );
      input += ch;
    }
  }

};

main(){
  LetterSequenceAnalysis LSA;
  LSA.read();
  LSA.work();
}

// @end_of_source_code


