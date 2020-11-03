import java.util.Scanner;

class Main {
  static final int INF = 100000;
    
  void solve(){
    Scanner sc = new Scanner( System.in );
    int N = sc.nextInt();
    int[] a = new int[N];
    for ( int i = 0; i < N; ++i ) a[i] = sc.nextInt();

    int w, lmin = INF, rmin = INF;
    for ( int i = 0; i < N; ++i ) {
      w = sc.nextInt();
      if ( a[i] == 1 ) rmin = Math.min(rmin, w);
      else lmin = Math.min(lmin, w);
    }

    if ( rmin == INF || lmin == INF ) System.out.println(0);
    else System.out.println(rmin + lmin);
  }

  public static void main(String[] a) { new Main().solve(); }
}
    
