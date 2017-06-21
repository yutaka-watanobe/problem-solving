#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000

int n, L, P[MAX+1], v[(MAX+1)*(MAX+1)];

void compute(){
    int size = 0;
    for ( int i = 0; i < n+1; i++ ){
	for ( int j = i; j < n+1; j++ ){
	    v[size++] = P[i] + P[j];
	}
    }
    sort(v, v + size);
    int maxv = 0;

    for ( int i = 0; i < size; i++ ){
	if ( v[i] > L ) break;
	int first = v[i];
	int target = L - v[i];
	
	int t = distance(v, upper_bound(v, v + size, target));

	if ( v[t] + first <= L && maxv < v[t]+first ) maxv = v[t]+first;
	if ( t+1 <size && v[t+1] + first <= L && maxv < v[t+1]+first ) maxv = v[t+1]+first;
	if ( t-1 >= 0 && v[t-1] + first <= L && maxv < v[t-1]+first ) maxv = v[t-1]+first;
    }
    cout << maxv << endl;
}

main(){
    while( cin >> n >> L && n ){
	P[0] = 0;
	for ( int i = 1; i <= n; i++ ) cin >> P[i];
	compute();
    }
}
