#include<iostream>
#include<string>
#include<cassert>
using namespace std;

void normalize(string &str){
    while( str.size() >= 2 && str[0] == '0' ) {
	str.erase( str.begin() );
    }
}

bool parse(string exp, char ch){
    for ( int i = 0; i < exp.size(); i++ ){
	if ( exp[i] == 'X' ) exp[i] = ch;
    }

    string  fac1, fac2, result;
    fac1 = fac2 = result = "";
    int p = 0;
    while( exp[p] != '+' ) { fac1 += exp[p]; p++;}
    p++;
    while( exp[p] != '=' ) { fac2 += exp[p]; p++;}
    p++;
    while( p < exp.size() ){ result += exp[p]; p++;}


    //if ( fac1.size()>=2 && fac1[0] =='0' ) assert(false);
    // if ( fac2.size()>=2 && fac2[0] =='0' ) assert(false);
    //    if ( result.size()>=2 && result[0] =='0' ) assert(false);

    // if the number has leading zero:
    if ( fac1.size()>=2 && fac1[0] =='0' ) return false;
    if ( fac2.size()>=2 && fac2[0] =='0' ) return false;
    if ( result.size()>=2 && result[0] =='0' ) return false;

    
    int len = max( fac1.size(), fac2.size() );

    while( fac1.size() < len ) fac1 = '0' + fac1;
    while( fac2.size() < len ) fac2 = '0' + fac2;

    int carry = 0;
    int v;
    string left(len, '0');
    for ( int i = len-1; i >= 0; i-- ){
	v = (fac1[i]-'0') + (fac2[i]-'0') + carry;
	left[i] = v%10+'0';
	carry = v/10;
    }
    left = char(carry+'0') + left;

    normalize(left);
    normalize(result);
    
    //    cout << fac1 << "+" << fac2 << "=" << left << endl;




    return (left == result);
}

void compute(string exp){
    char ans = 'X';
    int cnt = 0;
    for ( char ch = '0'; ch <= '9'; ch++ ){
	if ( parse(exp, ch ) ) {
	    assert( ans == 'X' );
	    ans = ch;
	    cnt++;
	}
    }

    assert( cnt <= 1 );
    for ( int i = 0; i < exp.size(); i++ ){
      if ( exp[i] == 'X' ) exp[i] = ans;
    }

    //    cout << exp << endl;
        if ( ans == 'X' ) cout << "NA" << endl;
        else cout << ans << endl;
}

int main(){
    string exp;
    int c = 1;
    while( cin >> exp ){
	compute( exp );
    }
    return 0;
}
