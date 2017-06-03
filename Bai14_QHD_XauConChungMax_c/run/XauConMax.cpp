#include <iostream>
#include<conio.h>
#include<string.h>
#define max 30

       void LCS(char X[max],char Y[max],char b[20][20])
        {
            int m = strlen(X);
            int n = strlen(Y);
            int i, j;
            int c[m][n];
            for ( i = 1; i <=m; i++) c[i][0] = 0;
            for ( j = 1; j <=n; j++) c[0][j] = 0;
            for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                    if(X[i]==Y[j])
                    {
                        c[i][j] = c[i - 1][j - 1] + 1;
                        b[i][j] = 'k';
                    }
                    else
                    {
                        if(c[i-1][j]>=c[i][j-1])
                        {
                            c[i][j] = c[i - 1][j];
                            b[i][j] = 'c';
                        }
                        else
                        {
                            c[i][j] = c[i][j - 1];
                            b[i][j] = 'd';
                        }
                    }
            for(i=0;i<m;i++)
            {
            	for(j=0;j<n;j++)
            	{
            		printf("%c ",b[i][j]);
				}
				printf("\n");
			}

   }
      void Road(char X[],char Y[],char b[20][20])
        {
            int m = strlen(X);
            int n = strlen(Y);
            char s[30];
           while(m>=0&&n>=0)
            {
                if (b[m][n] == 'k')
                {
                    s[--m] = X[m - 1];
                    m--;
                    n--;
                }
                else if (b[m][n] == 'c')
                    m--;
                else n--;
            }
           for(int i=1;i<=strlen(s);i++)
            {

				printf(" %c ",s[i]);
            }
        }
    int main(int argc, char *argv[])
        {
            char X[] = { 'T','O','A','N','H','O','C'};
            char Y[] = { 'H','O','A','H','O','N','G'};
     
            char b[20][20]; 
            LCS(X, Y,b);
            Road(X, Y,b);
            getch();
        
            

        }
    


