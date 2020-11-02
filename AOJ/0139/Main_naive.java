import java.util.Scanner;

class Main{
  boolean isA(String s){
    if ( s.substring(0, 2) != ">'" ||
	 s.charAt(s.length() - 1) != '~' )
      return false;
    int c = s.indexOf('#');
    if ( c == -1 ) return false;
    if ( c - 2 != s.length() - 1 - (c + 1) )
      return false;
    for (int i = 2; i < c; i++ )
      if ( s.charAt(i) != '=' ||
	   s.charAt(c + i - 1) != '=' )
	return false;
    return s.length() > 4;
  }

  boolean isB(String s){
    if ( s.substring(0, 2) != ">^" ||
	 s.substring(s.length()-2, s.length()) != "~~" )
	return false;
    for (int i = 2; i <= s.length() - 4; i += 2 )
      if ( s.substring(i, i + 2) != "Q=" )
	return false;
    return s.length() > 4;
  }

  void solve(){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for ( int i = 0; i < n; i++ ) {
      String snake = sc.next();
      if ( isA(snake) )
	System.out.println("A");
      else if ( isB(snake) )
	System.out.println("B");
      else
	System.out.println("NA");
    }
  }

  public static void main(String[] args){
      new Main().solve();
  }
}


