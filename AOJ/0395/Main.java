import java.util.*;
import java.io.*;

class Main{
    int[] A, W;
    int N, a, w;
    List<Integer> R, L;

    int solve(){
	if ( R.size() == 0 || L.size() == 0 ) return 0;
	Collections.sort(R);
	Collections.sort(L);
	return R.get(0) + L.get(0);
    }

    void init() {
	A = new int[10];
	W = new int[10];
	R = new ArrayList<Integer>();
	L = new ArrayList<Integer>();
	Scanner sc = new Scanner(System.in);
	N = sc.nextInt();

	for ( int i = 0; i < N; i++ ) A[i] = sc.nextInt();
	for ( int i = 0; i < N; i++ ) W[i] = sc.nextInt();
	for ( int i = 0; i < N; i++ ){
	    if ( A[i] == 0 ) R.add(W[i]);
	    if ( A[i] == 1 ) L.add(W[i]);
	}
	System.out.println(solve());
    }

    public static void main(String[] a){ new Main().init(); }

}

