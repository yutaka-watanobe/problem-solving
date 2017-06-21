#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

bool judge(int x, string y){
    if ( x % 3 == 0 && x % 5 == 0 ) return y == "FizzBuzz";
    if ( x % 3 == 0 ) return y == "Fizz";
    if ( x % 5 == 0 ) return y == "Buzz";
    if ( !isdigit(y[0]) ) return false;
    return x == atoi(y.c_str());
}

main(){
    int m, n;
    string num;
    while(1){
	cin >> m >> n;
	if ( m == 0 && n == 0 ) break;
	vector<int> P;
	int cur = 0, w = -1;
	for ( int i = 1; i <= m; i++ ) P.push_back(i);
	for ( int i = 1; i <= n; i++ ){
	    cin >> num;
	    if ( w != -1 ) continue;
	    if ( judge(i, num) ) cur++;
	    else P.erase(P.begin() + cur);
	    cur = cur%P.size();
	    if ( P.size() == 1 ) w = P[0];
	}
	if ( w != -1 ) cout << w << endl;
	else {
	    for ( int i = 0; i < P.size(); i++ ){
		if ( i ) cout << " ";
		cout << P[i];
	    }
	    cout << endl;
	}
    }
}
