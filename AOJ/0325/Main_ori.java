import java.util.*;

class Main{

    boolean check(){
	Scanner sc = new Scanner(System.in);
	Rect[] D = new Rect[6];

	for ( int i = 0; i < 6; i++ ) {
	    D[i] = new Rect(0, 0);
	    D[i].h = sc.nextInt();
	    D[i].w = sc.nextInt();
	    if ( D[i].h > D[i].w) {
		int tmp = D[i].h;
		D[i].h = D[i].w;
		D[i].w = tmp;
	    }
	}
	Arrays.sort(D, new Comparator<Rect>(){
		public int compare(Rect a, Rect b){
		    if ( a.h == b.h ) return a.w - b.w;
		    return a.h - b.h;
		}
	    });
	for ( int i = 0; i < 6; i+=2){
	    if ( D[i].h == D[i+1].h && D[i].w == D[i+1].w ) D[i/2] = D[i];
	    else return false;
	}
	
	return D[0].h == D[1].h && D[0].w == D[2].h && D[1].w == D[2].w;
    }
    
    void solve(){
	if ( check() ) System.out.println("yes");
	else System.out.println("no");
    }
    
    class Rect{
	public int h;
	public int w;
	
	Rect (int h, int w) {
	    this.h = h;
	    this.w = w;
	}
    }
    
    public static void main(String[] args){ new Main().solve(); }
}


