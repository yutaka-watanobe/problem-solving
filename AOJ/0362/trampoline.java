import java.util.Scanner;

class Main {
  int N = 0;
  ArrayList<Integer> d = new ArrayList<Integer>();
    
  boolean isReachable() {
    int current = 0;
    for ( int i = 0; i < N; i++ ) {
      if ( current < 10 * i ) return false;
      current = Math.max(current, 10 * i + d.get(i));
      if ( current >= 10 * N ) return true;
    }
    return false;
  }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    for ( int i = 0; i < n; i++ ) d.add(sc.nextInt());
	    
    if ( !isReachable() ) {
      System.out.println("no");
      return;
    }
	
    Collections.reverse(d); // 列の要素を逆順に変換する
    if ( !isReachable() ) System.out.println("no");
    else System.out.println("yes");
	
  }

  public static void main(String[] args) {new Main().solve(); }
}
