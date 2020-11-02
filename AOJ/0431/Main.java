import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] r = new int[N]; // N 個の円盤の半径を記録できる配列
    for ( int i = 0; i < N; i++ ) r[i] = sc.nextInt();
    int maxr = 0, cnt = 0;
    for ( int i = N - 1; i >= 0; i-- ){
      if ( r[i] > maxr ) {
	cnt++;
	maxr = r[i];
      }
    }
    System.out.println(cnt);
  }

  public static void main(String[] args){ new Main().solve(); }
}
