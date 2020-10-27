import java.util.Scanner;

class Main{
    long getY(long x){
	long y = 0;
	while(x > 0){
	    y += x%10;
	    x /= 10;
	}
	return y;
    }

    void solve(){
	long a, n, m;
	Scanner sc = new Scanner(System.in);
	a = sc.nextLong();
	n = sc.nextLong();
	m = sc.nextLong();
	int cnt = 0;
	for ( int y = 1; y <= 72; y++ ){
	    long x = 1;
	    for ( int t = 1; t <= n; t++ ){
		x *= (y + a);
	    }
	    if (x <= m && getY(x) == y) cnt++;
	}
	System.out.println(cnt);
    }

    public static void main(String[] args){ new Main().solve(); }
}

