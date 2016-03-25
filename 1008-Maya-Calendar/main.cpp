#include<cstdio>
#include<cstring>
char haab_mon[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol",
						"chen","yax","zac","ceh","mac","kankin","muan","pax",
						"koyab","cumhu","uayet"};
char tzolkin_names[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik",
							"lamat","muluk","ok","chuen","eb","ben","ix","mem",
							"cib","caban","eznab","canac","ahau"};
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	while(n--){
		int date;
		char month[10];
		int year;
		scanf("%d. %s %d",&date,month,&year);
		int i=0;
		for(;i<19;i++)
			if(strcmp(haab_mon[i],month)==0)
				break;
		int totalDays=date+i*20+365*year;
		year=totalDays/260;
		date=totalDays%260;
		int number=(date)%13;
		int name=(date)%20;
		printf("%d %s %d\n",number+1,tzolkin_names[name],year);
	}		
}

