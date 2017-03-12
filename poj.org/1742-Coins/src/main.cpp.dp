#include<cstdio>
int main(){
	int n,m;
	int A[100];
	int C[100];
	while(scanf("%d %d",&n,&m),n!=0 && m!=0){
		for(int i=0;i<n;i++)
			scanf("%d",A+i);
		for(int i=0;i<n;i++)
			scanf("%d",C+i);
		int count=0;
		bool ind[100001]={false};
		ind[0]=true;
		for(int i=0;i<n;i++){
			int AUseCount[100001]={0};
			for(int j=A[i];j<=m;j++)
				if( (!ind[j]) && ind[ j-A[i] ] && AUseCount[ j-A[i] ]+1<=C[i] ){
					ind[j]=true;
					AUseCount[j]=AUseCount[ j-A[i] ]+1;
					count++;
				}
		}
		printf("%d\n",count);
	}
	return 0;
}
