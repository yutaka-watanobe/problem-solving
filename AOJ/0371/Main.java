import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int maxt = 0, ans = 0;
    int[] t = new int[n];
    List<Integer> divisors = new ArrayList<Integer>();

    for ( int i = 0; i < n; i++ ){
      t[i] = sc.nextInt();
      // 間隔が一番長いmaxtを更新
      maxt = Math.max(maxt, t[i]);
    }

    // maxtの約数を昇順に列挙
    for ( int i = 1; i <= maxt; i++ ){
      if ( maxt % i == 0) divisors.add(i);
    }
	
    for ( int i = 0; i < n; i++ ) {
      // tを増やしたときに最初に一致する
      // maxtの約数を線形探索
      for ( int j = 0; j < divisors.size(); j++ ) {
        if ( divisors.get(j) >= t[i]) {
          ans += divisors.get(j) - t[i];
          break;
        }
      }
   }
   System.out.println(ans);
 }

  public static void main(String[] args){
    new Main().solve();
  }
}


