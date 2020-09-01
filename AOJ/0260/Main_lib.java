import java.util.*;

class Main{
    void solve (){
	int n;
	long totalp, totalj;
	long[] P;
	long[] J;
	Scanner sc = new Scanner(System.in);
	while(true){
	    n = sc.nextInt();
	    if ( n == 0 ) break;
	    P = new long[n];
	    J = new long[n];
	    totalp = 0;
	    for ( int i = 0; i < n; i++ ) {
		P[i] = sc.nextLong();
		totalp += P[i];
	    }
	    for ( int i = 0; i < n-1; i++ ) {
		J[i] = sc.nextLong();
	    }
	    
	    long maxv = 0;
	    Arrays.sort(J);
	    totalj = 0;
	    for ( int j = 0, t = n; t >= 1; t--, j++ ){
		long v = t*(totalj + totalp);
		totalj += J[n-1-j];
		maxv = Math.max(v, maxv);
	    }
	    System.out.println(maxv);
	}
    }

    public static void main(String[] args){
	new Main().solve();
    }
}
