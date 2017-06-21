
import java.util.*;

class Main{
    

    char G[][];
    boolean V[][];
    
    int H, W;
    static final int[] di = {0, -1, 0, 1};
    static final int[] dj = {1, 0, -1, 0};
    
    public Main(){
	Scanner sc = new Scanner(System.in);

	while(true){
	    H = sc.nextInt();
	    W = sc.nextInt();

	    if ( H == 0 && W == 0 ) break;

	    //	    G = new char[H][W];
	    //	    V = new boolean[H][W];

	    G = new char[200][200];
	    V = new boolean[200][200];

	    for ( int i = 0; i < H; i++ ){
		String str = sc.next();
		for ( int j = 0; j < W; j++ ){
		    G[i][j] = str.charAt(j);
		    V[i][j] = false;
		}

	    }

	    int cnt = 0;
	    for ( int i = 0; i < H; i++ ){
		for ( int j = 0; j < W; j++ ){
		    if ( !V[i][j] ){
			bfs( i, j, G[i][j] );
			cnt++;
		    }
		}
	    }

	    System.out.println(cnt);


	}

    }

    private void bfs( int si, int sj, char ch ){
	Vector<Pair> q = new Vector<Pair>();
	
	Pair s = new Pair();

	q.addElement(new Pair(si, sj));
	V[si][sj] = true;
	int ni, nj;
	int i, j;
	while( q.size() >= 1 ){

	    //	    Pair u = q.elementAt(0);
	    i = q.elementAt(0).i;
	    j = q.elementAt(0).j;
	    //	    System.out.println(i + " " + j + "     " + q.size() );
	    q.remove(0);
	    
	    V[i][j] = true;

	    for ( int r = 0; r < 4; r++ ){
		ni = i + di[r];
		nj = j + dj[r];
		if ( ni < 0 || nj < 0 || ni >= H || nj >= W ) continue;
		if ( V[ni][nj] ) continue;
		if ( G[ni][nj] != ch ) continue;
		V[ni][nj] = true;
		q.addElement(new Pair(ni, nj));
	    }
	}

    }

    public static void main(  String[] a ){
	new Main();
    }

    class Pair{
	int i, j;
	Pair(){}
	Pair(int i, int j){
	    this.i = i;
	    this.j = j;
	}
    };
}
