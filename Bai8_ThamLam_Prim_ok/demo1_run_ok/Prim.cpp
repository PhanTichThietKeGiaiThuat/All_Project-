#include <iostream>
#define max 100
#define int_max 2147483647 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Prim(int c[max][max],int n)
{
	double Lowcost[max];
	int Closest[max];
	int i,j,k,Min;
	for(i=2;i<=n;i++)
	{
		Lowcost[i]=c[1][i];
		Closest[i]=1;
	}
	for(i=2;i<=n;i++)
	{
		Min=Lowcost[2];
		k=2;
		for(j=3;j<=n;j++)//chon k
		if(Lowcost[j]<Min)
		{
			Min=Lowcost[j];
			k=j;
		}
		printf("\nk=%d  closest=%d",k,Closest[k]);
		Lowcost[k]=int_max;
		//khoi dong lai closest,lowcost
		for(j=2;j<=n;j++)
		if(c[k][j]<Lowcost[j]&&Lowcost[j]<int_max)
		{
			Lowcost[j]=c[k][j];
			
			Closest[j]=k;
		}
	}
}
void nhap(int a[max][max],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		printf("a[%d][%d]=",i,j);
		scanf("%d",&a[i][j]);
	}
	
}
int main(int argc, char** argv) {
	int a[max][max];
	int n=7;
	
	nhap(a,n);
	Prim(a,n);
	return 0;
}
