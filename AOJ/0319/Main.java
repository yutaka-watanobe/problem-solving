import java.util.Scanner;

class Main{
  void solve(){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] p = new int[N];
    for ( int i = 0; i < N; i++ )
      p[i] = sc.nextInt();


    for ( int i = 0; i < N - 2; i++ )
      for ( int j = N - 2; j >= i; j-- )
        if ( p[j] < p[j + 1] ){
	  int tmp = p[j];
	  p[j] = p[j + 1];
	  p[j + 1] = tmp;
        }

    int ans = 0;
    for ( int i = 0; i < N; i++ )
      if ( p[i] >= i + 1 ) ans = i + 1;

    System.out.println(ans);
  }

  public static void main(String[] args){
    new Main().solve();
  }
}



