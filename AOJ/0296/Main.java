import java.util.*;

class Main{
    int c1, c5, c10, c50, c100, c500, sum;

    void solve(){
	Scanner sc = new Scanner(System.in);
	c1 = sc.nextInt();
	c5 = sc.nextInt();
	c10 = sc.nextInt();
	c50 = sc.nextInt();
	c100 = sc.nextInt();
	c500 = sc.nextInt();
	long sum = c1 + c5*5 + c10*10 + c50*50 + c100*100 + c500*500;
	if ( sum >= 1000 ){
	    System.out.println(1);
	} else {
	    System.out.println(0);
	}
    }

    public static void main(String[] a){ new Main().solve(); }
}
