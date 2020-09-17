import java.util.*;

public class Main{
  Scanner sc = new Scanner(System.in);
  int j, y;
    
  void solve(){
    j = sc.nextInt();
    y = sc.nextInt();
    parse(0, 0, "");
  }

  void parse( int a, int b, String path ){
    if ( a == j && b == y ){
      System.out.println(path);
      return;
    }
    if ( a >= 5 && b <= 3 ) return;
    if ( b >= 5 && a <= 3 ) return;
    if ( a + 1 <= j && b <= y ) parse(a + 1, b, path + "A");
    if ( a <= j && b + 1 <= y ) parse(a, b + 1, path + "B");
  }

  public static void main(String[] a){ new Main().solve(); }
}
