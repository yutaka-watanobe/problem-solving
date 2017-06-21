import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;

public class Main{

    public Main(){
	int a, b;
	Scanner sc = new Scanner(System.in);

	while(sc.hasNextInt()){
	    a = sc.nextInt();
	    b = sc.nextInt();
	    System.out.println(a+b);
	}
    }

    public static void main( String[] a ){
	new Main();
    }
}
