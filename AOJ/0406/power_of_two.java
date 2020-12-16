import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int ans = 1, N = sc.nextInt();

    while ( ans <= N ) {
      ans *= 2;
    }

    System.out.println(ans / 2);
  }

  public static void main(String[] args) { new Main().solve(); }
}
