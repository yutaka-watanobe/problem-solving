#include<iostream>
#include<string>


using namespace std;

int expression();
int term();
pair<int,int> factor();

int power(int x, int a){
  int v = 1;
  for ( int i = 0; i < a; i++ ){
    v *= x;
  }
  return v;
}

string exp;
string buffer;

int p;

int expression(){
    int value = term();
    while( exp[p] == '+' || exp[p] == '-' ){
	if ( exp[p] == '+' ) { 
	  p++; 
	  buffer += '+';
	  value += term(); 
	} else { 
	  p++; 
	  buffer += '-';
	  value -= term(); 

	}
    }
    return value;
}

int term(){
    pair<int, int> f = factor();
    int value = f.first;
  
    while( exp[p] == '*' || exp[p] == '/' ){
	if ( exp[p] == '*' ) { 
	  p++; 
	  buffer += '*';
	  if ( exp[p] == '*' ){
	    p++;
	    buffer += '*';
	    f = factor();
	    int v = f.first;
	    value = power(value, v);
	  } else {
	    f = factor();
	    value *= f.first;
	  }
	} else { 
	  buffer += '/';
	  p++; 
	  f = factor();
	  value /= f.first;

	}
    }
    return value;
}

pair<int, int> factor(){
    int value = 0;
    if ( exp[p] == '(' ){
      buffer += '(';
	p++; value = expression(); p++;
	buffer += ')';
    } else {
	while( isdigit(exp[p]) ) { 
	  buffer += exp[p];
	  value = value*10 + exp[p] - '0'; p++;
	}
    }
    return make_pair(value, 0);
}

int main(){
	while(cin >> exp){
	  p = 0;
	  buffer = "";
	  cout << expression() << endl;
	  cout << exp << endl;
	  cout << buffer << endl;
	  cout << endl;
	}

    return 0;
}
