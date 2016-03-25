#include<cstdio>
int main(){
	float account,sum=0;
	int i=12;
	while(i--) scanf("%f",&account),sum+=account;
	printf("$%.2f\n",sum/12.0);
}


