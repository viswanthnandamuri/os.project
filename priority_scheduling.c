#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class cpuschedule
{
	int n,Bu[20];
	float Twt,Awt,A[10],Wt[10],w;
public:
	//Getting the No of processes & burst time
	void Getdata();
		void Priority();
};

//Getting no of processes and Burst time
void cpuschedule::Getdata()
{
	int i;
	cout<<"Enter the no of processes:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cout<<"Enter The BurstTime for Process p"<<i<<"=	"<<endl;
		cin>>Bu[i];
	}
}

void cpuschedule::Priority()
{
	int i,B[10],P[10],j;
	w=0.0;
	int max;
	Twt=0.0;
	max=1;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p"<<i<<"=	"<<endl;
		cout<<B[i];
		cout<<"Enter the priority for process P"<<i<<"=	"<<endl;
		cin>>P[i];
		if(max<P[i])
			max=P[i];
	}
	j=1;
	while(j<=max)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				Wt[i]=w;
				w=w+B[i];
			}
			i++;
		}
		j++;
	}

	//calculating average weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total   Weighting Time="<<Twt<<""<<endl;
	cout<<"Average Weighting Time="<<Awt<<""<<endl;
}
int main()
{
	int ch,cho;
	cpuschedule c;
	do
	{
		cout<<"	 MENU"<<endl;
		cout<<"1.Getting process & BurstTime"<<endl;
		cout<<"2.Priority"<<endl;
		cout<<"3.EXIT"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			c.Getdata();
			break;
		case 2:
			cout<<"PRIORITY SCHEDULING"<<endl;
			c.Priority();
			break;
		case 3:
			break;
		}
	}while(ch<=3);
}
