// @JUDGE_ID:  17051CA  397  C++
// @begin_of_source_code
/* Simple Parse */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

class EquationElation{
 public:
  vector<char> operand;
  vector<int> value;
  string answer;

  void printEquation(){

    for ( int i = 0; i < value.size(); i++ ){
      cout << value[i];
      if ( i != value.size() -1 ) {
	cout << " " << operand[i] << " ";
      }
    }

    cout << " = " << answer << endl;
  }

  bool compute(){
    char op;
    for ( int i = 0; i < operand.size(); i++ ){
      op = operand[i];
      if ( op == '*' ){
	value[i] = value[i] * value[i+1];
	value.erase( value.begin() + i + 1 );
	operand.erase( operand.begin() + i );
	return false;
      }
      if ( op == '/' ){
	value[i] = value[i] / value[i+1];
	value.erase( value.begin() + i + 1 );
	operand.erase( operand.begin() + i );
	return false;
      }
    }

    for ( int i = 0; i < operand.size(); i++ ){
      op = operand[i];
      if ( op == '+' ){
	value[i] = value[i] + value[i+1];
	value.erase( value.begin() + i + 1 );
	operand.erase( operand.begin() + i );
	return false;
      }
      if ( op == '-' ){
	value[i] = value[i] - value[i+1];
	value.erase( value.begin() + i + 1 );
	operand.erase( operand.begin() + i );
	return false;
      }
    }
    return true;
  }

  void work(){
    printEquation();

    while ( 1 ){
      if ( compute() ){
	break;
      } else {
	printEquation();
      }
    }

  }

  void init(){
    operand.clear();
    value.clear();
  }

  bool read(){
    init();
    
    int v;
    char ch;

    while ( 1 ){
      if ( !( cin >> v ) ) return false;
      value.push_back( v );
      cin >> ch;
      if ( ch == '=' ) break;
      operand.push_back( ch );
    }

    cin >> answer;
    return true;
  }

};

main(){
  EquationElation EE;
  for ( int i = 0; EE.read(); i++ ){
    EE.work();
    cout << endl;
  }
}

// @end_of_source_code


