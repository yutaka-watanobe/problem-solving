import java.util.*;

class Main{
    
    boolean overlap(int a, int b, int c, int d){
	if ( d <= a ) return false;
	if ( b <= c ) return false;
	return true;
    }

    void solve(){
	Scanner sc = new Scanner(System.in);
	int a, b, s, f, n;
	a = sc.nextInt();
	b = sc.nextInt();
	n = sc.nextInt();
	for ( int i = 0; i < n; i++ ){
	    s = sc.nextInt();
	    f = sc.nextInt();
	    if ( overlap(a, b, s, f) ){
		System.out.println("1");
		return;
	    }
	}
	System.out.println("0");
    }

    public static void main(String[] args){ new Main().solve(); }
}

