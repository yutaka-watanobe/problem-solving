import java.util.*;
import java.lang.*;

class Main{

    int A[];
    int n;

    public Main(){
	A = new int[100];
	Scanner sc = new Scanner(System.in);

	while(true){
	    n = sc.nextInt();
	    if ( n == 0 ) break;

	    for ( int i = 0; i < n; i++ ){
		A[i] = sc.nextInt();
	    }
	    
	    int cnt = 0;

	    for ( int end = n-2; end >= 0; end-- ){
		for ( int j = 0; j <= end; j++ ){
		    if ( A[j] > A[j+1] ){
			int tmp = A[j];
			A[j] = A[j+1];
			A[j+1] = tmp;
			cnt++;
		    }
		}
	    }


	    System.out.println(cnt);
	}
    }

    public static void main(String[] a){
	new Main();
    }
}
