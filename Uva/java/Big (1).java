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

    int b;

    String a, op, b;
    try{
      FileInputStream is = new FileInputStream("big.txt");
      DataInputStream ds = new DataInputStream(is);

      while((line_str = ds.readLine()) != null){
	System.out.println(line_str);
	st = new StringTokenizer(line_str);

	a = st.nextToken();
	op = st.nextToken();
	b = st.nextToken();

	BigInteger A = new BigInteger(a);
	BigInteger B = new BigInteger(b);
	BigInteger C;

	if(op.equals("+")){
	  C = A.add(B);
	}else if(op.equals("-")){
	  C = A.subtract(B);
	}else if(op.equals("/")){
	  C = A.divide(B);
	}else if(op.equals("%")){
	  C = A.multiply(B);
	}
	System.out.println(line_str + " = " + C.toString());
      }
    }catch(IOException e){

    }

  }

}
// @end_of_source_code

