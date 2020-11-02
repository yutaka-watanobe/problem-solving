import java.util.Scanner;

class Main {
  int getScore(int iwa, int yam,
		 int a, int b, int c, int d) {
    return iwa * a + yam * b +
	(iwa / 10) * c + (yam / 20) * d;  
  }
  
  void solve() {
    Scanner sc = new Scanner(System.in);
    int h1 = sc.nextInt(), h2 = sc.nextInt();
    int k1 = sc.nextInt(), k2 = sc.nextInt();
    int a = sc.nextInt(),  b = sc.nextInt();
    int c = sc.nextInt(),  d = sc.nextInt();

    int hiro = getScore(h1, h2);
    int ken = getScore(k1, k2);
	
    if      ( hiro > ken )
      System.out.println("hiroshi");
    else if ( hiro < ken )
      System.out.println("kenjiro");
    else
      System.out.println("even");
  }

  public static void main(String[] args) {
      new Main().solve();
  }
}
