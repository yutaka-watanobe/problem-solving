import java.util.Scanner;

class Main{
  static final int N_MAX = 10;
  int N, a[], w[], ans;
  int table[];    // 座席表
  boolean sat[];  // 座ったかどうか

  void rec(int p){
    if ( p == N ){
      int sum = 0;
      for ( int i = 0; i < N; i++ ){
        if ( a[table[i]] == 0 && a[table[(i - 1 + N) % N]] == 1 ||
             a[table[i]] == 1 && a[table[(i + 1) % N]] == 0 )
          sum += w[table[i]];
      }
      ans = Math.min(sum, ans);
      return;
    }

    for ( int i = 0; i < N; i++ ){
      if ( sat[i] ) continue;
      sat[i] = true;
      table[p] = i;
      rec(p + 1);
      sat[i] = false;
    }
  }

  void solve(){
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    a = new int[N];
    w = new int[N];
    table = new int[N];
    sat = new boolean[N];
    for ( int i = 0; i < N; i++ ) a[i] = sc.nextInt();
    for ( int i = 0; i < N; i++ ) w[i] = sc.nextInt();
    ans = 1000 * N;
    rec(0);
    System.out.println(ans);
  }

  public static void main(String[] args) { new Main().solve(); }
}

