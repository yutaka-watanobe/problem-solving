// @author yutaka C++
// String + Set
#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string> departures;

void insert( string line1, int reversal1, string line2, int reversal2 ){
    if ( reversal1 ) reverse( line1.begin(), line1.end() );
    if ( reversal2 ) reverse( line2.begin(), line2.end() );
    departures.insert( line1 + line2 );
}

void compute(){
    string arrival, storage1, storage2;
    cin >> arrival;

    departures.clear();

    for ( int d = 0; d < arrival.size() - 1; d++ ){
	storage1 = arrival.substr(0, d + 1);
	storage2 = arrival.substr(d + 1, arrival.size() - d - 1 );

	insert( storage1, 0, storage2, 0 );
	insert( storage1, 0, storage2, 1 );
	insert( storage1, 1, storage2, 0 );
	insert( storage1, 1, storage2, 1 );
	insert( storage2, 0, storage1, 0 );
	insert( storage2, 0, storage1, 1 );
	insert( storage2, 1, storage1, 0 );
	insert( storage2, 1, storage1, 1 );
    }

    cout << departures.size() << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}
