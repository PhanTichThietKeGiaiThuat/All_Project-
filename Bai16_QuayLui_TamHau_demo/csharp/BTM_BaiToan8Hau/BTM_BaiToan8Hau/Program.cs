using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace BTM_BaiToan8Hau
{
    class Program
    {
        public static int[] x = new int[9];
        public static int[] a = new int[9];
        public static int[] b = new int[100];
        public static int[] c = new int[100];

        public static int init()
        {
            int i;
            for(i=0;i<8;i++)
            {
                x[i] = 0;
                a[i] = 1;
            }
            for(i=0;i<15;i++)
            {
                b[i] = 1;
                c[i] = 1;
            }
            return 0;
        }
        public static int print()
        {
            int i;
            for(i=0;i<8;i++)
            {
                Console.Write("{0} ",x[i]);
            }
            Console.WriteLine();
            return 0;
        }
        public static void thu(int i)
        {
            int j;
            for(j=0;j<8;j++)
            {
                if(a[j]==1 && b[i+j-1]==1&&c[i-j+8]==1)
                {
                    x[i] = j;
                    a[j] = 0;
                    b[i + j - 1] = 0;
                    c[i - j + 8] = 0;
                    if (i < 8)
                        thu(i + 1);
                    else print();
                    a[j] = 1;
                    b[i + j - 1] = 1;
                    c[i - j + 8] = 1;
                }
            }
        }
        static void Main(string[] args)
        {
            init();
            thu(1);
            Console.ReadKey();
        }
    }
}
