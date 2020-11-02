import java.util.Scanner;

class Main{
  void solve() {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    System.out.println((B + A - 1) / A);
  }

  public static void main(String[] a){
    new Main().solve();
  }
}
