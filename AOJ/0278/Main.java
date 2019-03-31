import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int N, x, y, b, p;
	N = sc.nextInt();
	for(int i = 0; i < N; ++i) {
	   x = sc.nextInt();
	   y = sc.nextInt();
	   b = sc.nextInt();
	   p = sc.nextInt();
	   System.out.println(Math.min(x*b+y*p, (x*Math.max(b,5)+y*Math.max(p,2))*4/5) );
	}
    }

    public static void main(String[] args){ new Main().solve(); }
}
