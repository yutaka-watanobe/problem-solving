import java.util.*;

public class Main{

    int n;

    int[][] G, P;
    int[] C;

    public Main(){
	Scanner sc = new Scanner(System.in);
	while(true){
	    n = sc.nextInt();

	    if ( n == 0 ) break;
	    G = new int[n][2];
	    P = new int[n][2];
	    C = new int[n];

	    for ( int i = 0; i < n; i++ ){
		int v1, v2, c1, c2;
		v1 = sc.nextInt();
		c1 = sc.nextInt();
		v2 = sc.nextInt();
		c2 = sc.nextInt();
		G[i][0] = v1;
		G[i][1] = v2;
		P[i][0] = c1;
		P[i][1] = c2;
	    }
	    compute();
	}
    }
    
    void compute(){
	for ( int i = 0; i < n; i++ ) C[i] = -1;
	int color = 0;
	for ( int i = 0; i < n; i++ ){
	    if ( C[i] == -1 ) {
		bfs(i, color);
		color++;
	    }
	}

	int[] MV = new int[color];
	int[] MC = new int[color];
	for ( int i = 0 ; i < color; i++ ) MV[i] = MC[i] = 0;

	for ( int i = 0; i < n; i++ ){
	    int g = C[i];
	    MV[g] = Math.max(MV[g], P[i][0]);
	    MV[g] = Math.max(MV[g], P[i][1]);
	}

	for ( int i = 0; i < n; i++ ){
	    int g = C[i];
	    if ( MV[g] == P[i][0] ) MC[g]++;
	    if ( MV[g] == P[i][1] ) MC[g]++;
	}

	for ( int i = 0; i < color; i++ ){
	    MC[i] /= 2;
	}

	int p = 1;
	for ( int i = 0; i < color; i++ ){
	    p = (p*MC[i])%10007;
	}

	System.out.println(p);


    }
    
    void bfs(int s, int color){
	Vector<Integer> Q = new Vector<Integer>();
	Q.addElement(s);

	int u;
	while( Q.size() > 0 ){
	    u = Q.elementAt(0); Q.remove(0);
	    C[u] = color;
	    for ( int i = 0; i < 2; i++ ){
		int v = G[u][i];
		if ( C[v] == -1 ){
		    Q.addElement(v);
		}
	    }
	}
    }

    public static void main(String[] args){
	new Main();
    }
}
