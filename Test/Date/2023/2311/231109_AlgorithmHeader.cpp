#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <map>

using namespace std;

//#define SET_01
//#define VECTOR_TO_SET_02
//#define ADJACENT_FIND_03
//#define ALL_OF_04
//#define ANY_OF_05
//#define BINARY_SEARCH_06
//#define CLAMP_07
//#define COPY_08
//#define COPY_BACKWARD_09
//#define COPY_IF_10
//#define COPY_N_11
//#define COUNT_12
//#define COUNT_IF_13
//#define FOR_EACH_14
//#define GENERATE_15
//#define INCLUDES_16
//#define INPLACE_MERGE_17
//#define MERGE_18
//#define MAX_ELEMENT_19
//#define MINMAX_20
#define REVERSE_21

int main()
{
	//1. 합집합, 교집합, 차집합
#ifdef SET_01
	set<int> s1{ 1,2,3,4 };
	set<int> s2{ 3,4,5,6 };
	set<int> s3;
	set<int> s4;
	set<int> s5;

	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));	//s3 -> 1,2,3,4,5,6,

	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s4, s4.begin()));	//s4 -> 3,4

	set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s5, s5.begin()));	//s5 -> 1,2
#endif

	//2. 벡터 -> Set 복사 없이 중복 없애기
#ifdef VECTOR_TO_SET_02
	vector<int> v{ 1,2,1,2,3,4,5 };
	sort(v.begin(), v.end());	//정렬 후
	auto iter = unique(v.begin(), v.end());	//unique 사용 시 중복 값들은 뒤로 밀어내고 중복의 시작 위치 반복자 리턴
	v.erase(iter, v.end());	//그 반복자로부터 끝까지 삭제
#endif

	//3. adjacent_find
#ifdef ADJACENT_FIND_03
	list<int> l{ 1,2,2,4,5 };
	list<int>::iterator iter = adjacent_find(l.begin(), l.end());	//2,2가 붙어있기 때문에 인접한 요소인 인덱스 1에 해당하는 2의 이터 반환
	cout << *iter << endl;
	list<int>::iterator iter2 = adjacent_find(l.begin(), l.end(), [](int a, int b) {
		return a * 2 == b;
		});	//좌측에 비해 우측 값이 2배 크다면 좌측 값에 해당하는 이터 반환
	cout << *iter2 << endl;
	iter2++;
	cout << *iter2 << endl;
#endif

	//4. all_of
#ifdef ALL_OF_04
	set<int> s{ 3,6,9,12 };
	bool result = all_of(s.begin(), s.end(), [](int ele) {
		return ele > 2;
		});	//모든 요소가 2는 넘음 -> 전부 true (각 요소마다 다 true 여야 result가 true)

	bool result2 = all_of(s.begin(), s.end(), [](int ele) {
		return ele > 4;
		});	//3은 4보다 작음 ->false
#endif

	//5. any_of
#ifdef ANY_OF_05
	vector<int> v{ 1,3,5,7,9 };
	bool result = any_of(v.begin(), v.end(), [](int ele) {
		return ele == 1;
		});	//1이 하나라도 있음 -> true 
	bool result2 = any_of(v.begin(), v.end(), [](int ele) {
		return ele > 10;
		});	//10을 넘는 요소가 하나도 없음 -> false
#endif

	//6. binary_search
#ifdef BINARY_SEARCH_06
	list<int> l{ 1,10,40,50,20 };
	l.sort();
	bool reuslt = binary_search(l.begin(), l.end(), 1);
	bool reuslt2 = binary_search(l.begin(), l.end(), 2);

	vector<int> v{ 1,30,50,20,40 };
	sort(v.begin(), v.end());
	bool reuslt3 = binary_search(v.begin(), v.end(), 1);
#endif

	//7. clamp
#ifdef CLAMP_07
	int a = 30;
	int b = 2;
	a = std::clamp(a, 5, 20);	//최소, 최대 사이 값을 지정 -> C++17부터 표준
	b = std::clamp(b, 5, 20);
#endif

	//8. copy
#ifdef COPY_08
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	list<int> l{ 1,5,3,2,1 };
	l.resize(15);
	auto iter = l.begin();
	advance(iter, 5);
	copy(v.begin(), v.end(), iter);
#endif

	//9. copy_backward
#ifdef COPY_BACKWARD_09
	vector<int> v1{ 1,2,3,4,5,6 };
	vector<int> v2{ 11,12,13,14,15,16 };
	copy_backward(v1.begin(), v1.begin() + 2, v2.begin() + 2);	//v2 -> 1,2,13,14,15,16
#endif

	//10. copy_if
#ifdef COPY_IF_10
	vector<int> v1{ 1,2,3,4,5,6 };
	vector<int> v2{ 11,12,13,14,15,16 };
	int v3[20];
	auto is_over3 = [](int ele) { return ele > 3; };
	copy_if(v1.begin(), v1.end(), v2.begin(), is_over3);	//v2 -> 4,5,6,14,15,16
	copy_if(v1.begin(), v1.end(), v3, is_over3);	//v3 -> 4,5,6,...쓰레기값
#endif

	//11. copy_n
#ifdef COPY_N_11
	vector<int> v1{ 1,2,3,4,5,6 };
	vector<int> v2{ 11,12,13,14,15,16 };
	int v3[10]{ 3,4,5,1,2,3 };
	copy_n(v1.begin(), 3, v2.begin());	//v2 -> 1,2,3,14,15,16
	copy_n(v3, 3, v2.begin());	//v2 -> 3,4,5,14,15,16
#endif

	//12. count
#ifdef COUNT_12
	vector<int> v1{ 1,2,3,4,5,6,1,1 };
	vector<int> v2{ 11,12,13,14,15,16 };
	map<int, int> m1{ {1,2}, {2,3}, {3,4} };
	set<int> s1{ 1,2,2,1 };
	int v3[10]{ 3,4,5,1,2,3 };

	int c = count(v1.begin(), v1.end(), 1);		//3
	int c2 = count(s1.begin(), s1.end(), 1);	// 1

#endif

	//13. count_if
#ifdef COUNT_IF_13
	vector<int> v1{ 1,2,3,4,5,6,1,1 };
	vector<int> v2{ 11,12,13,14,15,16 };
	map<int, int> m1{ {1,2}, {2,3}, {3,4} };
	set<int> s1{ 1,2,2,1,5,4 };
	int v3[10]{ 3,4,5,1,2,3 };

	auto is_over3 = [](int ele) { return ele > 3; };

	int c = count_if(v1.begin(), v1.end(), is_over3);		//3
	int c2 = count_if(s1.begin(), s1.end(), is_over3);	// 1

#endif

	//14. for_each
#ifdef FOR_EACH_14
	vector<int> v1{ 1,2,3,4,5,6,1,1 };
	
	auto show = [](int ele) {cout << ele << " "; };
	for_each(v1.begin(), v1.end(), show);
	cout << endl;
	for_each_n(v1.begin(), 3, show);
#endif

	//15. generate
#ifdef GENERATE_15
	vector<int> v1{ 1,2,3,4,5,6,1,1 };
	generate(v1.begin(), v1.end(), rand);
#endif

	//16. includes
#ifdef INCLUDES_16
	vector<int> v1{ 3,4,5 };
	vector<int> v2{ 1,2,3,4,5,6 };
	bool result = includes(v2.begin(), v2.end(), v1.begin(), v1.end());
#endif

	//17. inplace_merge
#ifdef INPLACE_MERGE_17
	vector<int> v1{ 1,3,5,8,10,11,13,2,5,8,10,14 };
	inplace_merge(v1.begin(), v1.begin() + 7, v1.end());	//정렬 / 정렬 의 중간값을 넘겨야 함 ?
#endif

	//18. merge
#ifdef MERGE_18
	vector<int> v1{ 1,3,5,8,10,11,13,2,5,8,10,14 };
	vector<int> v2{ 5,2,1,4,7 };

	v1.insert(v1.end(), v2.begin(), v2.end());
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<int> v3(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
#endif

	//19. max_element
#ifdef MAX_ELEMENT_19
	vector<int> v1{ 1,6,4,3,1,200,3,120,1240 };
	vector<int>::iterator iter = max_element(v1.begin(), v1.end());
	*iter;
#endif

	//20. minmax
#ifdef MINMAX_20
	pair<int, int> mm = minmax(5, 3);
#endif

	//21. reverse
#ifdef REVERSE_21
	vector<int> v1{ 4,6,8,5,3,1,8 };
	reverse(v1.begin(), v1.end());
#endif

	return 0;
}