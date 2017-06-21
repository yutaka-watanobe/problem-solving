import java.util.*;

class Main{

    boolean used[];
    int n, s, cnt;

    public Main(){
	used = new boolean[10];


	Scanner sc = new Scanner(System.in);


	while( sc.hasNext() ){
	    n = sc.nextInt();
	    s = sc.nextInt();
	    cnt = 0;
	    for ( int i = 0; i < 10; i++ ) used[i] = false;	    
	    rec(n, 0);
	    System.out.println(cnt);
	}
    }

    void rec( int pos, int sum ){
	if ( sum > s ) return;
	if ( pos <= 0 ){
	    if ( sum == s ) cnt++;
	    return;
	}

	int md = 0;
	for ( int i = 1; i <= pos; i++ ) md += i*9;
	if ( md + sum < s ) return;


	for ( int i = 0; i < 10; i++ ){
	    if ( used[i] ) continue;
	    used[i] = true;
	    rec( pos - 1, sum + (pos)*i);
	    used[i] = false;
	}

    }


    public static void main(String[] s ){
	new Main();
    }
}
