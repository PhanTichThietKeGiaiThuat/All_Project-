using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QHD_DayConTongMax
{
    class Program
    {
        public static void SubMax(int[] a,int n,int s=1,int e=1)
        {
           int MaxS = a[1];
           int MaxE = a[1];
            int s1 = 1;
            for(int i=2;i<n;i++)
            {
                if (MaxE > 0) MaxE = MaxE + a[i];
                else { MaxE = a[i];s1 = i; }
                if(MaxE>MaxS)
                {
                    MaxS = MaxE;
                    e = i;
                    s = s1;
                }
            }
            for (int i = s; i <= e; i++)
            {
                Console.Write("{0} ", a[i]);

            }
        }
        //s chi so dau,e-chi so cuoi,s1-chi so dau tam
        public static void Input(int[]a,int n)
        {
            for(int i=0;i<n;i++)
            {
                Console.Write("a[{0}]=", i);
                a[i] = int.Parse(Console.ReadLine());
            }

        }
        
        static void Main(string[] args)
        {
            int[] a = new int[20];
            int n = 10;
            
            Input(a, n);
            Console.WriteLine();
            SubMax(a, n, 1, 1);
            Console.ReadKey();

        }
    }
}
