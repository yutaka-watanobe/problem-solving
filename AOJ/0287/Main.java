import java.util.Scanner;
import java.math.BigInteger;

public class Main {

  static final String table[] =
  {"", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", "Jou", "Ko", "Kan", 
   "Sei", "Sai", "Gok", "Ggs", "Asg", "Nyt", "Fks", "Mts"};

  void solve() {
    Scanner sc = new Scanner( System.in );
	
    while (true) {
      int m = sc.nextInt();
      int n = sc.nextInt();
      if ( m == 0 && n == 0 ) break;

      ArrayList<Integer> aBlock = new ArrayList<Integer>();
      BigInteger val = BigInteger.valueOf(m).pow(n);
      BigInteger tts = BigInteger.valueOf(10000);

      while ( val != BigInteger.ZERO ) {
        aBlock.add(val.mod(tts).intValue());
        val = val.divide(tts);
      }

      for (int i = aBlock.size()-1; i >= 0; --i) {
        //mts以上なら自動的に数値を出力 (1,0000MtsとかはMtsが出ない)
        if ( i >= table.length ) 
          System.out.print(aBlock.get(i));
        else if ( aBlock.get(i) != 0 ) 
          System.out.print(aBlock.get(i) + table[i]);
      }
      System.out.print("\n");
    }
  }

  public static void main(String[] args) { new Main().solve(); }
    
}
