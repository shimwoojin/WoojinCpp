#include <iostream>

int main()
{
	int *p_arr[3];		//이거는 각각 원소 p_arr[0],p_arr[1],p_arr[2]가 int 자료형을 가리키는 각각의 포인터. ok?
	int(*p2_arr)[3];	//이거는 크기가 열의 크기가 3인 배열을 받는 포인터. 행의 크기는 자유
	//둘중에 뭐가 포인터배열이고 배열포인터인지는 잘모름 ㅋ
	//간단하게 용도부터 설명하면
	
	//1. int *p_arr[3]에 대해 사용할 때
	int a = 3, b = 2, c = 1;
	p_arr[0] = &a;
	p_arr[1] = &b;
	p_arr[2] = &c;

	//2. int(*p2_arr)[3]에 대해 사용할 때
	int p_arr3[5][3] = {};
	int p_arr4[15][3] = {};
	int p_arr5[25][3] = {};

	p2_arr = p_arr3;
	p2_arr = p_arr4;
	p2_arr = p_arr5;	//열의 크기가 3인 배열에 대해 사용하는 포인터
	//결론적으로 int(*p2_arr)[3]는 이중배열(열의 크기가 3인)을 담을 때 쓸 수 있는 포인터 형태

	return 0;
}