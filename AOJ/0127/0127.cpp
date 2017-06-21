#include<iostream>
#include<string>
using namespace std;

string T[6] = {"",
	       " afkpuz",
	       " bglqv.",
	       " chmrw?",
	       " dinsx!",
	       " ejoty "};

void simulate(string str){
    if ( str.size()%2 != 0 ){
	cout << "NA" << endl; 
	return;
    }
    
    string ans = "";
    for ( int i = 0; i < str.size(); i+=2){
	int first = str[i] - '0';
	int second = str[i+1] - '0';
	if ( 1 <= first && first <= 6 &&
	     1 <= second && second <= 5 ){
	    ans += T[second][first];
	} else {
	    cout << "NA" << endl; return;
	}
    }
    cout << ans << endl;
}

int main(){
    string str;
    while( cin >> str ){
	simulate(str);
    }
    return 0;
}
