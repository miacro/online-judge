#include<cstdio>
#include<cmath>
#include<algorithm>
int n;
int pairIn[1001][2];
int pairOutPixel[8001];
int pairOutPos[8001];
int pairInCount;
int pairOutPixelCount;
int pairOutPosCount;

int getPixel(int pos){
	int left=0,right=pairInCount-1;
	while(left<right){
		int mid=(left+right)/2;
		if(pairIn[mid][1]==(pos+1)){
			left=mid;
			break;
		}
		else if(pairIn[mid][1]<(pos+1))
			left=mid+1;
		else right=mid;
	}
	return pairIn[left][0];
}
int calPixel(int pos){
	int pixelCen=getPixel(pos);
	int max=0;
	int row=pos/n;
	int col=pos%n;
	for(int l=row-1;l<=row+1;l++)
		for(int m=col-1;m<=col+1;m++){
			if(l<0 || m<0 || (l*n+m)>=pairIn[pairInCount-1][1] || m>=n || (l==row&&m==col))
				continue;
			int pixelEdge=getPixel(l*n+m);
			max=(max>abs(pixelCen-pixelEdge))?max:abs(pixelCen-pixelEdge);
		}
	return max;
}
int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		pairInCount=0;
		pairOutPixelCount=0;
		pairOutPosCount=0;
		int position=0;
		int i=0,j=0;
		while(scanf("%d %d",&pairIn[pairInCount][0],&pairIn[pairInCount][1]),
				pairIn[pairInCount][0]!=0 || pairIn[pairInCount][1]!=0)
			position+=pairIn[pairInCount][1],pairIn[pairInCount++][1]=position;
		for(i=0;i<=pairInCount;i++){
			if(i==0)
				position=0;
			else position=pairIn[i-1][1];
			int row=position/n;
			int col=position%n;
			for(int j=row-1;j<=row+1;j++)
				for(int k=col-1;k<=col+1;k++){
					if(j<0 || k<0 || k>=n || (j*n+k)>=pairIn[pairInCount-1][1] ) 
						continue;
					pairOutPos[pairOutPosCount++]=j*n+k;
				}
			position=pairIn[i][1];
		}
		std::sort(pairOutPos,pairOutPos+pairOutPosCount);
		pairOutPos[pairOutPosCount++]=pairIn[pairInCount-1][1];
		int curPos=pairOutPos[0];
		pairOutPixel[pairOutPixelCount++]=calPixel(curPos);
		for(i=1;i<pairOutPosCount;i++)
			if(curPos!=pairOutPos[i]){
				pairOutPixel[pairOutPixelCount]=calPixel(curPos);
				j=curPos;
				curPos=pairOutPos[i];
				pairOutPos[pairOutPixelCount++]=j;
			}
		pairOutPos[pairOutPixelCount]=pairIn[pairInCount-1][1];
		printf("%d\n",n);
		int curPixel=pairOutPixel[0];
		curPos=pairOutPos[0];
		for(j=0;j<pairOutPixelCount;j++)
			if(curPixel!=pairOutPixel[j]){
				printf("%d %d\n",curPixel,pairOutPos[j]-curPos);
				curPixel=pairOutPixel[j];
				curPos=pairOutPos[j];
			}
		printf("%d %d\n0 0\n",curPixel,pairOutPos[pairOutPixelCount]-curPos);
	}
	printf("0\n");
}

