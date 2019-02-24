import java.util.*;

class Main{
    void solve(){
	string D = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"};
	Scanner sc = new Scanner(System.in);
	int x = sc.nextInt();
	System.out.println(D[x%7]);
    }
    
    public static void main(String[] args){ new Main().solve(); }
}
