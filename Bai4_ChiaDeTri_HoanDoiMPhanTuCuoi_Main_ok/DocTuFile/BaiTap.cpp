#include<conio.h>
#include<stdio.h>
int n,m,a[30];

void Exchange(int a[], int i, int j, int m,int n) {
	for (int p = n-1; p >n-m-1 ; p--)
	{
		int c = a[p-i];
		a[p-i] = a[p-j];
		a[p-j] = c;
	}
}
//
void Input()
{
//	int choose=0;
    FILE *f;

//    printf("1.file 1");
//    printf("2.file 2");
//    printf("3.file 3");
//    printf("4.file 4");
//    printf("5.file 5");
//    printf("choose file:");
//    scanf("%d",&choose);
//    switch(choose)
//    {
//    	case 1:
//    		    f = fopen("Exercise.txt", "r");
//    		    break;
//    	case 2:
//    		    f = fopen("Exercise1.txt", "r");
//    		    break;
//    	case 3:
//    		    f = fopen("Exercise2.txt", "r");
//    		    break;
//    	case 4:
//    		    f = fopen("Exercise3.txt", "r");
//    		    break;
//    	case 5:
//    		    f = fopen("Exercise4.txt", "r");
//    		    break;
//	}
    f = fopen("Exercise.txt", "r");
    if(!f)
    {
          puts("Error: could not open file");
    }
    fscanf(f, "%d", &n);//so phan tu mang
    fscanf(f, "%d", &m);//so phan tu muon hoan doi
    for(int j=0; j<n; j++)
    {
          fscanf(f, "%d", &a[j]);
    }

}
//
void Output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

//
void Transpose(int a[], int n, int m) {
	int i = m, j = n - m;
	
	while (i != j) {
		if (i > j) {
			Exchange(a, m - i, m, j,n );	
			for(int t=0;t<n;t++)
			Output(a,n);
			printf("\n\n");
			i = i - j;
		}
		else {
			j = j - i;
			Exchange(a, m - i, m + j, i,n);
			Output(a,n);
			printf("\n\n");
		}
	}
	Exchange(a, m - i, m, i,n);
	Output(a,n);
	printf("\n\n");
}

int main() {


	Input();
	printf("\n Input array: ");
	Output(a,10);
	printf("\n");
	Transpose(a, n, m);
	printf("\n Result:  ");
	Output(a, 10);
	_getch();


}
