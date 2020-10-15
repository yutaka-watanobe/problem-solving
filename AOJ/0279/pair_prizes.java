import java.util.Scanner;

class Main {
  void solve() {
    Scanner sc = new Scanner( System.in );

    while ( true ) {
      int n = sc.nextInt();
      if ( n == 0 ) break;
      int less1Cnt = 0;
      int zeroCnt = 0;
      for ( int i = 0; i < n; ++i ) {
        int k = sc.nextInt();
        if ( k <= 1 ) ++less1Cnt;
        if ( k == 0 ) ++zeroCnt;
      }
      if ( n == less1Cnt ) System.out.println("NA");
      else System.out.println(n - zeroCnt + 1);
    }
  }

  public static void main(String[] a) { new Main().solve(); }
}
