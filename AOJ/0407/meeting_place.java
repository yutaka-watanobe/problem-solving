import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int xmin = 2000, xmax = 0;
    for ( int i = 0; i < N; i++ ) {
      int x = sc.nextInt();
      if ( x < xmin ) xmin = x;
      if ( x > xmax ) xmax = x;
    }

    System.out.println( xmax - (xmin + xmax) / 2 );
  }

  public static void main(String[] args) {
    new Main().solve();
  }
}
