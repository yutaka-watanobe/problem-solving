#include<iostream>
#include<map>

using namespace std;

int k, m, c, r;

main(){
    map<int, bool> courses;
    int id;
    while( cin >> k && k ){
	cin >> m;
	courses = map<int, bool>();
	int pass = true;
	for ( int i = 0; i < k; i++ ){
	    cin >> id;
	    courses[id] = true;
	}

	for ( int i = 0; i < m; i++ ){
	    cin >> c >> r;
	    int sum = 0;
	    for ( int j = 0; j < c; j++ ){
		cin >> id;
		if ( courses[id] ) sum++;
	    }
	    if ( sum < r ) pass = false;
	}
	cout << ((pass) ? "yes" : "no") << endl;
    }
}
