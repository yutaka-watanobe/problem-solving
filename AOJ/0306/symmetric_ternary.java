import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner( System.in );
    int w = sc.nextInt();
    StringBuilder res = new StringBuilder();

    while ( w > 0 ) {
      int r = w % 3;
      if ( r == 0 ) {
        res.insert(0, '0');
        w /= 3;
      } else if ( r == 1 ) {
        res.insert(0, '+');
        w /= 3;
      } else if ( r == 2 ){
        res.insert(0, '-');
        w = w/3 + 1;
      }
    }
	
    System.out.println(res.toString());
  }

  public static void main(String[] args) {
    new Main().solve();
  }
}
