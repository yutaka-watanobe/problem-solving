#include<iostream>

using namespace std;
#define MAX 100000

int Y, P, L, T[MAX];

void compute(){
    int left, right;
    left = right = 0;
    int maxv = 1;
    int begin, end;
    begin = end = 0;
    while(1){
	if ( left == right && left == P-1 ) break;

	while ( right + 1 < P && T[right+1]-T[left] <= Y-1 ) right++;

	if ( maxv < right - left + 1 ){
	    maxv = right - left + 1;
	    begin = left;
	    end = right;
	}
	left++;
    }

    cout << maxv << " " << T[begin] << " " << T[end] << endl;

}

int main(){
    while( cin >> Y ) {
	cin >> P;
	for ( int i = 0; i < P; i++ ) cin >> T[i];
	compute();
    }
    return 0;
}
