#include<iostream>
#include<string>


using namespace std;

void expression();
void term();
int factor();


string exp;
string buffer;
int p;
bool updated;
string cand;

void expression(){
    if ( updated ) return;
    term();
    while( exp[p] == '+' || exp[p] == '-' ){
	if ( updated ) return;
	if ( exp[p] == '+' ) { 
	  p++; 
	  buffer += '+';
	  term ();
	} else { 
	  p++; 
	  buffer += '-';
	  term();
	}
    }
}

void term(){
    if ( updated ) return;
    int b = factor();
  
    while( exp[p] == '*' || exp[p] == '/' ){
	if ( updated ) return;
	if ( exp[p] == '*' ) { 
	  p++; 
	  buffer += '*';
	  if ( exp[p] == '*' ){
	    p++;
	    buffer += '*';
	    buffer.resize(buffer.size()-2);

	    //buffer.insert(b, "X");
	    buffer.resize(b);
	    buffer += "9*";
	    //buffer += "-";

	    factor();
	    buffer += exp.substr(p);
	    cand = buffer;
	    updated = true;
	  } else {
	      factor();
	  }
	} else { 
	  buffer += '/';
	  p++; 
	  factor();
	}
    }

}

int factor(){
    if ( updated ) return 0;
    int b = p;
    if ( exp[p] == '(' ){
	buffer += '(';
	p++; expression(); p++;
	buffer += ')';
    } else {
	while( isdigit(exp[p]) ) { 
	  buffer += exp[p];
	  p++;
	}
    }
    return b;
}

int main(){
	while(cin >> exp){
	  updated = true;

	  buffer = "";

	  cout << exp << endl;

	  while( updated ){
	      p = 0;
	      updated = false;
	      expression();
	      cout << "---> " << buffer << endl;
	      if ( updated ) exp = cand;
	  }
	  cout << exp << endl;
	  cout << endl;
	}

    return 0;
}
