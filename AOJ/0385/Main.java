import java.util.*;
class Main{
    static final int INF = 2000000000;
    int N, diff;
    int[] A;
    Scanner sc;
    
    void update(int i, int v){
	if ( A[i-1] > A[i] ) diff--;
	if ( A[i] > A[i+1] ) diff--;
	A[i] = v;
	if ( A[i-1] > A[i] ) diff++;
	if ( A[i] > A[i+1] ) diff++;
    }
    
    void solve(){
	sc = new Scanner(System.in);
	N = sc.nextInt();
	A = new int[N+2];
	for ( int i = 1; i <= N; i++ )  A[i] = sc.nextInt();
	A[0] = -INF;
	A[N+1] = INF;
	System.out.println(solve());
    }
    
    int solve(){
	int a, b, q, v1, v2;
	diff = 0;
	for ( int i = 1; i <= N; i++ ) 
	    if ( A[i-1] > A[i] ) diff++;

	if ( diff == 0 ) return 0;
	q = sc.nextInt();
	for ( int i = 1; i <= q; i++ ){
	    a = sc.nextInt();
	    b = sc.nextInt();
	    v1 = A[a];
	    v2 = A[b];
	    update(a, v2);
	    update(b, v1);
	    if ( diff == 0 ) return i;
	}
	
	return -1;
    }

    public static void main(String[] args){ new Main().solve(); }
}

