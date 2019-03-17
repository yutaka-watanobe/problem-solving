import java.util.*;

class Main{
    int[] cnt;

    boolean check(){
	for ( int i = 0; i <= 100; i++ ) if ( cnt[i] % 4 > 0 ) return false;
	return true;
    }
    
    void solve(){
	Scanner sc = new Scanner(System.in);
	cnt = new int[101];
	for ( int i = 0; i <= 100; i++ ) cnt[i] = 0;
	for ( int i = 0; i < 12; i++ ){
	    int x = sc.nextInt(); cnt[x]++;
	}
	if ( check() ) System.out.println("yes");
	else System.out.println("no");
    }
    
    public static void main(String[] a){ new Main().solve(); }
}
