import java.util.Scanner;

class Main{
  int gcd(int x, int y){ return y > 0 ? gcd(y, x % y) : x; }

  void print(int x, int y){
    int g = gcd(x, y);
    System.out.println(x / g + "/" + y / g);
  }
    
  void solve(){
    Scanner sc = new Scanner(System.in);
    String in = sc.next();
    int o, p, l, d;
    o = p = -1;
    String all = "", sub = "";
    o = in.indexOf('.');
    p = in.indexOf('(');
    d = in.length() - o - 1;
    if ( p == -1 ){
      all = in.substring(0, o) + in.substring(o + 1, in.length());
      print(Integer.parseInt(all), (int)Math.pow(10, d));
    }else {
      sub = in.substring(0, o) + in.substring(o + 1, p);
      all = sub + in.substring(p + 1, in.length() - 1);
      l = p - o - 1;
      d -= 2; // ()の分を引く
      print(Integer.parseInt(all)- Integer.parseInt(sub),
	    (int)Math.pow(10, d) - (int)Math.pow(10, l) );
    }
  }
    
  public static void main(String[] args){ new Main().solve(); }
}

