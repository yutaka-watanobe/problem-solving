#include<iostream>
#include<vector>
using namespace std;

main(){
    double x;
    int a;
    double b;

    while(1){
	cin >> x;
	if ( x < 0 ) break;
	a = (int)x;
	b = x - a;
	vector<int> A, B;
	while(a){ A.push_back(a%2); a /= 2; }
	while(b >= 1.0) b /= 10;
	while(b){ 
	    b *= 2;
	    if ( b >= 1.0 ){ B.push_back(1); b -= 1; }
	    else B.push_back(0);
	    if ( B.size() > 4 ) break;
	}
	while( A.size() < 8 ) A.push_back(0);
	while( B.size() < 4 ) B.push_back(0);
	if ( A.size() > 8 || B.size() > 4 ) cout << "NA" << endl;
	else {
	    for ( int i = A.size()-1; i >= 0; i-- ) cout << A[i];
	    cout << ".";
	    for ( int i = 0; i < B.size(); i++ ) cout << B[i];
	    cout << endl;
	}
    }
    
}
