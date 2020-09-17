import java.util.Scanner;

class Main{
  int G[][] = {{1, 2}, {-1, 3}, {1, -1}, {4, 5}, {5, 2}, {2, 1}};  // 地図

  void solve(){
    Scanner sc = new Scanner(System.in);
    String p;
    while(true){
      p = sc.next();
      if ( p.charAt(0) == '#' ) break;
      int cur = 0; // A市を出版
      for ( int i = 0; i < p.length(); i++ ) {
        if ( cur == -1 ) break;
        cur = G[cur][p.charAt(i) - '0'];
      }
      System.out.println(cur == 5 ? "Yes" : "No"); // B市か判定
    }
  }

  public static void main(String[] args){ new Main().solve(); }
}
