#include<iostream>
#include<cmath>

using namespace std;
typedef unsigned long long llong;

long long N;

llong computeBF(){
    llong n = N/2;
    llong sum = 0;
    sum += n;
    for ( int i = 1; i < n; i++ ){
	llong h = (llong)ceil( 1.0*n/i );
	sum += h;
    }
    return 8*sum;
}

llong compute(){
    llong n = N/2;
    llong rn = (llong)ceil(sqrt(n));
    llong sum = 0;
    sum += n;
    for ( int i = 1; i < rn; i++ ){
	sum += (llong)ceil(1.0*n/i);
    }
    sum *= 2;
    sum -= rn*rn;
    return 8*sum;

}

int main(){
    while( cin >> N && N ){
	cout << compute() << endl;
    }

    return 0;
}
