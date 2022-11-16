#include <iostream>
#include <memory>

int main()
{
	using namespace std;
	//unique_ptr<int> upa = make_unique<int>(1);
	unique_ptr<int[]> upa(new int[10]{1,2,3,4,5,6,7,8,9,10});
	for(int i=0;i<10;i++) 
		cout << upa[i] << endl;

	return 0;
}