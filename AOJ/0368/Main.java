import java.util.*;
class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int W = sc.nextInt();
	int H = sc.nextInt();
	String c = sc.next();
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		if ( i == 0 && j == 0 || i == 0 && j == W-1 ||
		     i == H-1 && j == 0 || i == H-1 && j == W-1 ){
		    System.out.print("+");
		} else if ( i == 0 || i == H-1 ){
		    System.out.print("-");
		} else if ( j == 0 || j == W-1 ){
		    System.out.print("|");
		} else if ( i == H/2 && j == W/2 ){
		    System.out.print(c);
		} else {
		    System.out.print(".");
		}
	    }
	    System.out.println();
	}
    }
    public static void main(String[] args){ new Main().solve(); }
}
