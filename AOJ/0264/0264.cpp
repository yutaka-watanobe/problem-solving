#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
string exp;
int pos, p;
bool valid;

int expression();
int term();
int factor();

int power(int x, int n){
  if ( n == 0 ) return 1;
  int res = power(x*x%p, n/2);
  if ( n & 1 ) res = res*x%p;
  return res;
}

int expression(){
    int value = term();
    while( exp[pos] == '+' || exp[pos] == '-' ){
	if ( exp[pos] == '+' ) { 
	    pos++; value = (value + term())%p; 
	} else { 
	    pos++; 
	    int m = p - term();
	    value = (value + m)%p;
	}
    }
    return value;
}

int term(){
    int value = factor();
    while( exp[pos] == '*' || exp[pos] == '/' ){
	if ( exp[pos] == '*' ) { 
	    pos++; 
	    value = (value*factor())%p;
	} else { 
	    pos++; 
	    int f = factor();
	    if ( f == 0 ) { valid = false; return 0;}
	    int d = power(f, p-2);
	    value = (value*d)%p;
	}
    }
    return value;
}

int factor(){
    int value = 0;
    if ( exp[pos] == '(' ){
	pos++; value = expression(); pos++;
    } else {
	while( isdigit(exp[pos]) ) { value = value*10 + exp[pos] - '0'; pos++;}
    }
    return value;
}


int main(){
    char ch;
    while(1){
	cin >> p >> ch;
	if ( p == 0 ) break;
	exp = "";
	while(1) { 
	  scanf("%c", &ch);
	  if ( ch == ' ' ) continue;
	  if ( ch == '\n' ) break;
	  exp += ch;
	}
	pos = 0;
	valid = true;
	int ans = expression();
	if ( !valid ) {
	    cout << "NG" << endl;
	} else {
	    cout << exp << " = " << ans << " (mod " << p << ")" << endl;
	}
    }
    return 0;
}
