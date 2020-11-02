import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int R = sc.nextInt();
    int T = sc.nextInt();

    int[] p = new int[N];
    for ( int i = 0; i < N; i++ ) p[i] = sc.nextInt();

    int[] filled = new int[R];
    for ( int i = 0; i < R; i++ ) filled[i] = 0;
	
    int res = 0;
    for ( int i = 1; i <= T; i++ ) {
      for ( int j = 0; j < N; j++ ) {
        if ( filled[(p[j] * i) % R] <= 0 ) ++res;
        else --filled[(p[j] * i) % R];
      }

      if ( i > 1 ) {
        for ( int j = 0; j < N; j++ ) ++filled[(p[j] * i) % R];
      }
    }

    System.out.println(res);
  }

  public static void main(String[] args) { new Main().solve(); }
}
