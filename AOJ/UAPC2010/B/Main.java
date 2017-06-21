import java.util.*;

class Task{
    public int cost, lim;
    public Task(int cost, int lim){
	this.cost = cost;
	this.lim = lim;
    }
}

public class Main{

    public Main(){
	Scanner sc = new Scanner(System.in);
	int n;
	Task[] T;
	int cost, lim;
	while(true){
	    n = sc.nextInt();
	    if ( n == 0 ) break;
	    T = new Task[n];
	    for ( int i = 0; i < n; i++ ){
		cost = sc.nextInt();
		lim = sc.nextInt();
		T[i] = new Task(cost, lim);
	    }

	    for ( int end = n-2; end >= 0; end-- ){
		for ( int j = 0; j <= end; j++ ){
		    if ( T[j].lim > T[j+1].lim ){
			Task tmp = T[j];
			T[j] = T[j+1];
			T[j+1] = tmp;
		    }
		}
	    }
	    
	    boolean suc = true;
	    int cur = 0;
	    for ( int i = 0; i < n; i++ ){
		cur += T[i].cost;
		if ( cur > T[i].lim ) suc = false;

	    }
	    
	    if ( suc ){
		System.out.println("Yes");
	    } else {
		System.out.println("No");
	    }

	}


    }

    public static void main(String[] args) { new Main(); }
}

