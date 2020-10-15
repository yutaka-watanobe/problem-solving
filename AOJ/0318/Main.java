import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    boolean[] A = new boolean[N+1];
    boolean[] B = new boolean[N+1];
    boolean[] C = new boolean[N+1];
    for ( int i = 1; i <= N; i++ ) A[i] = B[i] = C[i] = false;
	
    int X, Y, Z;
    X = sc.nextInt();
    for ( int i = 0; i < X; i++ ) A[sc.nextInt()] = true;
    Y = sc.nextInt();
    for ( int i = 0; i < Y; i++ ) B[sc.nextInt()] = true;
    Z = sc.nextInt();
    for ( int i = 0; i < Z; i++ ) C[sc.nextInt()] = true;

    int ans = 0;
    for ( int i = 1; i <= N; i++ ){
      if (!A[i] && C[i] || B[i] && C[i]) ans++;
    }

    System.out.println(ans);
  }

  public static void main(String[] a){ new Main().solve(); }
}
