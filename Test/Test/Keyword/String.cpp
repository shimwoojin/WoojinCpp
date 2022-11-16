#include <iostream>
//#include <cstring>
#include <string>

int main()
{
	using namespace std;
	char name1[40] = "shimwoojin";
	std::string name2 = "shimwoojin2";

	//sizeof와 strlen의 차이 : 배열 전체의 크기(capacity)는 sizeof, 문자열만의 크기(원소)는 strlen
	cout << sizeof(name1) << endl;
	cout << strlen(name1) << endl;

	cout << name2.size() << endl;

	//c스타일 문자열과 string 객체간의 문자열 작업
	strcpy_s(name1, name2.c_str());
	strcat_s(name1, name2.c_str());
	cout << name1 << endl;
	cout << name2 << endl;

	//cin.get과 cin.getline 차이 테스트 : get은 마지막 문자 남겨둠, getline은 마지막 문자(개행문자 혹은 제3의 매개변수) 없앰
	//getline도 개행문자까진 없애도 그 다음 버퍼까지 clear하지는 않음 ( cin.clear 해야 함)
	char arrtest[20] = {};

	cin.get(arrtest,20).get();
	cout << arrtest << endl;

	char arrtest2[20] = {};

	cout << "문자열에 #이 있으면 거기서 끊김" << endl;
	cin.getline(arrtest2,20,'#');
	cout << arrtest2 << endl;
	//cin.clear();
	//cin.ignore(10);
	//fflush(stdin);

	cin >> name1;
	cout << name1 << endl;

	return 0;
}