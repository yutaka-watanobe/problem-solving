#include<stdio.h>
#include<string.h>

int main(){
	int ba[101][2],n,m,i,j,c;
	
	while(0<=scanf("%d%d",&n,&m)){
		if(n==0 && m==0)break;
		
		//目的地番号と人数初期化
		memset(ba,0,sizeof(ba));
		
		
		//目的地番号代入と人数計算
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&c);
				if(c==1)++ba[j][1];
				ba[j][0]=j;
			}
		}
		
		//人数でソート
		for(i=1;i<=m;i++){
			for(j=i;j<=m;j++){
				if(ba[j][1]>ba[i][1]){
					c=ba[j][1];
					ba[j][1]=ba[i][1];
					ba[i][1]=c;
					
					c=ba[j][0];
					ba[j][0]=ba[i][0];
					ba[i][0]=c;
				}
			}
		}
		
		//出力
		for(i=1;i<=m;i++){
			printf("%d",ba[i][0]);
			if(i!=m)printf(" ");
		}
		printf("\n");
	}
	return 0;
}

