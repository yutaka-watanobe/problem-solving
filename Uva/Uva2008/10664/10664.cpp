#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAX 20

int D[MAX], size, target;

bool rec(int depth, int sum){
    if ( sum == target ) return true;
    if ( depth == size ) return false;

    if ( rec( depth+1, sum ) ) return true;
    if (rec( depth+1, sum+D[depth] ) ) return true;

    return false;
}

bool compute(){
    int sum = 0;
    for ( int i = 0; i < size; i++ ) sum += D[i];

    if ( sum % 2 != 0 ) return false;
    target = sum/2;

    return rec(0, 0);
}

int main(){
    int tcase; cin >> tcase;
    string line;
    getline( cin, line );
    for ( int i = 0; i < tcase; i++ ){
	getline( cin, line );
	stringstream sin(line);
	size = 0;
	while( sin >> D[size] ) size++;
	if (compute() ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }

    return 0;
}
