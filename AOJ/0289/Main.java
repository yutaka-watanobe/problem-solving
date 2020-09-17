import java.util.*;

class Main{
  // srcからdstまでの最短距離を求める
  int dist(int src, int dst) {
    int answer = 0;
    if (src == dst) return 0;
    if (src % 2 != 0) { answer++; src++; }
    if (dst % 2 != 0) { answer++; dst--; }
    answer += dist(src / 2, dst / 2);
    return answer;
  }
    
  void solve(){
    int N, s, d;
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    for ( int i = 0; i < N; i++ ){
      s = sc.nextInt();
      d = sc.nextInt();
      System.out.println(dist(s, d));
    }
  }

  public static void main(String[] args){ new Main().solve();} 
}
