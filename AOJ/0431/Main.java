import java.util.Scanner;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] A = new int[N];
	for ( int i = 0; i < N; i++ ) A[i] = sc.nextInt();
	int maxr = 0, cnt = 0;
	for ( int i = N - 1; i >= 0; i-- ){
	    if ( A[i] > maxr ) cnt++;
	    maxr = Math.max(A[i], maxr);
	}
	System.out.println(cnt);
    }
    public static void main(String[] argv){ new Main().solve(); }
}
