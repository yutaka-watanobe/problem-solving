#include<iostream>
#include<string>

using namespace std;

string line;

void compute(){
    string pqrst = "";
    string KACE = "";
    string N = "";
    string ans = "";
    for ( int i = 0; i < line.size(); i++ ){
	char ch = line[i];
	if ( ch == 'p' || ch == 'q' || ch == 'r' || ch == 's' || ch == 't' ){
	    pqrst += ch;
	} else if ( ch == 'N' ){
	    N += ch;
	} else if ( ch == 'K' || ch == 'A' || ch == 'C' || ch == 'E' ){
	    KACE += ch;
	}
    }

    if ( pqrst.size() == 0 ){
	cout << "no WFF possible" << endl;
	return;
    }
    if ( pqrst.size() ){
	ans += pqrst[0]; pqrst.erase(pqrst.begin());
    }

    int mn = min( pqrst.size(), KACE.size() );

    for ( int i = 0; i < mn; i++ ){
	ans = KACE[i] + ans + pqrst[i];
    }

    if ( ans.size() ){
	ans = N + ans;
    }
    
    cout << ans << endl;
}

int main(){
    while( cin >> line ){
	if ( line == "0" ) break;
	compute();
    }
}
