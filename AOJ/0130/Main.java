import java.util.*;

class Main{
    
    void solve(){
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	for ( int t = 0; t < n; t++ ) {
	    String s = sc.next();
	    String form = "";         
	    form += s.charAt(0);
	    for (int i = 3; i < s.length(); i += 3){
		if ( form.indexOf(s.charAt(i)) != -1 ) continue;
		if ( s.charAt(i-1) =='>' ) form += s.charAt(i);
		else form = s.charAt(i) + form;
	    }
	    System.out.println(form);
	}
    }

    public static void main(String[] args){ new Main().solve(); }
}
