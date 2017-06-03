#include <iostream>
#include<fstream>
using namespace std;
struct packed
{
	int W,V;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Input(int &n,int &M,packed *&A)
{
	ifstream fi("input.txt");
	fi>>n>>M;
	A=new packed[n+1];
	for(int i=1;i<=n;i++)
	{
		fi>>A[i].W>>A[i].V;
		fi.get();
	}fi.close();
}
void Optimise(int n,int M,packed A[],int **&F)
{
	F=new int*[n+1];
	for(int i=0;i<=n;i++)
	F[i]=new int [M+1];
	Memset(F[0],0,M);
	for(int i=1;i<=n;i++)
	for(int j=0;j<=M;j++)
	{
		if(A[i].W<=j&&A[i].V+F[i-1][j-A[i].W]>F[i-1][j])
		F[i][j]=F[i-1][j-A[i].W]+A[i].V;
		else
		
		F[i][j]=F[i-1][j];
		
	}
}
void Output(int **F,packed A[],int n,int M)
{
	ofstream fo("output.txt");
	fo<<F[n][M]<<endl;
	for(;n>0;n--)
	if(F[n][M]!=F[n-1][M])
	{
		fo<<n<<endl;
		M-=A[n].W;
	}
	fo.close();
}
int main(int argc, char** argv) {
	int n,M;
	packed *A;
	int **F;
	Input(n,M,A);
	Optimise(n,M,A,F);
	Output(F,A,n,M);
	delete []A;
	for(int i=0;i<=n;i++)
	delete []F[i];
	delete []F;
	return 0;
}
