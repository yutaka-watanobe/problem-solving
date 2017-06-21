import java.io.*;
import java.util.*;

class Main{

    public Main(){
	int a, b;
	Scanner sc = new Scanner(System.in);

	while( sc.hasNextInt() ){
	    a = sc.nextInt();
	    b = sc.nextInt();
	    
	    int ar[] = new int[10];
	    
	    ar[100] = 1;
	    System.out.println(gcd(a, b) + " " + lcm(a, b) );
	}


    }

    public int lcm( int a, int b ){
	return a/gcd(a, b)*b;
    }

    public int gcd( int a, int b ){
	if ( b == 0 ) return a;
	return gcd( b, a%b );
    }

    public static void main( String[] a ){
	new Main();
    }
}
