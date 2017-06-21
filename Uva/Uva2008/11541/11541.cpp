#include<iostream>
#include<string>

using namespace std;

int main(){
    int tcase; cin >> tcase;
    string str;
    for ( int c = 1; c <= tcase; c++ ){
	cout << "Case " << c << ": ";
	cin >> str;
	int i = 0; 
	while( i < str.size() ){
	    char ch = str[i++];
	    int n  = 0;
	    while(1){
		if ( i >= str.size() || isalpha(str[i]) ) break;
		n *= 10; n += str[i++]-'0';
	    }
	    for ( int j = 0; j < n; j++ ) cout << ch;
	}
	cout << endl;
    }
    return 0;
}

