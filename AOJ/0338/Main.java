import java.util.*;

class Main{
    
    int gcd(int a, int b){
	if ( b == 0 ) return a;
	return gcd(b, a % b);
    }
    
    void solve(){
	int W, H, C;
	Scanner sc = new Scanner(System.in);
	W = sc.nextInt();
	H = sc.nextInt();
	C = sc.nextInt();
	System.out.println((W / gcd(W, H)) * (H / gcd(W, H)) * C);
    }
    
    public static void main(String[] args){
	new Main().solve();
    }
}
