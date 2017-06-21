// 623:500!:0.5:BigInteger
import java.util.*;
import java.math.BigInteger;

public class Main{

    public Main(){
	Scanner sc = new Scanner(System.in);
	int n;
	while(sc.hasNext()){
	    n = sc.nextInt();

	    BigInteger f = new BigInteger(Integer.toString(1));
	    for ( int i = 1; i <= n; i++ ){
		BigInteger p = new BigInteger(Integer.toString(i));
		f = f.multiply(p);
	    }
	    System.out.println(n + "!");
	    System.out.println(f.toString());
	}
    }

    public static void main(String[] args){
	new Main();
    }
}
