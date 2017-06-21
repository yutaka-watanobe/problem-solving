import java.util.*;

public class Main{
    public Main(){
	Scanner sc = new Scanner(System.in);
	int N, T, E, x, ans;
	N = sc.nextInt();
	T = sc.nextInt();
	E = sc.nextInt();
	ans = -1;
	for ( int i = 0; i < N; i++ ){
	    x = sc.nextInt();
	    for ( int e = -E; e <= E; e++ ){
		if ( (T+e)%x == 0 ){
		    System.out.println(i+1);
		    return;
		}
	    }
	}
	System.out.println(ans);
    }

    public static void main(String[]  a) { new Main() ; }

}