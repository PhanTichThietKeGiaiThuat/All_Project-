using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTM_BaiToanMaDiTuan
{
    class Program
    {
        public static int[] a = new int[8];
        public static int[] b = new int[8];
        public static int[,] h = new int[8,8];
        public static int n = 8;
        public static void thu(int i,int x,int y){
            int k,u,v;
            for(k=0;k<=7;k++)
            {
                u = x + a[k];
                v = y + b[k];
                if(u>=1 && v<=n&&h[u,v]==0)
                {
                    h[u, v] = i;
                    if (i < n * n)
                        thu(i + 1, u, v);
                    else xuat(h);
                }h[u, v] = 0;

            }
        }
        public static void xuat(int[,]h)
        {
            int i, j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    Console.Write("{0} ", h[i, j]);
                }
            }
        }
        static void Main(string[] args)
        {
            thu(1, 2, 2);
            Console.ReadKey();
        }
    }
}
