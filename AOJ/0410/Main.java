import java.util.*;

class Main{
  int N, cnt;
  int[] A;
  boolean[] selected;

  long gcd(long x, long y){ return y != 0 ? gcd(y, x % y) : x; }
  long lcm(long x, long y){ return x / gcd(x, y) * y; }
  
  void rec(int p, long LCM, int sum){
    if ( p == N ){
      boolean ok = (sum > 0);
      for ( int i = 0; i < N; i++ ){
        if ( LCM >= A[i] && LCM % A[i] == 0 && selected[i] == false ) ok = false;
      }
      if ( ok ) cnt++;
    } else {
      selected[p] = true;
      rec(p+1, lcm(LCM, A[p]), sum+1);
      selected[p] = false;
      rec(p+1, LCM, sum);
    }
  }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    A = new int[20];
    selected = new boolean[20];
    N = sc.nextInt();
    for ( int i = 0; i < N; i++ ) A[i] = sc.nextInt();
    cnt = 0;
    rec(0, 1, 0);
    System.out.println(cnt);
  }

  public static void main(String[] args){ new Main().solve(); }
}
	
    
