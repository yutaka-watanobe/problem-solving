import java.io.*;
class Main{
    solve() {
	int A, B;
	Scanner sc = new Scanner(System.in);
	A = sc.nextInt();
	B = sc.nextInt();
	System.out.println((B+A-1)/A);
    }
    public static void main(String[] a){ new Main().solve(); }
}
