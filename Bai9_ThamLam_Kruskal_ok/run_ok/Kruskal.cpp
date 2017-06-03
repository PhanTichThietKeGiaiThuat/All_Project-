#include <iostream>
#define int_max 2147483647
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Egde{
	int x,y;
};
void Kruskal(int a[100][100],int n)
{
	char *D=new char[n];
	Egde *L=new Egde[n-1];
	int i,j,min,Dem=0,sum=0,T=0,temp;
	for(i=0;i<n;i++)
		D[i]=0;
	do{
		min=int_max;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		if(a[i][j]>0&&min>a[i][j]&&!(D[i]!=0&&D[i]==D[j]))
		{
			min=a[i][j];
			L[Dem].x=i;
			L[Dem].y=j;
			
		}
		//tao cay moi
		if(D[L[Dem].x]==0&&D[L[Dem].y]==0)
		{
			T++;
			D[L[Dem].x]=D[L[Dem].y]=T;
		}
		//dua dinh tuong ung vao cay
		if(D[L[Dem].x]==0&&D[L[Dem].y]!=0)
			D[L[Dem].x]=D[L[Dem].y];
		//dua dinh tuong ung vao cay
		if(D[L[Dem].x]!=0&&D[L[Dem].y]==0)
			D[L[Dem].y]=D[L[Dem].x];
		//ghep hai cay thanh 1 cay moi
		if(D[L[Dem].x]!=D[L[Dem].y]&&D[L[Dem].y]!=0)
		{
			temp=D[L[Dem].x];
			for(i=0;i<n;i++)
			if(temp==D[i])
			D[i]=D[L[Dem].y];
		}
		sum+=min;
		Dem++;
		
	}
	while(Dem<n-1);
	printf("Sum=%d\n",sum);
	for(i=0;i<n-1;i++)
	printf("  %d --> %d ",L[i].x+1,L[i].y+1);
}
void input(int** a,int n)
{
	
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
int main(int argc, char** argv) {
	int a[100][100]= {    {0,3,0,1,0,3,0 },
                          {3,0,4,0,0,6,0 },
                          { 0,4,0,3,7,0,5},
                          { 1,0,3,0,6,2,0},
                          {0,0,7,6,0,5,0 },
                          {3,6,0,2,5,0,1 },
                          { 0,0,5,0,0,1,0}
                        };
	int n=7;
//	input(a,n);
	Kruskal(a,n);
	return 0;
}
