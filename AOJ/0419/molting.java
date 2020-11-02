import java.util.Scanner;

class Main {
  void solve() {
    Scanner sc = new Scanner( System.in );
    int L = sc.nextInt();
    int N = sc.nextInt();
    String snake = sc.next();

    long oocnt = 0;
    for ( int i = 0; i < snake.length() - 1; i++ ) {
      if ( snake.substring(i, i + 2).equals("oo") )
         ++oocnt;
    }
    
    long total = 0;
    for ( int i = 0; i < N; i++ ) {
      total += oocnt;
      oocnt *= 2;
    }

    System.out.println(3 * total + snake.length());	    
  }
	
  public static void main(String[] args) { new Main().solve(); }    
}
