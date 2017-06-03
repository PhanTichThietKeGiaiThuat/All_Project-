using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TL_Kruskal
{
    class Program
    {
     struct Egde
        {
            public int x, y;
        };
       public static void Kruskal(int[,]A,int n)
        {
            int[]D = new int[n];
            Egde[] L = new Egde[n - 1];
            int min, Dem = 0,Sum=0,  T = 0, Temp = 0;
            
            for (int i = 0; i < n; i++)
             D[i] = 0; 
            do
            {
                min = int.MaxValue;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (A[i, j] > 0 && min > A[i, j] && !(D[i] != 0 && D[i] == D[j]))
                        {
                            min = A[i, j];
                            L[Dem].x = i;
                            L[Dem].y = j;
                        }
                if(D[L[Dem].x]==0&&D[L[Dem].y]==0)
                {
                    T++;
                    D[L[Dem].x] = D[L[Dem].y]=T;
                    
                }
                if (D[L[Dem].x] == 0 && D[L[Dem].y] != 0)
                    D[L[Dem].x] = D[L[Dem].y];
                if (D[L[Dem].x] != 0 && D[L[Dem].y] == 0)
                    D[L[Dem].y] = D[L[Dem].x];
                if(D[L[Dem].x]!=D[L[Dem].y]&&D[L[Dem].y]!=0)
                {
                    Temp = D[L[Dem].x];
                    for (int i = 0; i < n; i++)
                        if (Temp == D[i])
                            D[i] = D[L[Dem].y];
                }
                Sum += min;
                Dem++;

            } while (Dem < n - 1);
            Console.WriteLine(Sum);
            for (int i = 0; i < n - 1; i++)

                Console.WriteLine("{0} -> {1}", L[i].x + 1, L[i].y + 1);
        }
        
       public static  void Main(string[] args)
        {
            int[,] A = {  {0,3,0,1,0,3,0 },
                          {3,0,4,0,0,6,0 },
                          { 0,4,0,3,7,0,5},
                          { 1,0,3,0,6,2,0},
                          {0,0,7,6,0,5,0 },
                          {3,6,0,2,5,0,1 },
                          { 0,0,5,0,0,1,0}
                        };
            int n =7;
            
            Kruskal(A, n);
            
            Console.ReadKey();
        }
    }
}
