import java.util.Scanner;
import java.io.*;

public class Main{
    public static void main(String[] args){
	try{
	    //Scanner s = new Scanner(new BufferedReader(new FileReader("input.txt")));
	    Scanner s = new Scanner(System.in);
	    int n;
	    int[] v = {0, 0, 0, 0, 0, 0};
	    n = s.nextInt();
	    for ( int i = 0; i < n; i++ ){
		double h = s.nextDouble();
		if ( h < 165.0 ) v[0]++;
		else if ( 165.0 <= h && h < 170.0 ) v[1]++;
		else if ( 170.0 <= h && h < 175.0 ) v[2]++;
		else if ( 175.0 <= h && h < 180.0 ) v[3]++;
		else if ( 180.0 <= h && h < 185.0 ) v[4]++;
		else if ( 185.0 <= h ) v[5]++;
	    }
	    for ( int i = 0; i < 6; i++ ){
		System.out.print(i+1 + ":");
		for ( int j = 0; j < v[i]; j++ ) System.out.print('*');
		System.out.println();
	    }
	} catch (Exception e){}
    }
}
