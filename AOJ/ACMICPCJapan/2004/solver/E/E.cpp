#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#define MAX 200
using namespace std;

class String{
public:
  char str[20]; 
  int len;
  String(){}

  bool operator < ( const String &s ) const {
    int l = min( strlen(str), strlen(s.str) );
    for ( int i = 0; i < l; i++ ){
      if ( str[i] == s.str[i] ) continue;
      return str[i] < s.str[i];
    }
    return strlen(str) < strlen(s.str);
  }
};

int n, d;
String buffer[MAX];
set<String> transformed[MAX];

void transform(int pos){
    transformed[pos] = set<String>();

    String target;
    String source = buffer[pos];
    // delete
    for ( int i = 0; i < source.len; i++ ){
	int s = 0;
	for ( int j = 0; j < source.len; j++ ){
	    if ( j == i ) continue;
	    target.str[s++] = source.str[j];
	}
	target.len = source.len-1;
	transformed[pos].insert(target);
    }

    // insert
    for ( char ch = 'a'; ch <= 'z'; ch++ ){
	for ( int i = 0; i <= source.len; i++ ){
	    int s = 0;
	    for ( int j = 0; j < source.len; j++ ){
		if ( j == i ){
		    target.str[s++] = ch;
		}
		target.str[s++] = source.str[j];
	    }
	    target.len = source.len+1;
	    transformed[pos].insert(target);
	}
    }
    // replace
    for ( char ch = 'a'; ch <= 'z'; ch++ ){
	for ( int i = 0; i < source.len; i++ ){
	    if ( source.str[i] == ch ) continue;
	    for ( int j = 0; j < source.len; j++ ){
		target.str[j] = source.str[j];
		if ( i == j )  target.str[j] = ch;
	    }
	    transformed[pos].insert(target);
	}
    }
    // swap
    for ( int i = 0; i < source.len-1; i++ ){
	if ( source.str[i] == source.str[i+1] ) continue;
	for ( int j = 0; j < source.len; j++ ) target.str[j] = source.str[j];
	char tmp = target.str[i];
	target.str[i] = target.str[i+1];
	target.str[i+1] = tmp;
	transformed[pos].insert(target);
    }

    assert( transformed[pos].find( buffer[pos] ) == transformed[pos].end() );
}

bool check( int s, int t ){
    assert( s != t );
    set<String>::iterator it, it2;

    for ( it = transformed[s].begin(); it != transformed[s].end(); it++ ){
	if ( transformed[t].find(*it) != transformed[t].end() ) return true;
    }
    return false;
}

bool search( int t, String str ){
    if ( transformed[t].find( str ) != transformed[t].end() ) return true;
    else return false;
}

void compute(){
    set<pair<String, String> > ans;

    for ( int i = 0; i < n; i++ ) transform(i);

    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ){
	    if ( search( i, buffer[j] )  ){
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
    
    set<pair<String, String> >::iterator it;
    for ( it = ans.begin(); it != ans.end(); it++ ){
      //cout << (*it).first << "," << (*it).second << endl;
      printf("%s,%s\n", (*it).first.str, (*it).second.str);
    }
    cout << ans.size() << endl;
}

main(){
    while ( cin >> n, n ){
	cin >> d;
	for ( int i = 0; i < n; i++ ) {
	  scanf("%s", buffer[i].str );
	  buffer[i].len = strlen(buffer[i].str);
	}
	compute();
    }
}




