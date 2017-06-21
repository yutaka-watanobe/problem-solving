#include<iostream>
#include<algorithm>
using namespace std;
#define N 10

main(){
    int sum1, sum2;
    int S[N];
    for ( int i = 0; i < N; i++ ) cin >> S[i];
    sort( S, S + N );
    sum1 = S[N-1] + S[N-2] + S[N-3];
    for ( int i = 0; i < N; i++ ) cin >> S[i];
    sort( S, S + N );
    sum2 = S[N-1] + S[N-2] + S[N-3];
    cout << sum1 << " " << sum2 << endl;
    
}
