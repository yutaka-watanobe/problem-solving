import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int H = sc.nextInt();
    int A = sc.nextInt();
    int B = sc.nextInt();
    int cnt = 0;
    for ( int i = A; i <= B; i++ ){
	cnt += (H % i == 0 ? 1 : 0);
    }
    System.out.println(cnt);
  }

  public static void main(String[] args){
    new Main().solve();
  }
}
