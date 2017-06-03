using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QHD_DuongDiNganNhat_Floyd
{
    class Program
    {
        public static void Floyd(int[,] d,int[,]p,int[,]a,int n)
        {
            int i, j, k;
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                {
                    d[i, j] = a[i, j];
                    p[i, j] = 0;
                }
            for(k=0;k<n;k++)
                for(i=0;i<n;i++)
                    if(d[i,k]>0&&d[i,k]<int.MaxValue)
                        for(j=0;j<n;j++)
                            if(d[k,j]>0&&d[k,j]<int.MaxValue)
                                if(d[i,k]+d[k,j]<d[i,j])
                                {
                                    d[i, j] = d[i, k] + d[k, j];
                                    p[i, j] = k;
                                }
           
        }
       public static void FindBestRoad(int[,]d,int u,int v)
        {
            int i = d[u, v];
            if (i == 0) Console.Write("{0} ", u);
            else
            {
                FindBestRoad(d, i, v);
                FindBestRoad(d, u, i);
            }


        }
        public static void Result(int[,]d,int u,int v)
        {
            if (d[u, v] == 0) Console.Write("Duong di khong ton tai");
            else
            {
                Console.Write("{0}  ", v);
                FindBestRoad(d, u, v);
            }
        }
       
     
           
        static void Main(string[] args)
        {
            int[,] a =  { {0,5,int.MaxValue,int.MaxValue },
                          {50,0,15,5 },
                          {30,int.MaxValue,0,15 },
                          {15,int.MaxValue,5,0 }
                         };
            int[,] p = new int[4, 4];
            int[,] d = new int[4, 4];
            int n = 4;

            Floyd(d, p, a, n);
            Result(p, 0,3);
           
            Console.ReadKey();
        }
    }
}
