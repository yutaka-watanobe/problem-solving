import java.util.*;
import java.io.*;

class Main{

    public Main(){
	double x, h, H, S;

	Scanner sc = new Scanner(System.in);

	while(true){
	    x = sc.nextInt();
	    h = sc.nextInt();
	    if ( x == 0 && h == 0 ) break;

	    H = Math.sqrt( (x/2)*(x/2) + h*h);
	    S = x*x + x*H*2;

	    System.out.printf("%.2f\n", S);
	}
	    
    }

    public static void main( String[] a ){
	new Main();
    }
}
