import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	String A = ">'(=+)#\\1~$";
	String B = ">\\^(Q=)+~~$";  
	int n = sc.nextInt();
	for ( int i = 0; i < n; i++ ) {
	    String snake = sc.next();
	    if ( snake.matches(A) ) System.out.println("A");
	    else if ( snake.matches(B) ) System.out.println("B");
	    else System.out.println("NA");
	}
    }
    public static void main(String[] args){ new Main().solve(); }
}



