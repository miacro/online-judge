#include<cstdio>
int main(){
	const float PI=3.1415926;
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		float X,Y;
		scanf("%f %f",&X,&Y);
		int year=(PI*(X*X+Y*Y)/100.0);
		printf("Property %d: This property will begin eroding in year %d.\n",i,year+1);
	}
	printf("END OF OUTPUT.\n");
}
