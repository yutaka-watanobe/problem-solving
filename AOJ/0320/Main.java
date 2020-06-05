import java.util.*;

class Main{
    
    char[][] G;
    int N;

    int next(int i){ return ((N-i-1)+N)%N;}

    boolean getState(int i, int j){
	return  G[i][j] == G[i][next(j)] &&
	    G[i][j] == G[next(i)][j] &&
	    G[i][j] == G[next(i)][next(j)];
    }
    
    int getInit(){
	int i, j, dcnt = 0;
	for ( i = 0; i < N/2; i++ ){
	    for ( j = 0; j < N/2; j++ ){
		if (!getState(i, j)) dcnt++;
	    }
	}
	return dcnt;
    }
    
    void solve(){
	Scanner sc = new Scanner(System.in);
	int dcnt;
	int ans = 0;
	int C = sc.nextInt();
	N = sc.nextInt();

	G = new char[N][N];
	
	for ( int i = 0; i < N; i++ ){
	    String str = sc.next();
	    for ( int j = 0; j < N; j++ ){
		G[i][j] = str.charAt(j);
	    }
	}
	
	dcnt = getInit();
	if (dcnt == 0 ) ans++;
	for ( int i = 0; i < C-1; i++ ){
	    int k = sc.nextInt();
	    for ( int j = 0; j < k; j++ ){
		int r = sc.nextInt();
		int c = sc.nextInt();
		r--; c--;
		boolean pre = getState(r, c);
		G[r][c] = G[r][c]=='1'?'0':'1';
		boolean post = getState(r, c);
		if ( !pre && post ) dcnt--;
		else if ( pre && !post ) dcnt++;
	    }
	    if ( dcnt == 0 ) ans++;
	}

	System.out.println(ans);
    }

    public static void main(String[] args){
	new Main().solve();
    }
}
