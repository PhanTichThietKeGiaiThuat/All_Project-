#include <iostream>
#define max 100 
#define m 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Bag_best(int b,int n,int w[max],int c[max],int MaxV[m][max])
{
	int L=0;
	int i=0;
	for(L=0;L<=b;L++) MaxV[0][L]=0;
	for(i=0;i<=n;i++) MaxV[i][0]=0;
	for(i=1;i<=n;i++)
	{
		for(L=1;L<=b;L++)
		{
			MaxV[i][L]=MaxV[i-1][L];
			if((L>=w[i])&&(MaxV[i-1][L-w[i]]+c[i]>MaxV[i-1][L]))
			MaxV[i][L]=MaxV[i-1][L-w[i]]+c[i];
			
		}
	}
	return MaxV[n+1][b+1];
}
void Trace(int MaxV[m][max],int w[max],int n,int b)
{
	int Chon[max];
	int v=b,k,i;
	while(v>0)
	{
		for(k=n;k>=0;k--)
		{
			Chon[k]=1;
			v=MaxV[k][v]-w[k];
		}
	}
	for(i=0;i<=n;i++)
	{
		if(Chon[i]==1)
	
		printf("%d %d",i,w[i]);
		
	}
}
int main(int argc, char** argv) {

	int n=6,b=19;
	int i,MaxV[m][max];
	int c[]={7,10,20,19,13,40};
	int w[]={3,4,5,7,6,9};

	Bag_best(19,6,w,c,MaxV);
	Trace(MaxV,w,6,19);
	return 0;
}
