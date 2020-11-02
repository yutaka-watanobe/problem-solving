import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for ( int i = 0; i < N; i++ ){ // N 回繰り返す
      int K = sc.nextInt();
      int P = sc.nextInt();
      System.out.println((K - 1) % P + 1);
    }
  }
  public static void main(String[] args){ new Main().solve(); }
}
  
