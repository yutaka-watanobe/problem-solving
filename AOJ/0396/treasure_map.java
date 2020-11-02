import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner( System.in );
    int w = sc.nextInt();
    int h = sc.nextInt();

    Integer[] col = new Integer[w];
    Integer[] row = new Integer[h];
    int sumC = 0, sumR = 0;
    for ( int i = 0; i < w; ++i ) {
      col[i] = sc.nextInt();
      sumC += col[i];
    }
    for ( int i = 0; i < h; ++i ) {
      row[i] = sc.nextInt();
      sumR += row[i];
    }
    if ( sumR != sumC ) {
      System.out.println("0");
      return;
    }

    for ( int i = 0; i < w; ++i ) {

      Arrays.sort(row, Comparator.reverseOrder()); //降順ソート
	    
      for ( int j = 0; j < h; ++j ) {
        if ( col[i] == 0 || row[j] == 0 ) break;
        --row[j];
        --col[i];
      }

      if ( col[i] > 0 ) {
        System.out.println("0");
        return;
      }
    }

    System.out.println("1");
  }

  public static void main(String[] args) { new Main().solve(); }
}
