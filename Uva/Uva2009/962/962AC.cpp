#include<iostream>
#include<map>
#include<set>

using namespace std;
#define LIMIT 2005

int main(){
    map<long long, int > s;
    set<long long> num;
    int cnt = 0;

    long long P[LIMIT+1];
    for ( long long i = 1; i <= LIMIT; i++ ) P[i] = i*i*i;

    for ( long long i = 1; i <= LIMIT; i++ ){
	for ( long long j = i; j <= LIMIT; j++ ){
	    long long n = P[i] + P[j];
	    if ( n > 1000100000LL ) continue;
	    if ( s[n] == 0 ) {
		s[n] = 1;
	    } else if ( s[n] == 1 ) {
		s[n] = 2;
		num.insert(n);
	    }
	}
    }

    long long T[2000];
    int size = 1;
    T[0] = -1;
    set<long long>::iterator it;
    for ( it = num.begin(); it!=num.end(); it++ ){
	T[size++] = *it;
    }
    T[size++] = INT_MAX;

    /*
    long long pre = 0;
    for ( it = num.begin(); it!=num.end(); it++ ){
	
    	//cout << (*it) << endl;
	cout << *it - pre << endl;
	pre = (*it);
	}*/


	

    long long a, d;
    while( cin >> a >> d ){
	int l = 0;
	int r = size-1;
	while( T[l] < a ) l++;
	while( T[r] > a+d ) r--;
	
	if ( l > r ) cout << "None" << endl;
	else {
	    for ( int i = l; i <= r; i++ ) cout << T[i] << endl;
	}

    }

    /*
    while(cin >> a >> d){
	set<long long>::iterator it1;
	set<long long>::iterator it2;
	it1 = lower_bound( num.begin(), num.end(), a);
	it2 = upper_bound( num.begin(), num.end(), a+d);
	//	cout << distance(it1, it2) << endl;

	if ( it1 == it2 ) {
	    cout << "None" << endl; continue;
	}
	it2--;

	//cout << "t " << *it1 << " " << *it2 << endl;
	int cnt = 0;
	for ( it = it1; ; it++ ) {
	    cout << *it << endl;
	    if ( it == it2 ) break;
	    cnt++;
	}

	if ( cnt == 0 ) cout << "None" << endl;
	}*/
    return 0;

}
