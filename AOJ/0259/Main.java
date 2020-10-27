import java.io.*;
import java.util.*;

class Main {
  void solve(){
    Scanner sc = new Scanner(System.in);

    while( true ){
      String N = sc.next();
      if ( N.equals("0000") ) return;
      if ( N.charAt(0) == N.charAt(1) &&
        N.charAt(1) == N.charAt(2) &&
        N.charAt(2) == N.charAt(3) ) {
        System.out.println("NA");
        continue;
      }
      int cnt = 0;
      while ( !N.equals("6174") ) {
        char[] L = N.toCharArray();
        char[] S = N.toCharArray();
        Arrays.sort( L );                          // 昇順にソート
        char tmp = L[0]; L[0] = L[3]; L[3] = tmp;  // 逆順にして降順にソート
        tmp = L[1]; L[1] = L[2]; L[2] = tmp;       // 
        Arrays.sort( S );                          // 昇順にソート
        int num = Integer.parseInt( new String(L) ) - Integer.parseInt( new String(S) );
        N = Integer.toString(num);
        while( N.length() < 4 ) N = '0' + N;
        cnt++;
      }
      System.out.println(cnt);
    }
  }
    
  public static void main(String[] a) { new Main().solve(); }
}
