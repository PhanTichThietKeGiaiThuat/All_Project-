#include <stdio.h>
#include<conio.h>
#define max 100
#define int_max 2147483647
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int GTS(int a[max][max],int n,int TOUR[max],int Ddau)
{
	int v,k,w;
	int mini;
	int cost;
	int daxet[max];
	for(k=1;k<=n;k++)
		daxet[k]=0;
	cost=0;
	int i;
	v=Ddau;
	i=1;
	TOUR[i]=v;
	daxet[v]=1;	
	while(i<n)
	{
		mini=int_max;
		for(k=1;k<=n;k++)
		
			if(!daxet[k])
			
				if(mini>a[v][k])
				{
					mini=a[v][k];
					w=k;
				}
			
			
		
		v=w;
		i++;
		TOUR[i]=v;
		daxet[v]=1;
		cost+=mini;
	}
	cost+=a[v][Ddau];
	return cost;
		
	
}
void Input(int a[max][max],int n)
{

	int i=0,j=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		printf("a[%d][%d]=",i,j);
		scanf("%d",&a[i][j]);
		}
	
	}
	}
void Output(int TOUR[max],int n)
{
	int i=0;
	for(i=1;i<=n;i++)
	{
		printf("%d ",TOUR[i]);
	}
}
int main(int argc, char** argv) {
	int s=0;
	int a[max][max],TOUR[max],Ddau=1;	
	Input(a,5);
	s=GTS(a,5,TOUR,1);
	printf("s=%d\n",s);
	Output(TOUR,5);				
	return 0;
}
