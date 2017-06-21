// @JUDGE_ID:  17051CA  10530  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<string>
#include<algorithm>

bool M[11];

main(){
    string line;
    fill ( M, M + 11, false );
    int number;
    while ( 1 ){
	cin >> number; getline( cin, line );
	if ( number == 0 ) break;
	
	getline( cin, line );
	
	if ( line == "too high" ){
	    for ( int i = number; i < 11; i++ ) M[i] = true;
	}else if ( line == "too low" ){
	    for ( int i = number; i >= 0; i-- ) M[i] = true;
	}else if ( line == "right on" ){
	    if ( M[number] ) cout << "Stan is dishonest" << endl;
	    else cout << "Stan may be honest" << endl;
	    fill ( M, M + 11, false );
	}
    }
}
// @end_of_source_code
