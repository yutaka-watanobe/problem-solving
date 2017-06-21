#include<iostream>
#include<string>
#include<map>

using namespace std;

bool isConsonant( char ch ){
    return !(ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' );
}

main(){
    int L, N;
    string str, str1, str2;
    cin >> L >> N;
    map<string, string> D;

    for ( int i = 0; i < L; i++ ){
	cin >> str1 >> str2;
	D[str1] = str2;
    }


    for ( int i = 0; i < N; i++ ){
	cin >> str;
	int size = str.size();
	if ( D.find(str) != D.end() ){
	    cout << D[str] << endl;
	} else if ( size > 2 && str[size-1] == 'y' && isConsonant(str[size-2]) ){
	    cout << str.substr(0, size-1) << "ies" << endl;
	} else if ( str[size-1] == 'o' ||
		    str[size-1] == 's' ||
		    str[size-1] == 'x' ||
		    (size > 2 && str[size-2] == 'c' && str[size-1] == 'h')||
		    (size > 2 && str[size-2] == 's' && str[size-1] == 'h') ){
	    cout << str << "es" << endl;
	} else {
	    cout << str << "s" << endl;
	}

    }

}
