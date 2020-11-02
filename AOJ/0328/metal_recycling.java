import java.util.Scanner;

class Main{
  static final int PMAX = 100000;

  int[] T = new int[2 * PMAX + 20];
  
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    for ( int i = 0; i < N; i++ ){
      int a = sc.nextInt();
      int b = sc.nextInt();
      T[a + b]++;
    }

    for ( int i = 0; i < 2 * PMAX + 20 - 1; i++ ){
      T[i + 1] += T[i] / 2;
      T[i] %= 2;
      if ( T[i] > 0 ) System.out.println(i  + " " + 0);
    }
  }

  public static void main(String[] args){ new Main().solve(); }
}
