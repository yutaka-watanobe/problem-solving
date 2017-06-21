#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int expression();
int term();
int factor();

string exp;
int p;

int expression(){
    int value = term();
    while( exp[p] == '+' || exp[p] == '-' ){
	if ( exp[p] == '+' ) { p++; value += term(); }
	else { p++; value -= term(); }
    }
    return value;
}

int term(){
    int value = factor();
    while( exp[p] == '*' || exp[p] == '/' ){
	if ( exp[p] == '*' ) { p++; value *= factor(); }
	else { p++; value /= factor(); }
    }
    return value;
}

int factor(){
    int value = 0;
    if ( exp[p] == '(' ){
	p++; value = expression(); p++;
    } else {
	while( isdigit(exp[p]) ) { value = value*10 + exp[p++] - '0';}
    }
    return value;
}

string normalize(string str){
    string v = "";
    for ( int i = 0; i < str.size(); i++ ){
	if ( str[i] == ' ') continue;
	v += str[i];
    }
    return v;
}

vector<string> ans;

void parse( vector<string> expv, vector<char> op ){
    if ( expv.size() == 1 ){
	exp = normalize(expv[0]);
	p = 0;
	int v = expression();
	//	cout << expv[0] << " = " << v << endl;
	if ( v == 10 ) {
	    //cout << expv[0] << endl;
	    ans.push_back(expv[0]);
	}
	return ;
    }

    vector<string> v;
    vector<char> vo;

    for ( int i = 0; i < expv.size()-1; i++ ){
	v = expv;
	vo = op;
	string newe = "(" + v[i] + " " + vo[i] + " " + v[i+1] + ")";
	v.erase(v.begin() + i);
	v[i] = newe;
	vo.erase(vo.begin()+ i);
	parse(v, vo);
    }
}

char getOP(int i){
    if ( i == 0 ) return '+';
    else if ( i == 1 ) return '-';
    else if ( i == 2 ) return '*';
}

int main(){
    string in[4];
    
    while(1){
	ans.clear();
	for ( int i = 0; i < 4; i++ ) cin >> in[i];
	if ( in[0] == "0" && in[1] == "0" && in[2] == "0" && in[3] == "0" ) break;
	sort( in, in + 4);
	
	do{
	    vector<string> expv;
	    for ( int i = 0; i < 4; i++ ) expv.push_back(in[i]);
	    for ( int i = 0; i < 3; i++ ){
		for ( int j = 0; j < 3; j++ ){
		    for ( int k = 0; k < 3; k++ ){
			vector<char> op;
			op.push_back(getOP(i));
			op.push_back(getOP(j));
			op.push_back(getOP(k));
			parse(expv, op);
		    }
		}
	    }
	} while(next_permutation(in, in + 4));


	if ( ans.size() == 0 ) cout << "0" << endl;
	else cout << ans[0] << endl;
    }
    return 0;
}
