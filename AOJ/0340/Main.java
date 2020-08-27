import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] p = new int[N];
	int[] r = new int[N];
	for(int i = 0; i < N; i++ ) p[i] = sc.nextInt();
	int ans = (1<<29);
	
	for(int j = 0; j <= p[0]; j++) {
	    int x = j;
	    for(int i = 0; i < N; i++) r[i] = p[i];
	    r[0] -= j;
	    for(int i = 0; i < N - 1; i++) {
		int y = Math.max(0, r[i]);
		r[i] -= y;
		r[i+1] -= y;
		x += y*2;
	    }
	    ans = Math.min(ans, x + Math.max(0, r[N-1]));
	}
	System.out.println(ans);
    }

    public static void main(String[] args){ new Main().solve(); }
}
