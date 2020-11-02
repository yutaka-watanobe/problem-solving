import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int p = 0, N = sc.nextInt();

    while ( N > 1 ) {
      N >>= 1;
      ++p;
    }

    System.out.println(1 << p);
  }

  public static void main(String[] args) { new Main().solve(); }
}
