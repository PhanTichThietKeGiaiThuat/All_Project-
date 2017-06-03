using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NC_NguoiDuLich
{
  
class Program
    {
        public static int n = 5, S = 0;
        public static int[] x = new int[10];
        public static int[,] C = new int[5, 5];

        public static int tong = 0, gttu = 0, httu = 0, Cmin = int.MaxValue;

        public static int[] Daxet = new int[10];
        public static void TRYTO(int i)
        {
            int j, tong, g;
            for (j = 2; j <= n; j++)
                if (Daxet[j] == 0)
                {
                    x[i] = j;
                    Daxet[j] = 1;
                    S = S + C[x[i - 1], x[i]];
                    if (i == n)
                    {
                        tong = S + C[x[n], x[1]];
                        if (tong < gttu)
                        {
                            gttu = tong;
                        }
                    }
                    else
                    {
                        g = S + (n - i + 1) * Cmin;
                        if (g < gttu) TRYTO(i + 1);
                    }
                    S = S - C[x[i - 1], x[i]];
                    Daxet[j] = 0;

                }
        }
        public static void init()
        {
            int i, j;
            for (i = 0; i < n; i++)
            {
                Daxet[i] = 0;

            }
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    C[i, j] = int.Parse(Console.ReadLine());
                }
            }
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    if (Cmin > C[i, j])
                        Cmin = C[i, j];
            gttu = int.MaxValue;
            S = 0;
            x[i] = 1;

        }


  


        static void Main(string[] args)
        {
            init();
            TRYTO(1);
            Console.ReadKey();


        }
    }
}
