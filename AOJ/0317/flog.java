import java.util.Scanner;

public class Main {
    void solve(){
	Scanner sc = new Scanner(System.in);
	int D = sc.nextInt(), L = sc.nextInt();
	System.out.println(D / L + D % L);
    }
    public static void main(String[] args) { new Main().solve(); }
}
