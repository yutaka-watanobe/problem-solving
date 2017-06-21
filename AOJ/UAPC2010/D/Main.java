import java.util.*;

class Button{
    public int x1, y1, x2, y2;
    public String target;
    public Button(int x1, int y1, int x2, int y2, String target){
	this.x1 = x1;
	this.y1 = y1;
	this.x2 = x2;
	this.y2 = y2;
	this.target = target;
    }
}

class Page{
    public Vector<Button> B;
    public int nbt;
    public String name;

    public Page(String name, int nbt){
	this.name = name;
	this.nbt = nbt;
	B = new Vector<Button>();
    }

    public String getTarget(int x, int y){
	for ( int i = 0; i < B.size(); i++ ){
	    Button b = B.elementAt(i);
	    if ( b.x1 <= x && x <= b.x2 &&
		 b.y1 <= y && y <= b.y2 ) return b.target;
	}
	return name;
    }

}
public class Main{
    int n, H, W;
    Vector<Page> P;
    Hashtable<String, Integer> T;
    Scanner sc = new Scanner(System.in);

    public Main(){
	while(true){
	    n = sc.nextInt();
	    if ( n == 0 ) break;
	    W = sc.nextInt();
	    H = sc.nextInt();
	    P = new Vector<Page>();
	    T = new Hashtable<String, Integer>();
	    int nbt;
	    String name = "";
	    for ( int  i = 0; i < n; i++ ){
		name = sc.next();
		nbt = sc.nextInt();
		Page p = new Page(name, nbt);
		for ( int j = 0; j < nbt; j++ ){
		    int x1 = sc.nextInt();
		    int y1 = sc.nextInt();
		    int x2 = sc.nextInt();
		    int y2 = sc.nextInt();
		    String target = sc.next();
		    Button b = new Button(x1, y1, x2, y2, target);
		    p.B.addElement(b);
		}
		P.addElement(p);
		T.put(name, new Integer(i));
	    }
	    simulate();
	}
    }

    void simulate(){
	int q = sc.nextInt();
	int x, y;
	String com = "";
	int[] history = new int[10000];
	int top = 0;
	int forward = 0;
	history[top] = 0;

	for ( int i = 0; i < q; i++ ){
	    com = sc.next();
	    if ( com.equals("click") ){
		x = sc.nextInt();
		y = sc.nextInt();

		int next = T.get(P.elementAt(history[top]).getTarget(x, y)).intValue();

		if ( next != history[top] ){
		    history[++top] = next;
		    forward = top;
		}
	    } else if ( com.equals("back") ){
		if ( top-1 >= 0 ) top--;
	    } else if ( com.equals("forward") ){
		if ( top < forward ) top++;
	    } else if ( com.equals("show") ){
		System.out.println(P.elementAt(history[top]).name);
	    }
	}
    }
    public static void main(String[] args){ new Main(); }
}
