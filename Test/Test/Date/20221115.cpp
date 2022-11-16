#include <iostream>
using namespace std;

int main()
{
	/*
		1.
		int a = 123;


		a = 0;
		a = a ? a -> ?에 무슨 연산자가 들어가야  위 코드(a = 0;)보다 빠르게 될까?

		a = b'0000'0000'0000'0000'0000'0000'0111'1011;
		a = b'0000'0000'0000'0000'0000'0000'0111'1011;

		^   ============================================

		a = b'0000'0000'0000'0000'0000'0000'0000'0000;

		XOR 비트 연산자 (^) : 열에서 한개 비트만 1임ㄴ
	*/
	{
		int a = 123;
		a = a ^ a;
		cout << a << endl;
	}

	/*
		2.
		int a = 123;
		int b = 456;

		a = a ? b
		b = a ? b
		a = a ? b

		a = b'0000'0000'0000'0000'0000'0000'0111'1011;
		b = b'0000'0000'0000'0000'0000'0001'1100'1000;

		temp를 사용하지 않고 바꾸는법 찾기
	*/

	{
		int a = 123;
		int b = 456;
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;

		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}

	/*
		3.
		짝수/홀수 판별 -> %사용하지 않고
	*/

	{
		int a = 4;
		//if ((a << (sizeof(a) * 8 - 1)) == 0)
		//	cout << "짝수" << endl;
		//else
		//	cout << "홀수" << endl;
		if (a & 1) cout << "홀수" << endl;
		else cout << "짝수" << endl;
	}

	/*
		4.
		 음수/양수 판별 -> 관계연산자 사용 x
	*/
	{
		int a = 3;
		int b = 15;
		int c = -15;
		if ((c >> 31) == 0) cout << "양수" << endl;
		else cout << "음수" << endl;
	}

	/*
	    5.
		2의 승수인지 아닌지 판별 -> 반복문 사용하지 않고
		연산 두번만 하면 알 수 있음
	*/

	{
		int a = 128;	// a = b'1000'0000;
		int b = 127;
		if ((a & (a - 1)) == 0) cout << "a는 2의 승수입니다" << endl;
		if ((b & (b - 1)) == 0) cout << "b는 2의 승수입니다" << endl;
	}

	/*
		6.
	    대문자/소문자 변환 -> +, - 안쓰고
	    아스키 코드의 대문자는 여섯번째 비트가 모두 0이고
	    소문자는 모두 1 이다.
	*/

	{
		char a = 'a';
		char A = 'A';
		char b = 'b';
		char B = 'B';
		char test[4] = { a,A,b,B };
		for (int i = 0; i < 4; i++)
		{
			if ((test[i] & 32) == 0)
			{
				cout << "대문자" << endl;
				test[i] |= 32;
				cout << "변환 후 : " << test[i] << endl;
			}
			else
			{
				cout << "소문자" << endl;
				test[i] &= ~32;
				cout << "변환 후 : " << test[i] << endl;
			}
		}

	}

	return 0;
}