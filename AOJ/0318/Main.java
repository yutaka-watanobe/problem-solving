import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	boolean[] A = new boolean[N+1];
	boolean[] B = new boolean[N+1];
	boolean[] C = new boolean[N+1];
	for ( int i = 1; i <= N; i++ ) A[i] = B[i] = C[i] = false;
	
	int k;
	k = sc.nextInt();
	for ( int i = 0; i < k; i++ ) A[sc.nextInt()] = true;
	k = sc.nextInt();
	for ( int i = 0; i < k; i++ ) B[sc.nextInt()] = true;
	k = sc.nextInt();
	for ( int i = 0; i < k; i++ ) C[sc.nextInt()] = true;

	int ans = 0;
	for ( int i = 1; i <= N; i++ ){
	    if (!A[i] && C[i] || B[i] && C[i]) ans++;
	}

	System.out.println(ans);
    }

    public static void main(String[] a){
	new Main().solve();
    }
}
