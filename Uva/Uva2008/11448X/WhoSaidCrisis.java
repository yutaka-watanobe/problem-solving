import java.util.Scanner;
import java.math.BigInteger;

class WhoSaidCrisis{

    public WhoSaidCrisis(){
	Scanner s = new Scanner(System.in);
	int k;
	String a, b;
	
	k = s.nextInt();

	for ( int i = 0; i < k; i++ ){
	    a = s.next();
	    b = s.next();
	    BigInteger A = new BigInteger(a);
	    BigInteger B = new BigInteger(b);

	    A = A.subtract(B);

	    System.out.println(A.toString());
	}
    }

    public static void main(String[] ar ){
	new WhoSaidCrisis();
    }
}
