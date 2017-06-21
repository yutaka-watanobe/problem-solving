#include<iostream>
#include<string>
using namespace std;

static const string BT[10] = {"", "',.!?", "abcABC", "defDEF",
                             "ghiGHI", "jklJKL", "mnoMNO",
                             "pqrsPQRS", "tuvTUV", "wxyzWXYZ"};

int main(){
    string str;
    while( cin >> str ){
	str += '0';
	int cnt = 1;
	for(int i = 1; i < str.size(); i++){
	    if ( str[i-1] != str[i] ){
		if ( str[i-1] == '0' ) for ( int s = 1; s < cnt; s++ ) cout << ' ';
		else cout << BT[str[i-1]-'0'][(cnt-1)%BT[str[i-1]-'0'].size()];
		cnt = 1;
	    } else cnt++;
	}
	cout << endl;
    }
    return 0;
}
