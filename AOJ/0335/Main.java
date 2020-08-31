import java.util.Scanner;

public class Main {
    void solve(){
	Scanner s = new Scanner(System.in);
	int W, B;
	W = s.nextInt();
	B = W * 32;
	System.out.println(B);
    }
    
    public static void main(String[] args) { new Main().solve(); }
}
