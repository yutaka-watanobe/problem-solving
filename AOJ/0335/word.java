import java.util.Scanner;

public class Main {
  void solve(){
    Scanner s = new Scanner(System.in); // 入力用スキャナオブジェクトの生成
    int W, B;                           // 変数の宣言
    W = s.nextInt();                    // 変数に整数を入力
    B = W * 32;                         // 計算結果を代入
    System.out.println(B);              // 変数の値を出力
  }

  //  Mainオブジェクトを生成してプログラムをスタート
  public static void main(String[] args) { new Main().solve(); }
}
 

