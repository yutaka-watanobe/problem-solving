import java.util.*;
class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int m = sc.nextInt();
	int f = sc.nextInt();
	int b = sc.nextInt();
	if ( m  + f < b ) System.out.println("NA");
	else if ( m >= b ) System.out.println(0);
	else System.out.println(b - m);
    }

    public static void main(String[] args){ new Main().solve(); }
}
