import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();

    System.out.print(d / 3600  + " ");
    System.out.print(d % 3600 / 60 + " ");
    System.out.println(d % 60);
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
