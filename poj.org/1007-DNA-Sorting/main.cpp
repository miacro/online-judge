#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	char seq[100][51];
	for(int i=0;i<m;i++)
		scanf("%s",seq[i]);
	int inversions[100];
	for(int i=0;i<m;i++)
		inversions[i]=0;
	for(int i=0;i<m;i++)
		for(int j=1;j<n;j++)
			for(int k=1;k<=j;k++)
				if(seq[i][j]<seq[i][j-k])
					inversions[i]++;
	for(int i=0;i<m;i++)
		inversions[i]=inversions[i]*1000+i;
	sort(inversions,inversions+m);	
	for(int i=0;i<m;i++)
		inversions[i]%=1000;
	for(int i=0;i<m;i++)
	  printf("%s\n",seq[inversions[i]]);
}

