import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int F = sc.nextInt();
    System.out.println((F - 30) / 2);
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
