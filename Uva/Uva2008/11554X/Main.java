import java.math.BigInteger;
import java.util.Scanner;

class Main{
    
    public Main(){
	BigInteger tf, t, S[];
	S = new BigInteger[1000001];
	tf = new BigInteger("0");
	S[3] = new BigInteger("0");

	for ( int i = 4; i <= 1000000; i++ ){
	    S[i] = new BigInteger("0");
	    t = tf.add(new BigInteger(Integer.toString((i-2)/2)));
	    S[i] = S[i].add(S[i-1]);
	    S[i] = S[i].add(t);
	    tf = t;
	}

	int tcase, a;
	
	Scanner sc = new Scanner(System.in);
	tcase = sc.nextInt();

	for ( int i = 0; i < tcase; i++ ){
	    a = sc.nextInt();
	    System.out.println(S[a].toString());
	}
    }

    public static void main(String[] a){
	new Main();
    }
}
