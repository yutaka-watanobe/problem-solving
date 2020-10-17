import java.util.Scanner;

class Main{
    
    String[] P = {"RBYG", "RGBY", "RYGB", "YGRB", "YBGR", "YRBG",
		    "BYRG", "BGYR", "BRGY", "GBRY", "GYBR", "GRYB"};
    void solve(){
	Scanner sc = new Scanner(System.in);
	char c1 = sc.next().charAt(0);
	char c2 = sc.next().charAt(0);
	int n = sc.nextInt();
	for ( int i = 0; i < n; i++ ){
	    int x = sc.nextInt();
	    int y = sc.nextInt();
	    x %= 4;
	    y %= 2;
	    if ( y == 1 ) x = 3 - x;
	    for (String p : P){
		if (p.charAt(0) == c1 && p.charAt(1) == c2 ){
		    System.out.println(p.charAt(x));
		    break;
		}
	    }
	}
    }

    public static void main(String[] args){ new Main().solve(); }
}
