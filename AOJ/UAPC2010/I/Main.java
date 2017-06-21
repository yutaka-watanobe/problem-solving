import java.util.*;

class Grid{
    short n;
    boolean[][] G;
    public Grid(short n){
	this.n = n;
	G = new boolean[5][5];
    }
    public Grid(Grid u){
	this.n = u.n;
	G = new boolean[5][5];
	for ( short i = 0; i < n; i++ ){
	    for ( short j = 0; j < n; j++ ) G[i][j] = u.G[i][j];
	}
    }

    boolean solved(){
	for ( short i = 0; i < n; i++ ){
	    for ( short j = 0; j < n; j++ ){
		if ( G[i][j] ) return false;
	    }
	}
	return true;
    }
}

public class Main{

    short n;

    public Main(){
	Scanner sc = new Scanner(System.in);
	while(true){
	    n = sc.nextShort();
	    if ( n == 0 ) break;
	    Grid g = new Grid(n);
	    int x;
	    for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n; j++ ){
		    x = sc.nextInt();
		    g.G[i][j] = (x > 0)?true:false;
		}
	    }
	    int n = bfs(g);
	    //System.out.println(bfs(g));
	    for ( short i = 0; i < n; i++ ){
		System.out.print("myon");
	    }
	    System.out.println();
	}
    }

    int bfs(Grid s){
	Vector<Grid> Q = new Vector<Grid>();
	Hashtable<Grid, Integer> D = new Hashtable<Grid, Integer>();
	
	D.put(s, new Integer(0));
	Q.addElement(s);

	Grid u;
	int ucost;
	while( Q.size() > 0 ){
	    u = Q.elementAt(0); Q.remove(0);
	    ucost = D.get(u).intValue();

	    if ( u.solved() ) return ucost;

	    for ( int si = 0; si < n; si++ ){
		for ( int sj = 0; sj < n; sj++ ){
		    for ( int ei = si; ei < n; ei++ ){
			for ( int ej = sj; ej < n; ej++ ){
			    Grid v = new Grid(u);

			    for ( int i = si; i <= ei; i++ ){
				for ( int j = sj; j <= ej; j++ ){
				    v.G[i][j] = v.G[i][j]?false:true;
				}
			    }

			    Integer cost = D.get(v);
			    if ( cost == null ){
				D.put(v, new Integer(ucost+1));
				Q.addElement(v);
			    } 
			}
		    }
		}
	    }
	    
	}
	return -1;

    }

    public static void main(String[] arg){ new Main(); }
}
