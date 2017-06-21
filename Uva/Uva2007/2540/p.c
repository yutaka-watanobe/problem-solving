// @JUDGE_ID:  17051CA  2540  C++
// @begin_of_source_code
/* Simple Encode */
#include<stdio.h>
#include<iostream>
#include<string>

class TheHardestProblemEver{
 public:
  string cipherText;

  void work(){

    for ( int i = 0; i < cipherText.size(); i++ ){
      char ch = cipherText[i];
      if ( isalpha( ch ) ){
	char value = ch - 5;
	if ( value < 'A' ) value += 26;
	cout << ( char )( value  );
      } else {
	cout << ch;
      }
    }
    cout << endl;
  }

  bool read(){
    string line;
    cin >> line;
    if ( line == "ENDOFINPUT" ) return false;
    getline( cin, line );
    getline( cin, cipherText );
    cin >> line;
    return true;
  }

};

main(){
  TheHardestProblemEver ever;

  while ( ever.read() ){
    ever.work();
  }
}

// @end_of_source_code


