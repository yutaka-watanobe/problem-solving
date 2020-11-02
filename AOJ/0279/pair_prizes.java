import java.util.Scanner;

class Main {
  void solve() {
    Scanner sc = new Scanner( System.in );
    while ( true ) { // 無限ループ
      int N = sc.nextInt();
      if ( N == 0 ) break; // データセットの終わり
      int less1Cnt = 0;
      int zeroCnt = 0;
      for ( int i = 0; i < N; ++i ) {
        int k = sc.nextInt();
        if ( k <= 1 ) ++less1Cnt;
        if ( k == 0 ) ++zeroCnt;
      }
      if ( N == less1Cnt ) System.out.println("NA");
      else System.out.println(N - zeroCnt + 1);
    }
  }

  public static void main(String[] args) { new Main().solve(); }
}
