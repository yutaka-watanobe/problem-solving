// @JUDGE_ID:  17051CA  380  C++
// @begin_of_source_code
/* Simulation + Recursion */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>

class Call{
 public:
  int lower, upper;
  string target;
  Call(){}
  Call( string slower, string supper, string target): target( target ){
    lower = atoi( slower.c_str() );
    upper = atoi( supper.c_str() );
    upper = lower + upper;
  }
};

class Forward{
 public:
  vector<Call> callList;
  Forward(){}

  void addCall( Call call ){
    callList.push_back( call );
  }
};

map< string, Forward > forwardList;

string request( int time, string &target, map<string, int> &U ){

  if ( forwardList.find( target ) == forwardList.end() ) return target;
  if ( U[ target ] ) return "9999";
  U[ target ] = 1;
  
  Forward forward = forwardList[ target ];

  for ( int i = 0; i < forward.callList.size(); i++ ){
    Call call = forward.callList[i];
    if ( call.lower <= time && time <= call.upper ){
      return request( time, call.target, U );
    }
  }

  return target;
}

void work(){
  string target, time;
  string answer;
  
  while ( 1 ){
    cin >> time;
    if ( time == "9000" ) break;
    cin >> target;
    map<string, int> U;
    answer = request( atoi( time.c_str() ), target , U);
    cout << "AT " << time << " CALL TO " << target << " RINGS " << answer << endl;
  }
}

void read(){
  forwardList = map< string, Forward >();
  string source, lower, upper, target;
  while ( 1 ){
    cin >> source;
    if ( source == "0000" ) break;
    cin >> lower >> upper >> target;
    forwardList[ source ].addCall( Call( lower, upper, target ) );
  }
}

main(){
  int tcase;
  cin >> tcase;
  cout << "CALL FORWARDING OUTPUT" << endl;
  for ( int i = 0; i < tcase; i++ ){
    cout << "SYSTEM " << i + 1 << endl;
    read();
    work();
  }
  cout << "END OF OUTPUT" << endl;
}
// @end_of_source_code
