#include<iostream>
#define SIZE 1000000
using namespace std;

// begin_of_source
void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    // Šï”‚ð‘f”‚ÌŒó•â‚Æ‚·‚é
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    // ‡¬”‚Å‚È‚¢Šï”‚¾‚¯‚ðŽc‚·
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	// i ‚Í‘f”@i ‚Ì”{”‚ð‚·‚×‚ÄÁ‚·
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
}
// end_of_source

main(){
    bool prime[SIZE + 1];
    clock_t start, finish;
    start = clock();
    eratos( SIZE, prime );
    finish = clock();
    printf("%f seconds\n", ((double)(finish - start)/1000000));
    /*
    for ( int i = 0; i < SIZE; i++ ) {
	if ( prime[i] ) cout << i << endl;
    }
    */
}
