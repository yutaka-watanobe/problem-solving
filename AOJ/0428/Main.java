import java.util.Scanner;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int La = sc.nextInt();
	int Lo = sc.nextInt();
	System.out.println(La / 3600 + " " + Lo / 3600);
    }

    public static void main(String[] args) { new Main().solve(); }
}
