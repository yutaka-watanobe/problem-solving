import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		while(true){
			X = sc.nextInt();
			Y = sc.nextInt();
			if((X | Y)==0) break;
			
			yx = new int[Y][X];
			for(int i=0; i<Y; i++){
				for(int j=0; j<X; j++){
					yx[i][j] = sc.nextInt();
				}
			}
			memo = new int[Y][X];
			for(int i=0; i<Y; i++){
				for(int j=0; j<X; j++){
					memo[i][j] = -1;
				}
			}
			int ans =0;
			for(int i=0; i<X; i++){
				if(yx[0][i]==0){
					ans += fx(i,0);
				}
			}
			System.out.println(ans);
		}
	}
	static int X,Y;
	static int[][] yx,memo;
	static int fx(int x, int y){
		if(y==Y-1) return 1;
		if(memo[y][x]>=0) return memo[y][x];
		
		int res =0;
		//左へ移動する場合
		if(0<x && yx[y+1][x-1]==0){
			res += fx(x-1,y+1);
		}
		//まっすぐ降りる場合
		if(yx[y+1][x]==0){
			res += fx(x,y+1);
		}
		else if(yx[y+1][x]==2){
			res += jump(x,y+1);
		}
		//右へ移動する場合
		if(x<X-1 && yx[y+1][x+1]==0){
			res += fx(x+1,y+1);
		}
		
		memo[y][x] = res;
		return res;
	}
	static int jump(int x,int y){
		if(y>=Y-1) return 1;
		
		if(yx[y][x]==0){
			return fx(x,y);
		}
		else if(yx[y][x]==1){
			return 0;
		}
		else{
			return jump(x,y+2);
		}
	}
}