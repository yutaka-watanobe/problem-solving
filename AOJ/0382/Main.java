import java.util.Scanner;

class Main{
  void solve(){
    int N, C, sum = 0;
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt() + 1;
    C = sc.nextInt();
    
    for ( int i = 0; i < C; i++ ){
      int p = sc.nextInt();
      sum += p;
    }

    System.out.println(sum/N + (sum%N==0?0:1));
  }

  public static void main(String[] args){ new Main().solve(); }
}
