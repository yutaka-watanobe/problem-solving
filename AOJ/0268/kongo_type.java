import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main {

  void solve(){
    Scanner sc = new Scanner(System.in);
    int q = sc.nextInt();
	
    while ( q-- > 0 ) {

      long b = Long.parseLong( sc.next(), 16 );
      double res = (b&0x7fffff80) >> 7;

      double frac = 0.5;
      for ( long i=6; i>=0; --i ) {
        if ( ((b>>i)&1) == 1 ) res += frac;
        frac *= 0.5;
      }
	    
      System.out.printf("%s%s%s\n", ((b>>31) == 1) ? "-" : "",
                        BigDecimal.valueOf(res).stripTrailingZeros().toPlainString(),
                        ((b&0x0000007f)==0) ? ".0" : "" );
    }

  }

  public static void main(String[] a) { new Main().solve(); }
}
