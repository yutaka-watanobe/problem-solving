import java.util.*;

class Main{
  class Rect{
    public int h, w;
    Rect (int h, int w) {
      this.h = Math.min(h, w);
      this.w = Math.max(h, w);
    }
  }
    
  static final int N = 6;
    
  boolean check(){
    Scanner sc = new Scanner(System.in);
    Rect[] D = new Rect[N];

    for ( int i = 0; i < N; i++ ) {
      D[i] = new Rect(sc.nextInt(), sc.nextInt());
    }

    /* バブルソート */	
    for ( int i = 0; i < N - 2; i++ ){
      for ( int j = N - 2; j >= i; j-- ){
	if ( D[j].h > D[j + 1].h ||
          D[j].h == D[j + 1].h && D[j].w > D[j + 1].w ){
	    Rect tmp = D[j]; D[j] = D[j + 1]; D[j + 1] = tmp;
	}
      }
    }
	
    for ( int i = 0; i < N; i += 2){
      if ( D[i].h == D[i + 1].h && D[i].w == D[i + 1].w ) D[i / 2] = D[i];
      else return false;
    }
	
    return D[0].h == D[1].h && D[0].w == D[2].h && D[1].w == D[2].w;
  }
    
  void solve(){
    System.out.println(check() == true ? "yes" : "no");
  }
    
  public static void main(String[] args){ new Main().solve(); }
}
