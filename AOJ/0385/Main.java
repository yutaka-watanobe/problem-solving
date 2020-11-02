import java.util.Scanner;

class Main{
  static final int INF = 2000000000;
  int N, diff;
  int[] A;
  Scanner sc;
    
  void update(int i, int v){
    if ( A[i - 1] > A[i] ) diff--;
    if ( A[i] > A[i + 1] ) diff--;
    A[i] = v;
    if ( A[i - 1] > A[i] ) diff++;
    if ( A[i] > A[i + 1] ) diff++;
  }
    
  void solve(){
    sc = new Scanner(System.in);
    N = sc.nextInt();
    A = new int[N + 2];
    for ( int i = 1; i <= N; i++ )  A[i] = sc.nextInt();
    A[0] = -INF;
    A[N + 1] = INF;
    System.out.println(sort());
  }
    
  int sort(){
    diff = 0;
    for ( int i = 1; i <= N; i++ ) 
      if ( A[i - 1] > A[i] ) diff++;

    if ( diff == 0 ) return 0;
    int Q = sc.nextInt();
    for ( int i = 1; i <= Q; i++ ){
      int x = sc.nextInt();
      int y = sc.nextInt();
      int v1 = A[x];
      int v2 = A[y];
      update(x, v2);
      update(y, v1);
      if ( diff == 0 ) return i;
    }
	
    return -1;
  }

  public static void main(String[] args){ new Main().solve(); }
}

