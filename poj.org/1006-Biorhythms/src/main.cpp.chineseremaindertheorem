#include<cstdio>
int main(){
	int p,e,i,d;
	int case_num=0;
	while(scanf("%d %d %d %d",&p,&e,&i,&d),p!=-1 || e!=-1 || i!=-1 || d!=-1){
		int days=(5544*p+14421*e+1288*i-d+21252)%21252;
		days==0?days=21252:days=days;
		printf("Case %d: the next triple peak occurs in %d days.\n",++case_num,days);
	}
}
