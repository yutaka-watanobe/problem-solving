#include<iostream>
#include<map>
#include<string>
using namespace std;

main(){
    string str, maxs;
    int maxl = 0;
    map<string, int> M;
    while( cin >> str ){
	if ( maxl < str.size()){
	    maxl = str.size(); maxs = str;
	}
	M[str]++;
    }
    int m = 0;
    string fs;
    for ( map<string, int>::iterator it = M.begin(); it != M.end(); it++ ){
	if ( m < (*it).second ){
	    fs = (*it).first;
	    m = (*it).second;
	}
    }
    cout << fs << " " << maxs << endl;
}
