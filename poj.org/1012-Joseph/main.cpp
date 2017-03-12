#include<cstdio>
int main(){
	int k,m,position,restPerson;
	int res[14]={0};
	while(scanf("%d",&k),k!=0){
		if(res[k]!=0){
			printf("%d\n",res[k]);
			continue;
		}
		m=k+1;
		while(true){
			position=0;
			restPerson=2*k;
			while(restPerson>k){
				position=(m+position-1)%restPerson;
				if(position<=k-1) break;
				--restPerson;
			}
			if(restPerson<=k){
				res[k]=m;
				break;
			}
			if(m%(k+1)==1)
				m+=k;
			else m++;
		}
		res[k]=m;
		printf("%d\n",res[k]);
	}
	return 0;
}
