import java.util.Scanner;
import java.util.Arrays;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] A = new int[N];
    for ( int i = 0; i < N; i++ )
	A[i] = sc.nextInt();

    double res = 0.0;
    Arrays.sort(A);

    for ( int p4 = 0; p4 < N - 1; p4++ ){
      int p3 = p4 + 1;
      int p1 = N - 1;
      int p2 = N - 2;
      if ( p4 == N - 3 ){
	p2 = p4 - 1;
      } else if ( p3 == N - 2 ){
	p1 = p4 - 2;
	p2 = p4 - 1;
      }
      res = Math.max(res, 1.0 *
		     (A[p1] + A[p2]) /
		     (A[p3] - A[p4]));
    }

    System.out.println(String.format("%.8f", res));
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
