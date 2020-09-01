import java.util.*;

class Main{
    static final int MAX = 65000;
    void merge(long[] J, int l, int m, int r){
	long[] T = new long[MAX];
	int i, j, k;
	for ( i = l; i < m; i++ ) T[i] = J[i];
	for ( i = m; i < r; i++ ) T[(r-1)-(i-m)] = J[i];
	i = l;
	j = r - 1;
	for ( k = l; k < r; k++ ){
	    if ( T[i] >= T[j] ) J[k] = T[i++];
	    else J[k] = T[j--];
	}
    }
    
    void mergeSort(long[] J, int l, int r){
	if ( l+1 >= r ) return;
	int m = (l+r)/2;
	mergeSort(J, l, m);
	mergeSort(J, m, r);
	merge(J, l, m, r);
    }
    
    void solve (){
	int n;
	long totalp, totalj;
	long[] P, J;
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
	    for ( int i = 0; i < n-1; i++ ) J[i] = sc.nextLong();

	    mergeSort(J, 0, n-1);  	    //Arrays.sort(J);

	    long maxv = 0;
	    totalj = 0;
	    for ( int j = 0, t = n; t >= 1; t--, j++ ){
		long v = t*(totalj + totalp);
		totalj += J[j];
		maxv = Math.max(v, maxv);
	    }
	    System.out.println(maxv);
	}
    }

    public static void main(String[] args){ new Main().solve(); }
}
