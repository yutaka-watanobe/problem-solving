import java.util.Scanner;

class Main{
  int gcd(int x, int y){
    return y > 0 ? gcd(y, x%y) : x;
  }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    int x, y;
    x = sc.nextInt();
    y = sc.nextInt();
    System.out.println((x + 1) + (y + 1) - (gcd(x, y) - 1) - 2);
  }
    
  public static void main(String[] args){ new Main().solve(); }
}
