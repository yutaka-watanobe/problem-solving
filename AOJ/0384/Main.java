import java.util.*;

class Main{

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
		x *= (y+a);
	    }
	    if (x <= m && val(x) == y) cnt++;
	}

	System.out.println(cnt);
    }

    long val(long x){
	long  sum = 0;
	while(x > 0){
	    sum += x%10;
	    x /= 10;
	}
	return sum;
    }

    public static void main(String[] args){ new Main().solve(); }
}

