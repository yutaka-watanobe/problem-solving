import java.util.*;

class Main{
    static final int MAX = 300000;
    boolean[] T;
    int[] L;

    void solve(){
	int N, Q, q, x;
	T = new boolean[MAX+1];
	L = new int[MAX+1];

	Scanner sc = new Scanner(System.in);
	N = sc.nextInt();
	Q = sc.nextInt();
	
	for ( int i = 0; i < N; i++ ) {
	    x = sc.nextInt();
	    T[x] = true;
	}

	int m = 0;
	for ( int i = 1; i <= MAX; i++ ){
	    L[i] = m;
	    if ( T[i] ) m = i;
	}

	for ( int i = 0; i < Q; i++ ){
	    q = sc.nextInt();
	    int maxv = 0;
	    int cur = m;
	    while(cur > 0){
		int p = cur%q;
		maxv = Math.max(maxv, p);
		if ( cur - p < 0 ) break;
		cur = L[cur - p];
	    }
	    System.out.println(maxv);
	}
    }

    public static void main(String[] args){ new Main().solve(); }
}
