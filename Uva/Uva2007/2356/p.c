// @JUDGE_ID:  17051CA  2356  C++
// @begin_of_source_code
/* Simple Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>

stack<string> forwardStack;
stack<string> backwardStack;
string current;

void printCurrent(){
  cout << current << endl;
}

void ignored(){
  cout << "Ignored" << endl;
}

void work(){
  string command;
  while ( 1 ){
    cin >> command;
    if ( command == "BACK" ){
      if( backwardStack.empty() ) ignored();
      else{
	forwardStack.push( current );
	current = backwardStack.top(); backwardStack.pop();
	printCurrent();
      }
    } else if ( command == "FORWARD" ){
      if ( forwardStack.empty() ) ignored();
      else{
	backwardStack.push( current );
	current = forwardStack.top(); forwardStack.pop();
	printCurrent();
      }
    } else if ( command == "VISIT" ){
      string url;
      cin >> url;
      backwardStack.push( current );
      forwardStack = stack<string>();
      current = url;
      printCurrent();
    } else if ( command == "QUIT" ){
      return;
    } else {
      assert( false );
    }
  }
}

void init(){
  forwardStack = stack<string>();
  backwardStack = stack<string>();
  current = "http://www.acm.org/";
}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    init();
    work();
  }
}
// @end_of_source_code
