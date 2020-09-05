import java.util.*;
class Main{
    int G[][] = {{1, 2}, {-1, 3}, {1, -1}, {4, 5}, {5, 2}, {2, 1}};

    void solve(){
	Scanner sc = new Scanner(System.in);
	String S;
	while(true){
	    S = sc.next();
	    if ( S.charAt(0) == '#' ) break;
	    int cur = 0; 
	    for ( int i = 0; i < S.length(); i++ ) {
		if ( cur == -1 ) break;
		cur = G[cur][S.charAt(i) - '0'];
	    }
	    System.out.println(cur == 5 ? "Yes" : "No"); 
	}
    }
    public static void main(String[] args){ new Main().solve(); }
}
