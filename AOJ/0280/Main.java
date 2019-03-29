import java.util.*;

class Main{
    
    void play(String line, int N){
	int[] C = new int[N];
	int B = 0;
	for (int i = 0; i < N; i++ ) C[i] = 0;
	
	for ( int i = 0; i < line.length(); i++ ){
	    int p = i%N;
	    if ( line.charAt(i) == 'M' ){
		C[p]++;
	    } else if ( line.charAt(i) == 'S' ){
		C[p]++;
		B += C[p];
		C[p] = 0;
	    } else if ( line.charAt(i) == 'L' ){
		C[p] += B + 1;
		B = 0;
	    }
	}
	
	Arrays.sort(C);
	
	for ( int i = 0; i < N; i++ ) System.out.print(C[i] + " ");
	System.out.println(B);
    }
    
    void solve(){
	int N;
	String line;
	Scanner sc = new Scanner(System.in);
	while(true){
	    N = sc.nextInt();
	    if ( N == 0 ) break;
	    line = sc.next();
	    play(line, N);
	}
    }

    public static void main(String[] args){ new Main().solve(); }
}
