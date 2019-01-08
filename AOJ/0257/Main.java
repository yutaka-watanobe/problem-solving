import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int i, b, st = 0;
	for ( i = 0; i < 3; i++ ){
	    b = sc.nextInt();
	    if ( b == 1 ) st += (1<<i);
	}
	if ( st >= 3 ) System.out.println("Open");
	else System.out.println("Close");
    }

    public static void main(String[] args) { new Main().solve(); }
}
