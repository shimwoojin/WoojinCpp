#include <iostream>
#include <crtdbg.h>		// _CrtDumpMemoryLeaks() ����ϱ� ����
#if _DEBUG		//DEBUG�� 
#define new new(_NORMAL_BLOCK, __FILE__,__LINE__)	
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif	// ���࿡�� �޸� ���� ������ �˷���

int main()
{
	int* a = new int[5];
	_CrtDumpMemoryLeaks();

	return 0;
}
