import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int t = sc.nextInt();
    int r = sc.nextInt();
    double elapse = (1.0 * t / a) * r; // 経過時間
    System.out.println(elapse);
  }

  public static void main(String[] a) {new Main().solve(); }
}
