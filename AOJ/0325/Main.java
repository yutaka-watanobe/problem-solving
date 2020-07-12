import java.util.*;

class Main{

    boolean check(){
	int N = 6;
	Scanner sc = new Scanner(System.in);
	int[] D = new int[N];
	int M = 10000;
	int h, w;
	for ( int i = 0; i < N; i++ ) {
	    h = sc.nextInt();
	    w = sc.nextInt();
	    // sortが使えるように長方形を整数であらわす
	    D[i] = M * Math.min(h, w) + Math.max(h, w);
	}
	Arrays.sort(D);
	for ( int i = 0; i < N; i += 2){
	    if ( D[i] != D[i+1] ) return false;
	}
	
	return D[0]/M == D[2]/M && D[0]%M == D[4]/M && D[2]%M == D[4]%M;
    }
    
    void solve(){
	if ( check() ) System.out.println("yes");
	else System.out.println("no");
    }
    
    public static void main(String[] args){ new Main().solve(); }
}


