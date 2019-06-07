#include <cstdlib>

extern "C"
{
	//Use __declspec(dllexport) to mark export as public
	__declspec(dllexport) int ReturnHiorLo()
	{
		int r = rand()&1;
		return r;
	}
}
