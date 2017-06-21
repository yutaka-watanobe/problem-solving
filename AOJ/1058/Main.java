import java.util.Scanner;

//Winter Bells
public class Main{

	void run(){
	    Scanner sc = new Scanner(System.in);
	    for(;;){
		int n = sc.nextInt();
		int m = sc.nextInt();
		int p = sc.nextInt();
		int x = 0;
		if((n|m|p)==0)break;
		for(int i=0;i<m;i++){
		    x = sc.nextInt();
		    x = sc.nextInt();
		    x = sc.nextInt();
		}
		for(int i=0;i<p;i++){
		    sc.nextInt();
		    System.out.printf("%.8f\n", 0.0);
		}
		System.out.println();
	    }
	}
	
	public static void main(String[] args) {
		new Main().run();
	}
}