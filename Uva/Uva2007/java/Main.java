import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main{
  public static void main (String args[]){
    Main m = new Main();
    m.Begin();
  }
  
  void Begin(){

    String line_str;
    StringTokenizer st;
    Vector num = new Vector();

    String a, op, b;

    try{
      FileInputStream fis = new FileInputStream("big.txt");
      BufferedReader buf = new BufferedReader(new InputStreamReader(fis));

      while((line_str = buf.readLine()) != null){

	st = new StringTokenizer(line_str);

	a = st.nextToken();
	op = st.nextToken();
	b = st.nextToken();

	BigInteger A = new BigInteger(a);
	BigInteger B = new BigInteger(b);
	BigInteger C = new BigInteger("0");

	if(op.equals("+")){
	  C = A.add(B);
	}else if(op.equals("-")){
	  C = A.subtract(B);
	}else if(op.equals("/")){
	  C = A.divide(B);
	}else if(op.equals("*")){
	  C = A.multiply(B);
	}else if(op.equals("%")){
	  C = A.remainder(B);
	}
	System.out.println(line_str + " = " + C.toString());
      }
    }catch(IOException e){

    }

  }
}
// @end_of_source_code

