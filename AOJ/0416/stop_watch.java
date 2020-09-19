import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int t = sc.nextInt();
    int r = sc.nextInt();
    System.out.println((1.0 * t / a) * r);
  }

  public static void main(String[] a) {new Main().solve(); }
}
