import java.util.*;

class Main{
    public Main(){
	Scanner sc = new Scanner(System.in);
	int n;
	int[] T;

	while(true){
	    n = sc.nextInt();
	    if ( n == 0 ) break;
	    T = new int[n];

	    Vector<Vector<Integer> > vl = new Vector<Vector<Integer> > ();

	    for ( int i = 0; i < n; i++ ) T[i] = sc.nextInt();

	    Vector<Integer> v = new Vector<Integer>();
	    v.addElement(T[0]);
	    int pre = T[0];
	    for ( int i = 1; i < n; i++ ){
		if ( T[i] != pre + 1 ){
		    vl.addElement(v);
		    v = new Vector<Integer>();
		}
		v.addElement(T[i]);
		pre = T[i];
	    }
	    if ( v.size() > 0 ) vl.addElement(v);
	    

	    for ( int i = 0; i < vl.size(); i++ ){
		if ( i > 0 ) System.out.print(" ");
		v = vl.elementAt(i);
		int b = v.elementAt(0).intValue();
		int e = v.elementAt(v.size()-1).intValue();
		if ( b == e ){
		    System.out.print(b);
		} else {
		    System.out.print(b + "-" + e);
		}
	    }
	    System.out.println();


	}


    }

    public static void main(String[] args){ new Main(); }
}
