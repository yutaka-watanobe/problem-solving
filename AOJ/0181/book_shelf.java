import java.util.Scanner;

class Main {
  int m = 0, n = 0;
  int[] w = null;
    
  boolean isStorable(int width) {
    int row = 0, c = 0, i = 0;
    while ( i < n ) {
      if ( c + w[i] <= width ) {
        c += w[i];
        ++i;
      }
      else if ( ++row < m ) c = 0;
      else return false;
    }
    return true;
  }

  void solve(){
    Scanner sc = new Scanner(System.in);

    while ( true ) {

      m = sc.nextInt();
      n = sc.nextInt();
      if ( m == 0 && n == 0 ) break;
	    
      w = new int[n];
      for ( int i = 0; i < n; ++i ) w[i] = sc.nextInt();

      int minw = 1, maxw = 1500000;
      if ( !isStorable(maxw) ) System.out.println("NA");

      while ( maxw > minw ) {
        int mid = (maxw + minw) / 2;
        if ( isStorable(mid) ) maxw = mid;
        else                   minw = mid + 1;
      }

      System.out.println( minw );
    }
  }

  public static void main(String[] a) { new Main().solve(); }
}
