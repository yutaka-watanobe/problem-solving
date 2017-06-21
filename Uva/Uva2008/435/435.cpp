#include<iostream>
using namespace std;
#define MAX 20

int size, V[MAX], C[MAX];
bool used[MAX];
int target;

void recursive( int depth, int sum ){
    if ( depth >= size ){
	for ( int i = 0; i < size; i++ ){
	    if ( !used[i] || sum < target )  continue;
	    if ( sum - V[i] < target ) C[i]++;
	}
	return;
    }

    recursive( depth+1, sum );

    used[depth] = true;
    recursive( depth+1, sum + V[depth] );
    used[depth] = false;
}

void compute(){
    for ( int i = 0; i < size; i++ ) { C[i] = 0; used[i] = false;}
    int sum = 0;
    for ( int i = 0; i < size; i++ ) sum += V[i];
    target = (sum+2)/2;

    recursive(0, 0);

    for ( int i = 0; i < size; i++ ){
	cout << "party " << i+1 << " has power index " << C[i] << endl;
    }
    cout << endl;
}

void input(){
    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> V[i];
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
    return 0;
}
