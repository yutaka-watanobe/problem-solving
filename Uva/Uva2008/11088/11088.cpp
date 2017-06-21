#include<iostream>
using namespace std;

int n, S[15];
bool used[15];
int maxd;

int getMin(int s, int ex1, int ex2){
    int minj = -1;
    int minv = INT_MAX;
    for ( int j = s; j < n; j++ ){
	if ( used[j] || j == ex1 || j == ex2) continue;
	if ( S[j] < minv ){
	    minv = S[j];
	    minj = j;
	}
    }
    return minj;
}

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

    if ( maxv >= 20 ){
	int min1 = getMin(0, maxi, -1);
	if ( min1 == -1 ) return;
	int min2 = getMin(0, maxi, min1);
	if ( min2 == -1 ) return;
	used[min1] = used[min2] = used[maxi] = true;	    
	rec(d+1, rem - (S[min1] + S[min2] + S[maxi]));
	used[min1] = used[min2] = used[maxi] = true;	    
	return;
    }

    int sum;
    for ( int i = 0; i < n-1; i++ ){
	if ( used[i] || i == maxi ) continue;
	int j;

	if ( S[i] + S[maxi] >= 20 ){
	    int minj = getMin(i+1, maxi, -1);
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
