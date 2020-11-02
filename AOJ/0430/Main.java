import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int x = sc.nextInt();
    int R = x;
    int L = x;
    for ( int i = 0; i < N; i++ ){
      int d = sc.nextInt();
      R = Math.max(R, d);
      L = Math.min(L, d);
    }
    int minv = Math.min(R - x, x - L);
    int maxv = Math.max(R - x, x - L);
    System.out.println(minv * 2 + maxv);
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
