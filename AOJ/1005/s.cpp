 #include<iostream>
 using namespace std;
 #define rep(i,n) for ( int i = 0; i < n; i++ )
 
 int main(){
     int n;
     int T[100][100], L[100][100], R[100][100];
     while( cin >> n && n){
 	rep(i, n) rep(j, n) { cin >> T[i][j]; L[i][j] = R[i][j] = 0; }
 	rep(i, n){
 	    int mj = 0;
 	    rep(j, n) if ( T[i][mj] >= T[i][j] ) mj = j;
 	    L[i][mj]++;
 	}
 	rep(j, n){
 	    int mi = 0;
 	    rep(i, n) if ( T[mi][j] <= T[i][j] ) mi = i;
 	    R[mi][j]++;
 	}
 	int ans = 0;
 	rep(i, n) rep(j, n) if ( R[i][j]+L[i][j] == 2 ) ans = T[i][j];
 	cout << ans << endl;
     }
     return 0;
 }
