import java.util.Scanner;

class Main{
  long gcd(long x, long y){ return y > 0 ? gcd(y, x % y) : x ; }
  long lcm(long x, long y){ return x / gcd(x, y) * y; }
  
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N;
    N = sc.nextInt();
    int[] A = new int[N];
    int cnt = 0;
    for ( int i = 0; i < N; i++ ) A[i] = sc.nextInt();

    for ( int bit = 1; bit < (1 << N); bit++ ) {
      boolean valid = true;
      long LCM = 1;
      for ( int i = 0; i < N; i++ ){
        if ( (bit & (1 << i)) > 0 ) LCM = lcm(LCM, A[i]);
      }
      for ( int i = 0; i < N; i++ ){
        if ( (bit & (1 << i)) == 0 )
          if ( LCM >= A[i] && LCM % A[i] == 0 ) valid = false; 
      }
      if ( valid ) cnt++;
    }
  
    System.out.println(cnt);
  }

  public static void main(String[] args){ new Main().solve(); }
}
