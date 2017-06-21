#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#define MAX 200
using namespace std;

int n, d;
string buffer[MAX];
map<string, bool> transformed[MAX];

void transform(int pos){
    transformed[pos] = map<string, bool>();

    string target;
    string source = buffer[pos];
    for ( int i = 0; i < source.size(); i++ ){
	target = source;
	target.erase( target.begin() + i );
	transformed[pos][target] = true;
    }
    for ( char ch = 'a'; ch <= 'z'; ch++ ){
	for ( int i = 0; i <= source.size(); i++ ){
	    target = source;
	    target.insert( target.begin() + i, ch );
	    transformed[pos][target] = true;
	}
    }
    for ( char ch = 'a'; ch <= 'z'; ch++ ){
	for ( int i = 0; i < source.size(); i++ ){
	    if ( source[i] == ch ) continue;
	    target = source;
	    target[i] = ch;
	    transformed[pos][target] = true;
	}
    }
    for ( int i = 0; i < source.size()-1; i++ ){
	if ( source[i] == source[i+1] ) continue;
	target = source;
	char tmp = target[i];
	target[i] = target[i+1];
	target[i+1] = tmp;
	transformed[pos][target] = true;
    }

    assert( !transformed[pos][buffer[pos]] );
}

bool check( int s, int t ){
    assert( s != t );
    map<string, bool>::iterator it, it2;


    for ( it = transformed[s].begin(); it != transformed[s].end(); it++ ){
	string str = (*it).first;
	if ( transformed[t][str] ) return true;


	}
    return false;

    for ( it = transformed[s].begin(); it != transformed[s].end(); it++ ){
	for ( it2 = transformed[t].begin(); it2 != transformed[t].end(); it2++ ){
	    if ( (*it).first == (*it2).first ) return true;
	}
    }

    return false;
}

bool search( int t, string str ){
    return transformed[t][str];
}

void compute(){
    set<pair<string, string> > ans;

    for ( int i = 0; i < n; i++ ) transform(i);

    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ){
	    if ( search( i, buffer[j] ) || search( j, buffer[i] ) ){
		if ( buffer[i] < buffer[j] ){
		    ans.insert( make_pair(buffer[i], buffer[j] ) );
		} else {
		    ans.insert( make_pair(buffer[j], buffer[i] ) );
		}
	    }
	    if ( d == 2 ){
		if ( check( i, j ) ){
		    if ( buffer[i] < buffer[j] ){
			ans.insert( make_pair(buffer[i], buffer[j] ) );
		    } else {
			ans.insert( make_pair(buffer[j], buffer[i] ) );
		    }
		}
	    }
	}
    }
    
    set<pair<string, string> >::iterator it;
    for ( it = ans.begin(); it != ans.end(); it++ ){
	cout << (*it).first << "," << (*it).second << endl;
    }
    cout << ans.size() << endl;



}

main(){
    while ( cin >> n, n ){
	cin >> d;
	for ( int i = 0; i < n; i++ ) cin >> buffer[i];
	compute();
    }
}
