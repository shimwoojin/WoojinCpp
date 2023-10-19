#include<iostream>


int main()
{
	using namespace std;

	int OutValue1 = 10;
	int OutValue2 = 20;
	int OutValue3 = 30;

	auto returnValue = [=,&OutValue1](int lamdaValue1, int lamdaValue2) 
	{
		int lamdasum = lamdaValue1 + lamdaValue2;
		cout << "lamda 식 내부 변경 전 OutValue1의 값 : " << OutValue1 << endl;
		OutValue1 -= lamdasum;
		//OutValue2 -= lamdasum;	//error -> lvalue가 아니라고 함
		//OutValue3 -= lamdasum;	//error
		cout << "lamda 식 내부 OutValue1의 값 : " << OutValue1 << endl;
		cout << "lamda 식 내부 OutValue2의 값 : " << OutValue2 << "은 수정 불가능" << endl;
		return OutValue1;
	}(2,5);
	
	cout << "lamda 식 외부 OutValue1의 값 : " << OutValue1 << endl;
	cout << "lamda식에서 return받은 returnValue의 값 : " << returnValue << endl;



	return 0;
}