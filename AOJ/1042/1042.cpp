#include<iostream>
#include<string>
#include<cstring>
using namespace std;

main(){
    string line;
    while(1){
	getline( cin, line );
	if ( line == "END OF INPUT" ) break;

	int cnt = 0;
	for ( int i = 0; i < line.size(); i++ ){
	    if ( line[i] == ' ' ) {
		cout << cnt; cnt = 0;
	    } else {
		cnt++;
	    }
	}
	cout << cnt << endl;

    }
}
