import java.util.*;

class Main{
    void solve(){
	Scanner sc = new Scanner(System.in);
	boolean[] timeTable = new boolean[24*60];
	int h, m;
	boolean isFirst;
  
	for (int i = 0; i < 2; ++i) {
	    int j;
	    j = sc.nextInt();
	    for (; j > 0; --j) {
		h = sc.nextInt();
		m = sc.nextInt();
		timeTable[h*60 + m] = true;
	    }
	}
	
	isFirst = true;
	for (h = 0; h < 24; ++h){
	    for (m = 0; m < 60; ++m)      {
		if ( timeTable[h*60 + m] ){
		    if ( !isFirst ) System.out.print(" ");
		    else isFirst = false;
		    System.out.format("%d:%02d", h, m);
		}
	    }
	}
	System.out.println();
    }

    public static void main(String[] args){ new Main().solve(); }
}
	
