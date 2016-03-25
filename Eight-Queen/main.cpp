#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;
int size=8;
int *lines;
int count=0;

void set_place(int line);
void printdrg();
int main(int argc,char ** argv)
{
	if(argc>=2)
	{
		stringstream ss(argv[1]);
		ss>>size;
	}
	lines=new int[size];
	set_place(0);
	cout<<count<<endl;
	return 0;
}

void set_place(int line)
{
	if(line>=size)
	{
//		printdrg();
		count++;
	}
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<line;j++)
			if(lines[j]==i || abs(lines[j]-i)==abs(line-j))
				break;
		if(j>=line)
		{
			lines[line]=i;
			set_place(line+1);
		}
	}
}

void printdrg()
{
	cout<<endl;
	int i=0,j=0;
	int dvi=0;
	for(i=0;i<size;i++)
	{
		dvi=lines[i];
		for(j=0;j<dvi;j++)
			cout<<" [ ] ";
		cout<<" [o] ";
		for(j=dvi+1;j<size;j++)
			cout<<" [ ] ";
		cout<<endl<<endl;
	}
}
