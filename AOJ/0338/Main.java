import java.util.Scanner;

class Main{
  int gcd(int a, int b){
    if ( b == 0 ) return a;
    return gcd(b, a % b);
  }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    int W = sc.nextInt();
    int H = sc.nextInt();
    int C = sc.nextInt();
    System.out.println((W / gcd(W, H)) *
		       (H / gcd(W, H)) * C);
  }
    
  public static void main(String[] args){
    new Main().solve();
  }
}
