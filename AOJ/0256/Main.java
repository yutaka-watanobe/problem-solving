import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int i = 0, total = 0;
    while ( i < 10 ) {           // 繰り返し処理の範囲始まり 
      int s = sc.nextInt();
      total += s;
      i++;
    }                            // 繰り返し処理の範囲終わり 
    System.out.println(total);
  }

  public static void main(String[] args){ new Main().solve(); }
}
