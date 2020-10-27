import java.util.Scanner;

class Main {
  static final int MAX_X = 2000;
  static final int MAX_Y = 2000;
  int[][] s = new int[MAX_X][MAX_Y];
    
  void solve(){
    for ( int i = 0; i < MAX_X; ++i ) 
      for ( int j = 0; j < MAX_Y; ++j ) s[i][j] = 0;

    Scanner sc = new Scanner( System.in );
    for ( int k = 0; k < 2; ++k ) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      int w = sc.nextInt();
      int h = sc.nextInt();
      for ( int i = x; i < x + w; ++i ) 
        for ( int j = y; j < y + h; ++j ) ++s[i][j];
    }

    int c = 0;
    for ( int i = 0; i < MAX_X; ++i ) 
      for ( int j = 0; j < MAX_Y; ++j )
        if ( s[i][j] == 1 ) ++c;
    System.out.println( c );
  }

  public static void main(String[] a) { new Main().solve(); }
}
