#include <cstdlib>

extern "C"
{
	//Use __declspec(dllexport) to mark export as public
	//using MS notation because that's what this computer has on it
	//using MS asm notation, so I'm stuck until I can get back to my Linux box

	__declspec(dllexport) int ReturnHiorLo()
	{
		int r = rand()&1;
		return r;
	}

	__declspec(dllexport) int Return4by4Array()
	{
		static int i = 0, SIZE = 4;
		//int arr[SIZE][SIZE];  //not allowed by c99 standards.  FIX LATER
		//using calloc, as we do not want garbage data.
		int arr[4][4];// = (int*)calloc((SIZE*SIZE), sizeof(int));
		int i = 0;
		for (i = 0; i < SIZE; i++)
		{
			//all arr[i][0]
			asm("movl $10 %eax;"
			"movl $20 %ebx;"
				"addl $ebx %eax;"
				"movl %eax arr[i][0];"
				);
			//all arr[i][1]
			asm("movl $20 %eax;"
				"movl $10 %ebx;"
				"subl %ebx %eax;"
				//FINISH ALL THIS
			);
			//all arr[i][2]

			//all arr[i][3]
		}
	}
}
