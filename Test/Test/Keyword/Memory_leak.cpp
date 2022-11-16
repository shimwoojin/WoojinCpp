#include <iostream>
#include <crtdbg.h>		// _CrtDumpMemoryLeaks() 사용하기 위해
#if _DEBUG		//DEBUG시 
#define new new(_NORMAL_BLOCK, __FILE__,__LINE__)	
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif	// 몇행에서 메모리 누수 나는지 알려줌

int main()
{
	int* a = new int[5];
	_CrtDumpMemoryLeaks();

	return 0;
}
