// @JUDGE_ID:  17051CA  325  C++
// @begin_of_source_code
/* Parse ? */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stl.h>

void trim(string &s){
  int l, r;

  l = s.find_first_not_of(" \n\r");
  r = s.find_last_not_of(" \n\r");

  if(l==string::npos) s = "";
  else  s = s.substr(l, r-l+1);
}

class PascalRealConstants{
 public:
  string input;
  string state;

  void createState(){
    state = "";
    
    char ch;
    for ( int i = 0; i < input.size(); i++ ){
      ch = input[i];
      if ( ch == '+' || ch == '-' ) state += 'S';
      else if ( ch == 'e' || ch == 'E' ) state += 'E';
      else if ( ch == '.' ) state += 'P';
      else if ( isdigit( ch ) ){
	if ( state.size() == 0 ){
	  state += 'D';
	} else {
	  if ( state[ state.size() - 1]  != 'D' ) state += 'D';
	}
      } else {
	state += 'O';
      }
    }

  }

  bool check(){
    if ( state == "DPD" || state == "SDPD" ||
	 state == "DPDESD" || state == "SDPDESD" ||
	 state == "DPDED" || state == "SDPDED" ||
	 state == "DED" || state == "SDED" ||
	 state == "DESD" || state == "SDESD" ) return true;
    return false;
  }

  void work(){
    createState();
    if ( check () ){
      cout << input << " is legal." << endl;
    } else {
      cout << input << " is illegal." << endl;
    }
  }

  bool read(){
    getline( cin, input );
    trim( input );
    if ( input == "*" ) return false;

    return true;
  }
  
};

main(){
  PascalRealConstants PRC;
  
  while ( PRC.read() ){
    PRC.work();
  }
}
// @end_of_source_code


