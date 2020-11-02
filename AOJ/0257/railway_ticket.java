import java.util.Scanner;

class Main {
  void solve() {
    Scanner sc = new Scanner(System.in);
    int b1 = sc.nextInt();
    int b2 = sc.nextInt();
    int b3 = sc.nextInt();
    if ( b1 == 1 && b2 == 1 || b3 == 1 )
      System.out.println("Open");
    else
      System.out.println("Close");
  }
    
  public static void main(String[] args) {
    new Main().solve();
  }
}
