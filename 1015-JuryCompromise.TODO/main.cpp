#include<cstdio>
int abs(int a){return a>=0?a:-a;}
int main(){
	int n;
	int m;
	int d[201];
	int p[201];
	int ind=0;
	int diff[201];
	int sum[201];
	int dp[21][401]={-1};
	while(scanf("%d %d",&n,&m),ind++,n!=0&&m!=0){
		for(int i=1;i<=n;i++)
			scanf("%d %d",p+i,d+i),diff[i]=d[i]-p[i],sum[i]=d[i]+p[i];
		//		for(int i=0;i<401;i++)
		dp[0][1]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)
				for(int k=1;k<401;k++){
					if(dp[j][k]>=0)
						if(abs(k+diff[i])<=400)
							if(dp[j+1][abs(k+diff[i])]<(dp[j][k]+sum[i]))
								dp[j+1][abs(k+diff[i])]=dp[j][k]+sum[i];
				}
		for(int i=0;i<401;i++)
			printf("%d\n",dp[m][i]);	

		//		for(int i=1;i<=n;i++)
		//		printf("%d %d\n",diff[i],sum[i]);
		printf("Jury #%d\n",ind);
//		printf("Best jury has value %d for prosecution and value %d for defence:\n",D[v],P[v]);
//		printf("\n\n");
	}
	return 0;
}
