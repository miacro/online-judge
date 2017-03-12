#include<cstdio>
#include<algorithm>
using namespace std;
void swap(int &n1,int &n2)
{
	int temp=n1;
	n1=n2;
	n2=temp;
}
void MaxHeapify(int *N,int n,int i)
{
    int left=2*i+1;
	int right=2*i+2;
	if(left>=n)	
		return;
	int index=left;
	if((right<n) && (N[right]>N[index]))
			index=right;
	if(N[index]>N[i])
	{
		swap(N[index],N[i]);
		MaxHeapify(N,n,index);
	}
}
 
void HeapSort(int *N,int n)	
{
	for(int i=n/2;i>=0;i--)
		 MaxHeapify(N,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(N[0],N[i]);
		MaxHeapify(N,--n,0);
	}
}

int main()
{
	int count;
	scanf("%d",&count);
	int phone_book[100000];
	int phone_count=0;
	int trans['Y'+1];
	trans['A']=trans['B']=trans['C']=trans['2']=2;
	trans['D']=trans['E']=trans['F']=trans['3']=3;
	trans['G']=trans['H']=trans['I']=trans['4']=4;
	trans['J']=trans['K']=trans['L']=trans['5']=5;
	trans['M']=trans['N']=trans['O']=trans['6']=6;
	trans['P']=trans['R']=trans['S']=trans['7']=7;
	trans['T']=trans['U']=trans['V']=trans['8']=8;
	trans['W']=trans['X']=trans['Y']=trans['9']=9;
	trans['0']=0;
	trans['1']=1;
	trans['-']=0;
	for(int i=0;i<count;i++)
	{
		int	num=0;
		int j=0;
		char phone[50];
		scanf("%s",phone);
		while(phone[j]!='\0')
		{
			if(phone[j]!='-')
				num=num*10+trans[phone[j]];
			j++;
		}		
		phone_book[phone_count++]=num;
	}
//	sort(phone_book,phone_book+phone_count);
	HeapSort(phone_book,phone_count);
	bool flag=false;
	int cur_num=phone_book[0];
	int cur_count=0;
	for(int i=0;i<phone_count;i++)
	{
			if(cur_num==phone_book[i])
				cur_count++;
			if( (i==phone_count-1) || (cur_num!=phone_book[i+1]) )
			{
				if(cur_count>1)
				{
					flag=true;
					printf("%03d-%04d %d\n",(cur_num)/10000,(cur_num)%10000,cur_count);
				}
				cur_num=phone_book[i];
				cur_count=1;
			}
	}
	if(flag==false)
		printf("No duplicates.\n");
}


