#include<iostream>
#include<string>

using namespace std;
string exp;
int index, pos;
char ans;

int expression( int s ){
    cout << "recursive " << s << " ";
    string result = "";
    int len = 0;
    while(1){
	string d = "";
	int el = 0;
	while( isdigit(exp[pos]) ) d += exp[pos++];
	int id;
	if ( d.size() == 0 ) id = 1;
	else id = atoi(d.c_str());
	string e;
	if ( exp[pos] == '(' ) {
	    pos++;
	    //e = expression();
	    el = expression(len);
	} else {
	    e = "";
	    while( pos < exp.size() && isalpha(exp[pos]) ) {e += exp[pos++]; el++;}
	}
	
	for ( int i = 0; i < id; i++ ) result += e;
	if ( len + el*id <= 1000000000 ) len = len + el*id;
	//	len = (len + el*id)%1000000;


	if ( s <= index && index < s + len ){
	  if ( ans == '0' ) {
	    cout << s << "--" << s+len << "  result = " << result << endl;
	    ans = result[result.size() - (len-index)];
	  }
	}
	

	if ( exp[pos] == ')' ){
	    pos++;
	    cout << s << "-----" << s+len << endl;
	    //	    return result;
	    cout << "return " << len << endl;
	    return len;
	} else if ( pos >= exp.size() ) {
	    cout << "return " << len << endl;
	    return len;
	    //return result;
	}
    }
}

void compute(){
    pos = 0;
    ans = '0';
    cout << "exp = " << exp << endl;
    int l = expression(0);
    cout << "length = " << l << endl;
    cout << ans << endl;
}

main(){
    while(1){
	cin >> exp >> index;
	if ( exp == "0" && index == 0 ) break;
	compute();
    }
}
