import java.util.Scanner;

class Main{
  static final int N = 12;
  int[] e;

  boolean check(){
    // 選択ソート
    for ( int i = 0; i < N - 1; i++ ){
      int minj = i;
      for ( int j = i + 1; j < N; j++ )
        if ( e[j] < e[minj] ) minj = j;
      int t = e[minj];
      e[minj] = e[i];
      e[i] = t;
    }
	
    for ( int i = 0; i < N; i += 4)
      if ( e[i] != e[i + 3] ) return false;
    return true;
  }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    e = new int[N];
    for ( int i = 0; i < N; i++ ) e[i] = sc.nextInt();
    System.out.println(check() == true ? "yes" : "no");
  }

  public static void main(String[] args){ new Main().solve();}
}
