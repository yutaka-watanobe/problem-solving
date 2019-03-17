import java.util.*;


class Main{
    int N, M, h, m, t;
    int[] A, B, C;

    void solve(){
	Scanner sc = new Scanner(System.in);

	N = sc.nextInt();
	A = new int[N+1];
	for ( int i = 0; i < N; i++ ){
	    h = sc.nextInt();
	    m = sc.nextInt();
	    A[i] = h*60 + m;
	}
	M = sc.nextInt();
	B = new int[M+1];
	for ( int i = 0; i < M; i++ ){
	    h = sc.nextInt();
	    m = sc.nextInt();
	    B[i] = h*60 + m;
	}

	int a = 0, b = 0, k = 0;
	A[N] = B[M] = 24*60;

	C = new int[N+M];

	for ( int i = 0; i < N+M; i++ ){
	    int t;
	    if ( A[a] <= B[b] ) t = A[a++];
	    else t = B[b++];
	    if ( k == 0 ) C[k++] = t;
	    else if ( C[k-1] != t ) C[k++] = t;
	}

	for ( int i = 0; i < k; i++ ){
	    if ( i > 0 ) System.out.print(" ");
	    h = C[i]/60;
	    m = C[i]%60;
	    System.out.print(h + ":");
	    if ( m < 10 ) System.out.print("0");
	    System.out.print(m);
	}
	System.out.println();
    }

    public static void main(String[] a){
	new Main().solve();
    }
}
