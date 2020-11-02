import java.util.Scanner;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);
    int y1, m1, d1, y2, m2, d2, t;
    y1 = sc.nextInt();
    m1 = sc.nextInt();
    d1 = sc.nextInt();
    y2 = sc.nextInt();
    m2 = sc.nextInt();
    d2 = sc.nextInt();
    if ( y1 > y2 || (y1 == y2
	 && (m1 > m2 || (m1 == m2 && d1 > d2)))) {
      t = y1; y1 = y2; y2 = t; // swap(y1, y2)
      t = m1; m1 = m2; m2 = t; // swap(m1, m2)
      t = d1; d1 = d2; d2 = t; // swap(d1, d2)
    }
    int ans = y2 - y1;
    if ( m1 < m2 || (m1 == m2 && d1 < d2) ) ans++;
    System.out.println(ans);
  }

  public static void main(String[] args) {
    new Main().solve();
  }
}
