import java.util.*;
class Main{
    void solve(){
	int a, b;
	Scanner sc = new Scanner(System.in);
	a = sc.nextInt();
	b = sc.nextInt();
	System.out.println((a>b) ? a-b : b-a);
    }
    public static void main(String[] args){ new Main().solve(); }
}
