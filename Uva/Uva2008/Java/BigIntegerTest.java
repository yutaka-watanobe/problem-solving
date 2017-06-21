import java.math.BigInteger;
import java.util.Scanner;

class BigIntegerTest{
    
    public BigIntegerTest(){
	int tcase;
	int a, b;
	
	Scanner sc = new Scanner(System.in);
	tcase = sc.nextInt();

	for ( int i = 0; i < tcase; i++ ){
	    a = sc.nextInt();
	    b = sc.nextInt();
	    BigInteger x = new BigInteger(Integer.toString(a));
	    x = x.add(new BigInteger(Integer.toString(b)));

	    System.out.println(x.toString());
	}
    }

    public static void main(String[] a){
	new BigIntegerTest();
    }
}
