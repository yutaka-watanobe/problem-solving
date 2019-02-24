import java.util.*;

public class Main{
    Scanner sc = new Scanner(System.in);
    
    public Main(){
	int j = sc.nextInt();
	int y = sc.nextInt();
	parse(0, 0, j, y, "");
    }

    void parse(int a, int b, int j, int y, String p){
	if ( a == j && b == y ){
	    System.out.println(p);
	    return;
	}
	if ( a >= 5 && b <= 3 ) return;
	if ( b >= 5 && a <= 3 ) return;
	if ( a+1 <= j && b <= y ) parse(a+1, b, j, y, p+"A");
	if ( a <= j && b+1 <= y ) parse(a, b+1, j, y, p+"B");
    }

    public static void main(String[] a){ new Main(); }
}
