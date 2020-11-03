import java.util.Scanner;

class Main {
  void solve() {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    double t = sc.nextDouble();
    double maxSlope = 0.0;
    for ( int i = 0; i < N; i++ ) {
      double xi = sc.nextDouble();
      double hi = sc.nextDouble();
      double slope = hi / xi;
      if ( slope > maxSlope ) maxSlope = slope;
    }

    System.out.printf( "%f", t * maxSlope );
  }

  public static void main(String[] args) {
    new Main().solve();
  }
}
