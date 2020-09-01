import java.util.*;

class Main{
    int[] e;

    boolean check(){
	Arrays.sort(e);
	for ( int i = 0; i < 12; i += 4)
	    if ( e[i] != e[i+3] ) return false;
	return true;
    }

    void solve(){
	Scanner sc = new Scanner(System.in);
	e = new int[12];
	for ( int i = 0; i < 12; i++ ) e[i] = sc.nextInt();
	if ( check() == true ) System.out.println("yes");
	else System.out.println("no");
    }

    public static void main(String[] args){
	new Main().solve();
    }
}
