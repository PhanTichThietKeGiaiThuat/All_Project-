#include <iostream>
#include<stdio.h>
#include<conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int p[8]={-2,-2,-1,-1,1,1,2,2};
int q[8]={-1,1,-2,2,-2,2,-1,1};
int d=0,x,y,m,n,a[50][50];
void inkq()
{
	printf("Cach di thu:%d ",++d);
	printf("\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%3d",a[i][j]);
		printf("\n");
	}
}
void tim(int x,int y,int k)
{
	if(k>m*n) inkq();
	else
	 for(int i=0;i<m;i++)
	 {
	 	int x1=x+p[i],y1=y+q[i];
	 	if(x1>=0&&x1<m&&y1>=0&&y1<n)
	 	if(a[x1][y1]==0)
	 	{
	 		a[x1][y1]=k;
	 		tim(x1,y1,k+1);
	 		a[x1][y1]=0;
		 }
	 }
}

int main(int argc, char** argv) {
	printf("Nhap kich thuoc ban co m,n :");
	scanf("%d%d",&m,&n);
	printf("Nhap vi tri xuat phat x,y :");
	scanf("%d%d",&x,&y);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	a[i][j]=0;
	a[x][y]=1;
	tim(x,y,2);
	if(d==0)
	printf("Khong co cach di nao thoa man");
	else printf("Co tat ca %d cach di thoa man",d);
	inkq();
	return 0;
}
