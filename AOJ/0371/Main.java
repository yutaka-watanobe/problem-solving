import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int maxt = 0, ans = 0;
	int[] t = new int[n];
	List<Integer> divisors = new ArrayList<>();
	
	for ( int i = 0; i < n; i++ ){
	    t[i] = sc.nextInt();
	    maxt = Math.max(maxt, t[i]);
	}
	
	for ( int i = 1; i <= maxt; i++ ){
            if ( maxt % i == 0) divisors.add(i);
	}
	
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < divisors.size(); j++ ) {
                if ( divisors.get(j) >= t[i]) {
                    ans += divisors.get(j) - t[i];
                    break;
                }
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args){ new Main().solve(); }
}
