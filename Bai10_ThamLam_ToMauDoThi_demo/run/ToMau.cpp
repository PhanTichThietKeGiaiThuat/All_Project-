#include <iostream>
#define max 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void input(int n,int a[max][max])
{
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)	
	{
		printf("a[%d][%d]=",i,j);
		scanf("%d",&a[i][j]);
	}
}
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int *Bac(int n,int a[max][max])
{
	int i,j;
	int *d=new int[n+1];
	for(i=1;i<=n;i++)
	{
		d[i]=0;
		for(j=1;j<=n;j++)
		d[i]=d[i]+a[i][j];
	}
	return d;
}
void sapxep(int n,int *d,int *&id)
{
	int i,j;
	id=new int[n+1];
	for(i=1;i<=n;i++) id[i]=i;
	for(i=1;i<n;i++)
	for(j=i+1;j<=n;j++)
	if(d[i]<d[j])
	{
		swap(d[i],d[j]);
		swap(id[i],id[j]);
	}
}
void tomau(int n,int a[max][max])
{
	int *m=new int[n+1];
	int *id,*d,i,j,k=0;
	d=Bac(n,a);
	sapxep(n,d,id);
	for(i=1;i<=n;i++)
	m[i]=0;
	for(i=1;i<=n;i++)
	if(m[id[i]]==0)
	{
		k++;
		m[id[i]]=k;
		for(j=i+1;j<=n;j++)
		if(m[id[j]]==0)
		{
			int t;
			for(t=1;t<=n;t++)
			if(m[t]==k&&a[id[j]][t]>0) break;
			if(t>n) m[id[j]]=k;
		}
	}
	printf("\n so mau su dung la: %d\n",k);
	for(j=1;j<=k;j++)
	{
		printf("\nMau %d:",j);
		for(i=1;i<=n;i++)
		if(m[i]==j) printf("%8d",i);
		}	
}
int main(int argc, char** argv) {
	int n=2;
	int a[max][max];
	input(n,a);
	tomau(n,a);
	return 0;
}
