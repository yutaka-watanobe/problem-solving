import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int maxv = 0, ans = 0;
	int[] t = new int[n];
	List<Integer> d = new ArrayList<>();
	
	for ( int i = 0; i < n; i++ ){
	    t[i] = sc.nextInt();
	    maxv = Math.max(maxv, t[i]);
	}
	
	for ( int i = 1; i <= maxv; i++ ){
            if ( maxv % i == 0) d.add(i);
	}
	
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < d.size(); j++ ) {
                if ( d.get(j) >= t[i]) {
                    ans += d.get(j) - t[i];
                    break;
                }
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args){ new Main().solve(); }
}
