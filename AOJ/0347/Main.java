import java.util.*;

class Main{
    void solve(){
	int n;
	int[] S;
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	S = new int[n];
	for ( int i = 0; i < n; i++ ) S[i] = sc.nextInt();

	double res = 0.0;
	Arrays.sort(S);

	for ( int d = 0; d < n-1; d++ ){
	    int c = d+1;
	    int a = n-1;
	    int b = n-2;
	    if ( d == n-3 ){
		b = d-1;
	    } else if ( d == n-2 ){
		a = d-2;
		b = d-1;
	    }
	    res = Math.max(res, 1.0*(S[a]+S[b])/(S[c]-S[d]));
	}

	System.out.println(String.format("%.8f", res));
    }

    public static void main(String[] args){
	new Main().solve();
    }
	
}
