#include<cstdio>
#include<algorithm>
const int MAX_STAMPS_COUNT=4;
int stampsDenominations[53];
int stampsTypeCount=0;

int currentMatchCase[4]; //subscript
int currentMatchCount=0;
int currentMatchTypeCount=0;

int tempBestMatchCase[4];//subscript
int tempBestTypeCount=0;
int tempBestStampsCount=0;
bool isTie;

void copyCurrentToTempBest(int typeCount,int type){
	int j=0;
	for(;j<currentMatchCount-typeCount;j++)
		tempBestMatchCase[j]=currentMatchCase[j];
	for(;j<currentMatchCount;j++)
		tempBestMatchCase[j]=type;
	tempBestTypeCount=currentMatchTypeCount;
	tempBestStampsCount=currentMatchCount;
	isTie=false;
}

void calRequestSolution(int type,int request){
	if(type==stampsTypeCount){
		return;
	}
	for(int i=0;i<=MAX_STAMPS_COUNT;i++){
		if(currentMatchCount+i>MAX_STAMPS_COUNT)
			return;

		int tempCount=currentMatchCount;
		int tempTypeCount=currentMatchTypeCount;
		if(i!=0)
			currentMatchTypeCount++;
		currentMatchCount+=i;

		if(request==i*stampsDenominations[type]){
			if(currentMatchTypeCount<tempBestTypeCount){
				currentMatchCount=tempCount;
				currentMatchTypeCount=tempTypeCount;
				return;
			}
			if(currentMatchTypeCount>tempBestTypeCount){
				copyCurrentToTempBest(i,type);
				currentMatchCount=tempCount;
				currentMatchTypeCount=tempTypeCount;
				return;
			}
			if( currentMatchCount > tempBestStampsCount ){
				currentMatchCount=tempCount;
				currentMatchTypeCount=tempTypeCount;
				return;
			}
			if( currentMatchCount < tempBestStampsCount ){
				copyCurrentToTempBest(i,type);
				currentMatchCount=tempCount;
				currentMatchTypeCount=tempTypeCount;
				return;
			}
			if( stampsDenominations[type] < stampsDenominations [ tempBestMatchCase[tempBestStampsCount-1] ] ){
				currentMatchCount=tempCount;
				currentMatchTypeCount=tempTypeCount;
				return;
			}
			if(stampsDenominations[type] > stampsDenominations [ tempBestMatchCase[tempBestStampsCount-1] ] ){
				copyCurrentToTempBest(i,type);
				currentMatchCount=tempCount;
				currentMatchTypeCount=tempTypeCount;
				return;
			}
			isTie=true;
			currentMatchCount=tempCount;
			currentMatchTypeCount=tempTypeCount;
			return;
		}
		if(request<i*stampsDenominations[type]){
			currentMatchCount=tempCount;
			currentMatchTypeCount=tempTypeCount;
			return;
		}
		for(int j=currentMatchCount-i;j<currentMatchCount;j++)
			currentMatchCase[j]=type;
		calRequestSolution(type+1,request-i*stampsDenominations[type]);
		currentMatchCount=tempCount;
		currentMatchTypeCount=tempTypeCount;
	}
}
int main(){
	int stampDe=0;
	while(1){
		while(scanf("%d",&stampDe)!=EOF && stampDe!=0)
			stampsDenominations[stampsTypeCount++]=stampDe;
		if(stampsTypeCount==0)
			break;
		std::sort(stampsDenominations,stampsDenominations+stampsTypeCount);
		int customerRequest;
		while(scanf("%d",&customerRequest)!=EOF && customerRequest!=0 ){
			tempBestStampsCount=0;
			tempBestTypeCount=0;
			currentMatchCount=0;
			currentMatchTypeCount=0;
			isTie=false;
			calRequestSolution(0,customerRequest);
			printf("%d ",customerRequest);
			if(tempBestStampsCount==0)
				printf("---- none\n");
			else{
				printf("(%d):",tempBestTypeCount);
				if(isTie)
					printf(" tie\n");
				else{
					for(int i=0;i<tempBestStampsCount;i++)
						printf(" %d",stampsDenominations[tempBestMatchCase[i]]);
					printf("\n");
				}
			}
		}
		stampsTypeCount=0;
	}
}

