import java.util.*;

class Main{
    int N, cnt;
    int[] A;
    boolean[] S;

    long gcd(long x, long y){
	long r, t;
	if ( x < y ) { t = x; x = y; y = t; }
	while( y > 0 ){
	    r = x % y;
	    x = y;
	    y = r;
	}
	return x;
    }
    long lcm(long x, long y){
	return x/gcd(x, y)*y;
    }
  
    void rec(int p, long LCM, int sum){
	boolean ok;
	if ( p == N ){
	    ok = (sum > 0);
	    for ( int i = 0; i < N; i++ ){
		if ( LCM >= A[i] && LCM % A[i] == 0 ){
		    if ( S[i] == false ) ok = false;
		}
	    }
	    if ( ok ) cnt++;
	    return;
	}
	S[p] = true;
	rec(p+1, lcm(LCM, A[p]), sum+1);
	S[p] = false;
	rec(p+1, LCM, sum);
    }
    
    void solve(){
	Scanner sc = new Scanner(System.in);
	A = new int[20];
	S = new boolean[20];
	N = sc.nextInt();
	for ( int i = 0; i < N; i++ ) A[i] = sc.nextInt();
	cnt = 0;
	rec(0, 1, 0);
	System.out.println(cnt);
    }

    public static void main(String[] args){
	new Main().solve();
    }
}
	
    
