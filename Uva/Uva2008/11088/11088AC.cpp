#include<iostream>
using namespace std;

int n, S[15];
bool used[15];
int maxd;

void rec( int d, int rem ){
    maxd = max( d, maxd );

    int maxi = -1;
    int maxv = -1;
    for ( int i = 0; i < n; i++ ){
	if ( used[i] ) continue;
	if ( maxv < S[i] ){
	    maxv = S[i]; maxi = i;
	}
    }

    if ( rem < 20 ) return;
    if ( maxi == -1 ) return;

    int sum;
    for ( int i = 0; i < n-1; i++ ){
	if ( used[i] || i == maxi ) continue;
	int j;

	if ( S[i] + S[maxi] >= 20 ){
	    int minj = -1;
	    int minv = INT_MAX;
	    for ( j = i+1; j < n; j++ ){
		if ( used[j] || j == maxi) continue;
		if ( S[j] < minv ){
		    minv = S[j];
		    minj = j;
		}
	    }
	    if ( minj == -1 ) continue;
	    sum = S[i] + S[minj] + S[maxi];
	    if ( sum>= 20 ){
		used[i] = used[minj] = used[maxi] = true;	    
		rec(d+1, rem - sum);
		used[i] = used[minj] = used[maxi] = false;	    
	    }
	    continue;
	}



	for ( j = i+1; j < n; j++ ){
	    if ( used[j] || j == maxi) continue;
	    sum = S[i] + S[j] + S[maxi];
	    if ( sum>= 20 ){
		used[i] = used[j] = used[maxi] = true;	    
		rec(d+1, rem - sum);
		used[i] = used[j] = used[maxi] = false;	    
	    }
	}


    }
}

void compute(){
    maxd = 0;
    for ( int i = 0; i < n; i++ ) used[i] = false;
    int sum = 0;
    for ( int i = 0; i < n; i++ ) sum += S[i];
    rec(0, sum);
    cout << maxd << endl;
}

int main(){
    int t = 1;
    while( cin >> n && n ){
	cout << "Case " << t << ": ";
	t++;
	for ( int i = 0; i < n; i++ ) cin >> S[i];
	compute();
    }

    return 0;
}
