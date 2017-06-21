#include<iostream>
#include<string>
using namespace std;
typedef pair<long long, long long> Complex;

#define MAX 10000

Complex expression();
Complex term();
Complex factor();
bool overflow;
string expp;
int p;

void check(Complex v){
  if( v.first > MAX || v.first < MAX*(-1) )  overflow = true;
  if( v.second > MAX || v.second < MAX*(-1) )  overflow = true;
}

Complex expression(){
    Complex value = term();
    while( expp[p] == '+' || expp[p] == '-' ){
	if ( expp[p] == '+' ) { 
	  p++; 
	  Complex t = term();
	  value.first += t.first;
	  value.second += t.second;
	  check(value);
	} else { 
	  p++; 
	  Complex t = term();
	  value.first -= t.first;
	  value.second -= t.second;
	  check(value);
	}
    }
    return value;
}

Complex term(){
    Complex value = factor();
    while( expp[p] == '*' ){
      p++; 
      Complex f = factor();
      Complex v = value;
      value.first = v.first*f.first - v.second*f.second;
      value.second = v.first*f.second + v.second*f.first;
      check(value);
    }
    return value;
}

Complex factor(){
  Complex value;
  value.first = value.second = 0;
    if ( expp[p] == '(' ){
	p++; value = expression(); p++;
    } else {
      if ( expp[p] == 'i' ){
	p++;
	value.first = 0;
	value.second = 1;
      } else {
	while( isdigit(expp[p]) ) { 
	  value.first = value.first*10 + expp[p] - '0'; p++;
	  check(value);
	}
      }
    }
    return value;
}

void output(Complex c){
  if ( c.first == 0 && c.second == 0 ) {
    cout << 0; return;
  } 
  if ( c.first != 0 ) cout << c.first;
  if ( c.second == 0 ) return;
  if ( c.first != 0 && c.second > 0 ) cout << "+";
  cout << c.second << "i";
}

int main(){
  while( cin >> expp ){
    p = 0;
    overflow = false;
    Complex ans = expression();
    if ( overflow ) cout << "overflow" << endl;
    else {
      output(ans);
      cout << endl;
    }
  }
  return 0;
}
