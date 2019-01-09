import java.util.*;
class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int i = 0, total = 0;
	while ( i < 10 ) {
	    int s = sc.nextInt();
	    total += s;
	    i++;
	}
	System.out.println( total );
    }

    public static void main(String[] args){ new Main().solve(); }
}


