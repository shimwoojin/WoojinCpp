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
		cout << "lamda �� ���� ���� �� OutValue1�� �� : " << OutValue1 << endl;
		OutValue1 -= lamdasum;
		//OutValue2 -= lamdasum;	//error -> lvalue�� �ƴ϶�� ��
		//OutValue3 -= lamdasum;	//error
		cout << "lamda �� ���� OutValue1�� �� : " << OutValue1 << endl;
		cout << "lamda �� ���� OutValue2�� �� : " << OutValue2 << "�� ���� �Ұ���" << endl;
		return OutValue1;
	}(2,5);
	
	cout << "lamda �� �ܺ� OutValue1�� �� : " << OutValue1 << endl;
	cout << "lamda�Ŀ��� return���� returnValue�� �� : " << returnValue << endl;



	return 0;
}