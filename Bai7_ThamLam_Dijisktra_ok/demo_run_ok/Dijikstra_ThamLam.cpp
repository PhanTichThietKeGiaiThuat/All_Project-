#include <iostream>
#define max 100
#define int_max 2147483647
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void nhap(int a[max][max],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void xuatdd(int s,int k,int Ddnn[max])
{
	int i;
	printf("\nDuong di ngan nhat tu %d den %d la:",s,k);
	i=k;
	while(i!=s)
	{
		printf("%d <---",i);
		i=Ddnn[i];
	}
	printf("%d",s);
}
void Dijikstra(int s,int a[max][max],int n)
{
	int Ddnn[max];//chua duong di ngan nhat tu dinh s den dinh t tai moi buoc
	int i,k,Dht,Min;
	int Daxet[max];//danh dau cac dinh da dua vao S
	int L[max];
	for(i=1;i<=n;i++)
	{
		Daxet[i]=0;
		L[i]=int_max;
	}
	//dua dinh s vao tap dinh S da xet
	Daxet[s]=1;
	L[s]=0;
	Dht=s;
	int h=1;//dem moi buoc cho du n-1 buoc
	while(h<=n-1)
	{
		Min=int_max;
		for(i=1;i<=n;i++)
		if(!Daxet[i])
		{
			if(L[Dht]+a[Dht][i]<L[i])//tinh lai nhan
			{
				L[i]=L[Dht]+a[Dht][i];
				Ddnn[i]=Dht;
				//gan dinh hien tai la dinh truoc dinh i tren lo trinh
			}
			if(L[i]<Min)//chon dinh k
			{
				Min=L[i];
				k=i;
			}
		}
		//tai buoc h:tim duoc duong di ngan nhat tu s den k: Ddnn[]
		xuatdd(s,k,Ddnn);
		printf("\nTrong so:%d ",L[k]);
		Dht=k;//khoi dong lai Dht
		Daxet[Dht]=1;
		h++;
	}
}
int main(int argc, char** argv) {
	int a[max][max];
	int n;
	printf("n=");
	scanf("%d",&n);
	nhap(a,n);
	Dijikstra(1,a,n);
	
	return 0;
}
