import java.io.*;
import java.util.*;
class Main {
    void solve(){
        Scanner sc = new Scanner( System.in );
        int a = sc.nextInt();
        int t = sc.nextInt();
        int r = sc.nextInt();
        System.out.println(1.0 * r * t / a);
    }
    public static void main( String[] a ) {new Main().solve(); }
}
