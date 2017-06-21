#include<iostream>
#include<string>
#include<map>

using namespace std;
int n;
string str;

string compute(){
    map<string, int> M;
    map<string, int>::iterator it;


    for ( int i = 0; i < str.size() - n; i++ ){
	M[str.substr(i, n)]++;
    }
    
    int maxv = 0;
    string ans;
    for ( it = M.begin(); it != M.end(); it++ ){
	if ( maxv < (*it).second ){
	    maxv = (*it).second;
	    ans = (*it).first;
	}
    }
    
    return ans;
}


main(){
    while ( cin >> n ){
	cin >> str;
	cout << compute() << endl;
    }
}
