using System;
using System.Runtime.InteropServices;

namespace ConsoleApp1
{
    class Program
    {
        [DllImport("C_dll_and_CSharp.dll", EntryPoint = "ReturnHiorLo")]
        public static extern int  ReturnHiorLo();

        static void Main(string[] args)
        {
            //Yeah, add more stuff here.  Actually do something with the info from the dll.
            int r = ReturnHiorLo();
            Console.WriteLine("{0}", r);
        }
    }
}
