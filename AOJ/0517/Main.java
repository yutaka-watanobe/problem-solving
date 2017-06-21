


import java.util.*;

class Main{
    int[] T, L, R;
    int n, k;
    boolean hasEmpty;

    public Main(){
	Scanner sc = new Scanner(System.in);
	int x;

	T = new int[100001];
	L = new int[100002];
	R = new int[100002];

	while(true){
	    n = sc.nextInt();
	    k = sc.nextInt();
	    if ( n == 0 && k == 0 ) break;

	    for ( int i = 1; i <= 100000; i++ ) T[i] = 0;
	    
	    hasEmpty = false;
	    for ( int i = 0; i < k; i++ ){
		x = sc.nextInt();
		T[x] = 1;
		if ( x == 0 ) hasEmpty = true;
	    }
	    System.out.println(compute());
	}
    }

    int compute(){
	T[0] = 0;
	
	for ( int i = 1; i <= n; i++ ) L[i] = R[i] = 0;
	
	L[0] = L[n+1] = 0;
	R[0] = R[n+1] = 0;
	
	for ( int i = 1; i <= n; i++ ){
	    if ( T[i] == 0 ) L[i] = 0;
	    else L[i] += L[i-1] + 1;
	}
	for ( int i = n; i >= 1; i-- ){
	    if ( T[i] == 0 ) R[i] = 0;
	    else R[i] += R[i+1] + 1;
	}

	int maxv = 0;
	for ( int i = 1; i <= n; i++ ) {
	    if ( maxv < L[i] ) maxv = L[i];
	}
	
	if ( hasEmpty ){
	    for ( int i = 1; i <= n; i++ ) {
		if ( T[i] == 0 ){
		    if ( maxv <  L[i-1] + R[i+1] + 1){
			maxv = L[i-1] + R[i+1] + 1;
		    }
		}
	    }
	}
	
	return maxv;
    }

    public static void main(String[] a){
	new Main();
    }
}
