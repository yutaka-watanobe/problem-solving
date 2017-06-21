#include<iostream>
using namespace std;

int getInt( string str ){
    int p = 1;
    int sum = 0;
    for ( int i = str.size()-1; i >= 0; i-- ){
	sum += (str[i]-'0')*p;
	p *=10;
    }
    return sum;
}

int main(){
    char ch;
    string digit = "";
    int sum = 0;
    while(scanf("%c", &ch) != EOF ){
	if ( '0' <= ch && ch <= '9' ) digit += ch;
	else {
	    if ( digit.size() > 0 ) sum += getInt(digit);
	    digit = "";
	}
    }

    cout << sum << endl;
    return 0;
}
