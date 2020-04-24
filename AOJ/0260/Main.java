import java.util.*;

class Main{
    static final int MAX = 65000;

    void solve (){
	long n, totalp, totalj;
	long[] P = new long[MAX];
	long[] J = new long[MAX];
	int tcase = 0;
	Scanner sc = new Scanner(System.in);
	while(true){
	    n = sc.nextLong();
	    if ( n == 0 ) break;
	    tcase++;
	    totalp = 0;
	    for ( int i = 0; i < n; i++ ) {
		P[i] = sc.nextLong();
		totalp += P[i];
	    }
	    for ( int i = 0; i < n-1; i++ ) {
		J[i] = sc.nextLong();
	    }
	    
	    long maxv = 0;
	    sort(J, J+(n-1));
	    reverse(J, J+(n-1));
	    totalj = 0;
	    for ( long j = 0, t = n; t >= 1; t--, j++ ){
		long v = t*(totalj + totalp);
		totalj += J[j];
		maxv = max(v, maxv);
	    }
	    System.out.println(maxv);
	}
    }

    public static void main(String[] args){
	new Main().solve();
    }
}
