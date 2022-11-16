// string 사용해보기

#include <iostream>
#include <string>

int main()
{
	using std::string; using std::cout; using std::endl;

	/*
		string 클래스의 특징
		- 문자의 끝에 null문자 포함 x
		- 배열처럼 다룰 수 있음
		- 문자열 합치는 것이 + 연산자로 가능(연산자 오버로딩)
		- 문자열 사전순 정리에도 간편
		- 다양한 멤버 함수 존재
	*/
	
	string str1 = "Hello world!";
	string str2 = "C++";

	/*
		string의 인덱스 접근
		- 배열처럼 접근 : 반환되는 문자는 char형
		- .at(index) : 반환되는 문자는 char형
	*/

	cout << "배열처럼 접근 : " << str1[0] << endl;
	cout << ".at 함수 사용 : " << str1.at(0) << endl;

	/*
		문자열의 맨 앞과 맨 끝 문자 반환
		- str.front() : 맨 앞 문자 반환
		- str.back() :  맨 끝 문자 반환
	*/
	
	cout << "str1.front() : " << str1.front() << endl;
	cout << "str1.back() : " << str1.back() << endl;
	cout << "str2.back() : " << str2.back() << endl;
	cout << "str2.back() : " << str2.back() << endl;

	/*
		문자열의 길이 반환
		- str.size()
		- str.length()
	*/
	
	cout << "str1.size() : " << str1.size() << endl;
	cout << "str2.length() : " << str2.length() << endl;
	
	/*
		숫자 -> 문자열, 문자열 -> 숫자
		- to_string() : 숫자 -> 문자열
		- stoi, stod, stof, stof : 문자열 -> 숫자 (int, double, float, long int)
	*/

	// 숫자 -> 문자열

	int a = 10;
	string str3;
	str3 = std::to_string(a);

	cout << "숫자를 문자로 : " << str3 << endl;
	cout << "숫자를 문자로 : " << std::to_string(a) << endl;

	// 문자열 -> 숫자

	string str_i = "11";
	string str_d = "12.3456";
	string str_f = "12.3456";
	string str_li = "2300000000";

	int after_i = std::stoi(str_i);
	int after_d = std::stod(str_d);
	int after_f = std::stof(str_f);
	int after_li = std::stof(str_li);

	// cout 모드 설정하여 double, float, long int 등 출력 가능
	cout << after_i << " " << after_d << " " << after_f << " " << after_li << endl;

	/*
		문자열의 capacity
		capacity란 이 객체에 할당된 메모리 bytes 크기로 객체에 들어올 문자열 크기에 대비하여
		넉넉하게 알아서 잡힘
		- str.capacity() : capacity 값 확인 (byte크기)
		- str.reserve(n) : 문자열 객체에 미리 n bytes 크기 할당
	*/

	cout << "str1.capacity() : " << str1.capacity() << endl;
	str1.reserve(50);
	cout << "str1.capacity() : " << str1.capacity() << endl;
	//cout << "str1의 50번째 인덱스 : " << str1[50] << endl;
	//error!

	/*
		그 외 유용한 함수들
		- str.empty() : size 혹은 length값이 0인지 아닌지 확인
		- swap(str1,str2) : swap
		- str.clear() : 문자열 제거, capacity값은 유지
		- str.append(str2) : +연산자랑 같은 기능
		- str.find(str2) : str에서 문자열 str2를 찾고 시작점 인덱스 반환
		- str.substr() : 문자의 일부분 반환 (반환형 string)
		- str.replace(idx,len,str2) : 문자열의 특정 인덱스부터 일정 길이만큼 str2로 변경
	*/

	cout << "str1.empty() : " << str1.empty() << endl;
	swap(str1, str2);
	cout << "str2와 swap 후 str1 : " << str1 << endl;
	cout << "swap 후 str1의 length : " << str1.length() << endl;
	cout << "swap 후 str2의 size : " << str2.size() << endl;
	cout << "swap 후 str1의 capacity : " << str1.capacity() << endl;
	cout << "swap 후 str2의 capacity : " << str2.capacity() << endl;
	str1.clear();
	cout << "str1.clear() 후 empty인지 : " << str1.empty() << endl;
	cout << "str1.clear() 후 capacity : " << str1.capacity() << endl;
	cout << "str_i, str_d에 append 사용 : " << str_i.append(str_d) << endl;
	cout << "str_i, str_d에 +연산자 적용 : " << str_i+str_d << endl;
	// 아마 lvalue와 rvalue의 차이인듯 ?
	cout << "str_i, str_d에 +연산자 한 번더 적용 : " << str_i+str_d << endl;
	cout << "str2.find(\"world\") : " << str2.find("world") << endl;	//str2 현재 상태 : Hello world!
	cout << "str2.substr(3, 5)  : " << str2.substr(3, 5) << endl;	//3번째 인덱스부터 5길이 만큼
	cout << "str2.substr(0, str2.size()) : " << str2.substr(0, str2.size()) << endl;	//처음부터 끝까지
	str2.replace(str2.begin() + 1, str2.end() - 2, "TEST");
	cout << "str2.replace(str2.begin() + 1, str2.end() - 2, \"TEST\") : " << str2 << endl;
	return 0;
}