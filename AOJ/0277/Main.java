import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int t, n;
    int[] V = {0, 6000, 4000, 3000, 2000};
	
    for ( int i = 0; i < 4; i++ ){
      t = sc.nextInt();
      n = sc.nextInt();
      System.out.println(V[t] * n);
    }
  }

  public static void main(String[] args){ new Main().solve(); }
}
