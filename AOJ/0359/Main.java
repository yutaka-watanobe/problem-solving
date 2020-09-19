import java.util.Scanner;

class Main{
  void solve(){
    String[] D = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"}; // 曜日を表す配列
    Scanner sc = new Scanner(System.in);
    int X = sc.nextInt();
    System.out.println(D[X % 7]); // 7で割った余りから曜日を求めてその文字列を出力
  }
    
  public static void main(String[] args){ new Main().solve(); }
}
