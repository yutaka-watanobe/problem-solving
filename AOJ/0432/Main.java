import java.util.Scanner;

class Main{
  int N;
  char[][] G, T;
    
  void rotate(){
    for ( int i = 0; i < N; i++ )
      for ( int j = 0; j < N; j++ )
	T[i][j] = G[i][j];
    for ( int i = 0; i < N; i++ )
      for ( int j = 0; j < N; j++ )
	G[j][N-i-1] = T[i][j];
    }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    int cnt = 4 * 100000;
    N = sc.nextInt();
    G = new char[N][N];
    T = new char[N][N];
    for ( int i = 0; i < N; i++ ) {
      String s = sc.next();
      for ( int j = 0; j < N; j++ )
	G[i][j] = s.charAt(j);
      }
    int Q = sc.nextInt();
    for ( int i = 0; i < Q; i++ ){
      int q = sc.nextInt();
      cnt += q;
    }
    cnt %= 4;
    for ( int i = 0; i < cnt; i++ ) rotate();
    for ( int i = 0; i < N; i++ )
      System.out.println(G[i]);
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
