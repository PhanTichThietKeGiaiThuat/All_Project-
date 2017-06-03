using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NC_BaiToanCaiTui
{
    class Program
    {
        public static int m=8,s=0,n=4,gttu=0;
        public static int tl = 0;
        public static int[] w = new int[] {5,3,2,4};
        public static int[] x = new int[n];
        public static int[] v = new int[] { 10,5,3,6};
        public static int[] patu = new int[n];
        public static void TRYTO(int i)
        {
            int j, t, g;
            t = (int)((m - tl) / w[i]);
            for(j=t;j>=0;j--)
            {
                x[i] = j;
                tl = tl + w[i] * x[i];//trong luong thu duoc
                s = s + v[i] * x[i];//gia tri thu duoc
                if(i==n)//cap nhap toi uu
                {
                    if(s>gttu)
                    {
                        gttu = s;

                    }
                }
                else
                {
                    g = s + v[i + 1] * (m - tl) / w[i + 1];//danh gia can
                    if (g > gttu) TRYTO(i + 1);

                }
                tl = tl - w[i] * x[i];
                s = s - v[i] * x[i];
            }
        }
        public static void init()
        {
            int i = 0;
            for(i=0;i<n;i++)
            {
                patu[i] = 0;
                x[i] = 0;
            }
            s = 0;
            gttu = 0;
            tl = 0;
        }
        static void Main(string[] args)
        {
            
             init();
            TRYTO(0);
            int i = 0;
            for (i = 0; i < 4; i++)
            {
                // Console.Write("{0},{1},{2}",i,w[i],v[i]);
                Console.Write("{0}", x[i]);
             }
            Console.ReadKey();
        }
    }
}
