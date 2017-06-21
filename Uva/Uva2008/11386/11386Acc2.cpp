#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 5000
#define HMAX 13239
typedef  long long ullong;

struct Pair{
    int first, second;
    bool operator < ( const Pair &p ) const{
	return first < p.first;
    }
};

int N, size;
int T[MAX];

Pair P[MAX];
Pair HT[HMAX];
int binarySearch( int left, int right, int target ){
     int h = target%HMAX;
     if ( HT[h].first == target ) {
	 return HT[h].second;
     }
     int mid;
    while( left < right ){
	mid = (left + right ) / 2;
	if ( P[mid].first == target ) return P[mid].second;
	if ( P[mid].first < target ) left = mid+1;
	else right = mid;
    }

    return 0;
}

void compute(){
    ullong counter = 0;
    int is, ie;

    for ( int j = size-2; j >= 1; j-- ){
	is = distance(T, lower_bound(T, T+(j), T[j+1] - T[j]));
	ie = distance(T, lower_bound(T, T+(j), T[size-1] - T[j]));
	if ( ie >= j ) ie = j-1;
	if ( is < 0 ) is = 0;
	for ( int i = is; i <= ie; i++ ){
	    counter += (P[i].second*P[j].second*binarySearch( j+1, size, P[i].first + P[j].first ));
	}
    }

    for ( int i = 0; i < size-1; i++ ){
	if ( P[i].second < 2 ) continue;
	ullong n = P[i].second;
	n = n*(n-1)/2;
	counter += (n*binarySearch(i+1, size, P[i].first*2));
	}

    printf("%lld\n", counter);
}

void construct(){
    sort( T, T + N );
    ullong pre = T[0];
    P[0].first = pre; P[0].second = 1;
    size = 1;

    for ( int i = 1; i < N; i++ ){
	if ( pre == T[i] ) P[size-1].second++;
	else {
	    size++;
	    P[size-1].first = T[i];
	    P[size-1].second = 1;

	    pre = T[i];
	}
    }

    for ( int i = 0; i < size; i++ ){
	T[i] = P[i].first;
    }


  for ( int i = 0; i < HMAX; i++ ){
	HT[i].first = -1;
	HT[i].second = 0;
    }

    for ( int i = 0; i < size; i++ ){
	int h = P[i].first % HMAX;
	if ( HT[h].first == -1 ){
	    HT[h] = P[i];
	}
	}

}

int main(){
    while( scanf("%d", &N) != EOF ){
	for ( int i = 0; i < N; i++ ) scanf("%d", &T[i]);
	construct();
	compute();
    }

    return 0;
}
