#include<iostream>

using namespace std;
main(){
    long long t, tf, S[1000001];

    tf = S[3] = 0;

    for ( int i = 4; i <= 1000000; i++ ){
	t = tf;
	t += ((i-2)/2);
	S[i] = S[i-1];
	S[i] += t;
	tf = t;
    }
    int tcase; scanf("%d", &tcase);
    int n;
    for ( int i = 0; i < tcase; i++ ) {
	scanf("%d", &n);
	cout << S[n] << endl;
    }
}
