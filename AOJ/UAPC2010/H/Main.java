import java.util.*;

class Path{
    public Vector<Integer> P;
    Path(){
	P = new Vector<Integer>();
    }
}

public class Main{

    public static final int INFTY = 100000;

    int n, m, p;
    int[][] G;
    double[] E1;
    double[] E2;
    double[] A;

    boolean[] visited;

    public Main(){
	Scanner sc = new Scanner(System.in);
	while( true ){
	    n = sc.nextInt();
	    m = sc.nextInt();
	    p = sc.nextInt();
	    if ( n == 0 && m == 0 && p == 0 ) break;
	    G = new int[100][100];

	    int s, t, c;
	    for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n; j++ ) G[i][j] = INFTY;
	    }

	    for ( int i = 0; i < m; i++ ){
		s = sc.nextInt();
		t = sc.nextInt();
		c = sc.nextInt();
		G[t][s] = c;
		G[s][t] = c;
	    }
	    
	    compute();
	    
	    for ( int i = 0; i <p; i++ ){
		int x = sc.nextInt();
		System.out.println(A[x]);
	    }
	    System.out.println();
	}
    }

    public void dijkstra(Path[] P){
	int[] D = new int[100];
	boolean[] V = new boolean[100];
	for ( int i = 0; i < n; i++ ) {
	    D[i] = INFTY;
	    V[i] = false;
	}
	
	D[0] = 0;
	int u, minv;
	u = 0;
	while(true){
	    minv = INFTY;
	    for ( int i = 0; i < n; i++ ){
		if ( !V[i] && minv > D[i] ){
		    u = i;
		    minv = D[i];
		}
	    }
	    if ( minv == INFTY ) break;
	    V[u] = true;

	    for ( int v = 0; v < n; v++ ){
		if ( V[v] || G[u][v] == INFTY ) continue;

		if ( D[u] + G[u][v] == D[v] ){
		    P[v].P.addElement(new Integer(u));
		} else if (D[u] + G[u][v] < D[v]){
		    D[v] = D[u] + G[u][v];
		    P[v] = new Path();
		    P[v].P.addElement(new Integer(u));
		}
	    }
	}
    }

    public void compute(){
	Path[] P = new Path[100];
	for ( int i = 0; i < n; i++ ) P[i] = new Path();
	dijkstra(P);


	boolean[][] T1 = new boolean[100][100];
	boolean[][] T2 = new boolean[100][100];

	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < n; j++ ) {
		T1[i][j] = false;
		T2[i][j] = false;
	    }
	}

	for ( int u = 0; u < n; u++ ){
	    Vector<Integer> p = P[u].P;
	    for ( int j = 0; j < p.size(); j++ ){
		int v = p.elementAt(j).intValue();
		T1[v][u] = true;
		T2[u][v] = true;
	    }
	}

	E1 = new double[100];
	E2 = new double[100];
	A = new double[100];

	for ( int i = 0; i < n; i++ ) {
	    E1[i] = 0.0;
	    E2[i] = 0.0;
	}

	E1[n-1] = 1.0;
	visited = new boolean[100];
	for ( int i = 0; i < n; i++ ) visited[i] = false;
	dfs(0, T1, E1);
	

	E2[0] = 1.0;
	for ( int i = 0; i < n; i++ ) visited[i] = false;
	dfs(n-1, T2, E2);

	double base = E1[0];

	A[0] = A[n-1] = 1.0;
	for ( int i = 1; i < n-1; i++ ) A[i] = E1[i]*E2[i]/base;


    }

    void dfs(int u, boolean[][] T, double[] E){
	visited[u] = true;
	for ( int v = 0; v < n; v++ ){
	    if ( T[u][v] ) {
		if ( !visited[v] ) dfs(v, T, E);
		E[u] += E[v];
	    }
	}
    }


    public static void main(String[] args) { new Main(); }
}
