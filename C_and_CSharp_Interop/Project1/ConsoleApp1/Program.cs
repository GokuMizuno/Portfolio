//Gordon Stangler
//This is a lame example of a C# program that takes a custom built DLL
//and does something trivial with the data.

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
            int r1 = ReturnHiorLo();
            int r2 = ReturnHiorLo();

            Console.WriteLine("{0}", r1);

            if (r1 == r2)
                Console.WriteLine("Both numbers are the same!");
        }
    }
}
