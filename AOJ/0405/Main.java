import java.util.*;

class Main{
    void solve(){
	int N;
	Scanner sc = new Scanner(System.in);
	N = sc.nextInt();
	
	if ('A' <= N && N <= 'Z' ) System.out.println("1");
	else if ( 'a' <= N && N <= 'z' ) System.out.println("2");
	else System.out.println("0");
    }
    
    public static void main(String[] args){
	new Main().solve();
    }
}
