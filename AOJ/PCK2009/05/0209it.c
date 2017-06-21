#include<stdio.h>
#include<string.h>
#include<math.h>

int ke[100][100],ki[50][50],tki[50][50],x,y,tx,ty;

int main(){
	int i,j,k,s,t,n,m;
	
	while(0<=scanf("%d%d",&n,&m)){
		if(n==0 && m==0)break;
		
		//景色と切れ端の入力
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&ke[j][i]);
			}
		}
		
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				scanf("%d",&ki[j][i]);
			}
		}
		
		//座標を初期化
		x=y=tx=ty=n;
		
		//多重ループ脱出用のフラグ
		int flag=1;
		
		//4回転のループ
		for(i=0;i<4;i++){
			
			//完全に重なる部分の探索
			for(j=0;j<n-m+1;j++){
				for(k=0;k<n-m+1;k++){
					//ここまで切れ端の移動
					
					//ここから切れ端と景色の照合
					flag=1;
					for(s=0;s<m;s++){
						for(t=0;t<m;t++){
							if(ki[t][s]==-1)continue;
							
							if(ki[t][s]!=ke[k+t][j+s]){
								flag=0;
								break;
							}
						}
						if(flag==0)break;
					}
					if(flag==1){
						for(s=0;s<m*m;s++){
							if(ki[s%m][s/m]!=-1)break;
						}
						tx=s%m+k;
						ty=s/m+j;
					}
					if(flag)break;
				}
				if(flag)break;
			}
			
			//見つかった座標が前回見つかったところより上側で左側なら代入
			if(tx<=x){
				if(tx<x){
					x=tx;
					y=ty;
					//if(x!=n)printf("%d %d %d\n",i,x,y);
				}else if(tx==x){
					if(ty<y){
						x=tx;
						y=ty;
						//if(x!=n)printf("%d %d %d\n",i,x,y);
					}
				}
			}
			
			
			//回転
			for(j=0;j<m;j++){
				for(k=0;k<m;k++){
					//printf("%d ",ki[k][j]);
					tki[k][j]=ki[m-j-1][k];
				}
				//printf("\n");
			}
			//printf("\n");
			memcpy(ki,tki,sizeof(ki));
		}
		
		//答え出力
		if(x==n)printf("NA\n");
		else printf("%d %d\n",x+1,y+1);
	}
	return 0;
}
