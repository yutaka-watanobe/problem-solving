import java.util.Scanner;
import java.util.Arrays;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] a = new int[N];
    for ( int i = 0; i < N; i++ )
	a[i] = sc.nextInt();

    double res = 0.0;
    Arrays.sort(a);

    for ( int D = 0; D < N - 1; D++ ){
      int C = D + 1;
      int A = N - 1;
      int B = N - 2;
      if ( D == N - 3 ){
	B = D - 1;
      } else if ( C == N - 2 ){
	A = D - 2;
	B = D - 1;
      }
      res = Math.max(res, 1.0 *
		     (a[A] + a[B]) /
		     (a[C] - a[D]));
    }

    System.out.println(String.format("%.8f", res));
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
