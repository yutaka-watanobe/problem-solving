#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
#include<vector>


using namespace std;

map<string, char> SC;
map<char, string> CS;

vector<char> v;

string itoa(int x){
  char a[20];
  
  sprintf(a, "%d", x);

  return string(a);
}

void split ( vector<string> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();
  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(t);
}

vector<string> digits;

void work(){
  string str = "";
  vector<int> values;
  vector<char> op;
  for ( int i = 0; i < digits.size(); i++ ){
    char ch = SC[ digits[i] ];
    if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
      values.push_back( atoi(str.c_str()) );
      op.push_back( ch );
      str = "";
    } else {
      str += ch;
    }
  }
  values.push_back( atoi(str.c_str() ));

  /*
  for ( int i = 0; i < values.size(); i++ ){
    if ( i ) cout << op[i-1];
    cout << values[i] << " ";
  }
  cout << endl;
  */


  bool changed;
  int value;
  while( 1 ){
    changed = false;

    for ( int i = 0; i < op.size(); i++ ){
      if ( op[i] == '*' ){
	value = values[i] * values[i+1];
	values.erase( values.begin() + i );
	op.erase( op.begin() + i);
	values[i] = value;
	changed = true;
	goto next;
      }else if ( op[i] == '/' ){
	value = values[i] / values[i+1];
	values.erase( values.begin() + i );
	op.erase( op.begin() + i);
	values[i] = value;
	changed = true;
	goto next;
      }
    }
  next:;
    
    if ( !changed ) break;
  }

  while( 1 ){
    changed = false;

    for ( int i = 0; i < op.size(); i++ ){
      if ( op[i] == '+' ){
	value = values[i] + values[i+1];
	values.erase( values.begin() + i );
	op.erase( op.begin() + i);
	values[i] = value;
	changed = true;
	goto next2;
      }else if ( op[i] == '-' ){
	value = values[i] - values[i+1];
	values.erase( values.begin() + i );
	op.erase( op.begin() + i);
	values[i] = value;
	changed = true;
	goto next2;
      }
    }
  next2:;
    
    if ( !changed ) break;
  }

  if ( values.size() != 1 ){
    while ( 1 ){}
  }

  string ans = itoa( values[0] );
  //  cout << values[0] << "---> " << ans << endl;
  vector<string> astring;

  for ( int i = 0; i < ans.size(); i++ ) astring.push_back( CS[ans[i]] );
  
  for ( int i = 0; i < 5; i++ ){
    for ( int j = 0; j < ans.size(); j++ ){
      if ( j ) printf(" ");
      cout << astring[j].substr(i*3, 3);
    }
    printf("\n");
  }
    

}

bool read(){

  string line;
  getline( cin, line );

  vector<string> segments;

  split( segments, line );
  

  digits.resize( segments.size() );
  for ( int i = 0; i < digits.size(); i++ ) digits[i] = segments[i];

  for ( int i = 1; i < 5; i++ ){
    getline( cin, line );
    split( segments, line );
    for ( int j = 0; j < segments.size(); j++ ){
      digits[j] += segments[j];
    }
  }

  if ( digits.size() == 1 && SC[digits[0]] == '0' ) return false;

  getline( cin, line );
  return true;
}

void init(){
  SC["0000.00.00.0000"] = '0';
  SC[".0..0..0..0..0."] = '1';
  SC["000..00000..000"] = '2';
  SC["000..0000..0000"] = '3';
  SC["0.00.0000..0..0"] = '4';
  SC["0000..000..0000"] = '5';
  SC["0..0..0000.0000"] = '6';
  SC["000..0..0..0..0"] = '7';
  SC["0000.00000.0000"] = '8';
  SC["0000.0000..0..0"] = '9';
  SC[".0..0.000.0..0."] = '+';
  SC["......000......"] = '-';
  SC["0.00.0.0.0.00.0"] = '*';
  SC[".0....000....0."] = '/';
  CS['0'] = "0000.00.00.0000";
  CS['1'] = ".0..0..0..0..0.";
  CS['2'] = "000..00000..000";
  CS['3'] = "000..0000..0000";
  CS['4'] = "0.00.0000..0..0";
  CS['5'] = "0000..000..0000";
  CS['6'] = "0..0..0000.0000";
  CS['7'] = "000..0..0..0..0";
  CS['8'] = "0000.00000.0000";
  CS['9'] = "0000.0000..0..0";
  CS['-'] = "......000......";
}

main(){
  init();
  for ( int i = 0;read(); i++ ){
    work();
    cout << endl;
  }
}
