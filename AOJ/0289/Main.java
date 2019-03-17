import java.util.*;

class Main{
    
    int solve(int src, int dst) {
	int answer = 0;
	if (src == dst) return 0;
	if (src % 2 != 0) { answer++; src++; }
	if (dst % 2 != 0) { answer++; dst--; }
	answer += solve(src / 2, dst / 2);
	return answer;
    }
    
    void _solve(){
	int N, s, d;
	Scanner sc = new Scanner(System.in);
	N = sc.nextInt();

	for ( int i = 0; i < N; i++ ){
	    s = sc.nextInt();
	    d = sc.nextInt();
	    System.out.println(solve(s, d));
	}
    }

    public static void main(String[] args){ new Main()._solve();} 
}
