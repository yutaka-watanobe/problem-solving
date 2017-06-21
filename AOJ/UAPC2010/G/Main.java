import java.util.*;

class Cube{
    int[] f;
    public Cube(){
	f = new int[6];
	for ( int i = 0; i < 6; i++ ) f[i] = i+1;
    }
    
    public void roll_z(){ roll(1, 2, 4, 3);}
    public void roll_y(){ roll(0, 2, 5, 3);}
    public void roll_x(){ roll(0, 1, 5, 4);}
    public void roll(int i, int j, int k, int l){
	int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }

    public void print(){
	for ( int i = 0; i < 6; i++ ) System.out.print(f[i]);
	System.out.println();
    }

    public int getValue(){
	int sum = 0;
	int p = 1;
	for ( int i = 5; i >= 0; i-- ){
	    sum += f[i]*p;
	    p *= 10;
	}
	return sum;
    }
}

public class Main{
    public static final int INFTY = 1000000;

    Hashtable<Integer, Integer> MP;
    Hashtable<Integer, Cube> PM;
    
    int H, W, si, sj, gi, gj;
    int[][] G;


    public Main(){
	init();
	
	Scanner sc = new Scanner(System.in);
	
	while(true){
	    H = sc.nextInt();
	    W = sc.nextInt();
	    if ( H == 0 && W == 0 ) break;
	    G = new int[10][10];

	    for ( int i = 0; i < H; i++ ){
		for ( int j = 0; j < W; j++ ){
		    G[i][j] = sc.nextInt();
		}
	    }
	    si = sc.nextInt();
	    sj = sc.nextInt();
	    gi = sc.nextInt();
	    gj = sc.nextInt();
	    System.out.println(dijkstra());
	}
    }

    // n^2 dijkstra
    int dijkstra(){
	int[][][] D = new int[10][10][24];
	int[][][] V = new int[10][10][24];

	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		for ( int k = 0; k < 24; k++ ){
		    D[i][j][k] = INFTY;
		    V[i][j][k] = 0;
		}
	    }
	}

	D[si][sj][0] = 0;

	int ui, uj, uk;
	ui = uj = uk = 0;
	Cube cube;
	int minv = INFTY;

	while(true){
	    minv = INFTY;

	    for ( int i = 0; i < H; i++ ){
		for ( int j = 0; j < W; j++ ){
		    for ( int k = 0; k < 24; k++ ){
			if ( V[i][j][k] == 0 && minv > D[i][j][k] ){
			    minv = D[i][j][k];
			    ui = i;
			    uj = j;
			    uk = k;
			}
		    }
		}
	    }
	    if ( minv == INFTY ) break;

	    V[ui][uj][uk] = 1;

	    cube = PM.get(new Integer(uk));

	    Cube ncube = new Cube();
	    int cost;
	    int index, uindex;

	    if ( ui > 0 ){
		for ( int i = 0; i < 6; i++ ) ncube.f[i] = cube.f[i];
		ncube.roll_x();
		index = MP.get(new Integer(ncube.getValue()));
		uindex = MP.get(new Integer(cube.getValue()));
		cost = ncube.f[5]*G[ui-1][uj] + D[ui][uj][uindex];
		if ( D[ui-1][uj][index] > cost && V[ui-1][uj][index] == 0){
		    D[ui-1][uj][index] = cost;
		}
	    }
	    if ( ui+1< H ){
		for ( int i = 0; i < 6; i++ ) ncube.f[i] = cube.f[i];
		for ( int i = 0; i < 3; i++ ) ncube.roll_x();
		index = MP.get(new Integer(ncube.getValue()));
		uindex = MP.get(new Integer(cube.getValue()));
		cost = ncube.f[5]*G[ui+1][uj] + D[ui][uj][uindex];
		if ( D[ui+1][uj][index] > cost && V[ui+1][uj][index] == 0 ){
		    D[ui+1][uj][index] = cost;
		}
	    }
	    if ( uj > 0 ){
		for ( int i = 0; i < 6; i++ ) ncube.f[i] = cube.f[i];
		ncube.roll_y();
		index = MP.get(new Integer(ncube.getValue()));
		uindex = MP.get(new Integer(cube.getValue()));
		cost = ncube.f[5]*G[ui][uj-1] + D[ui][uj][uindex];
		if ( D[ui][uj-1][index] > cost && V[ui][uj-1][index] == 0 ){
		    D[ui][uj-1][index] = cost;
		}
	    }
	    if ( uj+1< W ){
		for ( int i = 0; i < 6; i++ ) ncube.f[i] = cube.f[i];
		for ( int i = 0; i < 3; i++ ) ncube.roll_y();
		index = MP.get(new Integer(ncube.getValue()));
		uindex = MP.get(new Integer(cube.getValue()));
		cost = ncube.f[5]*G[ui][uj+1] + D[ui][uj][uindex];

		if ( D[ui][uj+1][index] > cost && V[ui][uj+1][index] == 0 ){
		    D[ui][uj+1][index] = cost;
		}
	    }
	}

	minv = INFTY;

	for ( int k = 0; k < 24; k++ ){
	    if ( D[gi][gj][k] < minv ) minv = D[gi][gj][k];
	}
	return minv;

    }

    public void init(){
	Cube c = new Cube();
	MP = new Hashtable<Integer, Integer>();
	PM = new Hashtable<Integer, Cube>();

	int id = 0;
	for ( int i = 0; i < 6; i++ ){
	    for (int j = 0; j < 4; j++ ){
		Cube nc = new Cube();
		for ( int k = 0; k < 6; k++ ) nc.f[k] = c.f[k];
		MP.put( nc.getValue(), id);
		PM.put(id, nc);
		id++;
		c.roll_z();
	    }
	    if ( i % 2 == 0 ) c.roll_y();
	    else c.roll_x();
	}
    }

    public static void main(String[] args) { new Main();}
}

