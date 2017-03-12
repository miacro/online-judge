#include<cstdio>
#include<algorithm>
int sticks[64];
bool used[64];
int n;
int sum;
int usedCount;
int checkLen;
int sample;
bool dfs(int len,int indx){
	sample=-1;
	while((--indx)>=0){
		while(indx>=0 && ( used[indx]==true || sticks[indx]>len || sample==sticks[indx])){--indx;}
		if(indx<0)
			break;
		used[indx]=true;
		usedCount++;
		if(sticks[indx]==len){
			if(usedCount==n)
				return true;
			if(dfs(checkLen,n))
				return true;
			sample=sticks[indx];
		}
		if(sticks[indx]<len){
			if(dfs(len-sticks[indx],indx))
				return true;
			sample=sticks[indx];
		}
		used[indx]=false;
		usedCount--;
		if(checkLen==len)
			break;
	}
	return false;
}
int main(){
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++)
			used[i]=false;
		sum=0;
		usedCount=0;
		for(int i=0;i<n;i++)
			scanf("%d",sticks+i),sum+=sticks[i];
		std::sort(sticks,sticks+n);
		for(int i=sticks[n-1];i<=sum;i++)
			if(!(sum % i) && ( checkLen=i,dfs(i,n)) ){
				printf("%d\n",i);
				break;
			}
	}
}
