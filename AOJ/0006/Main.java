import java.util.*;

class Main{
    
    public Main(){
	Scanner sc = new Scanner(System.in);

	String str = sc.next();

	for ( int i = 0; i < str.length(); i++ ){
	    System.out.print(str.charAt(str.length()-i-1));
	}
	System.out.println(".");

    }

    public static void main( String[] a ){
	new Main();
    }
}
