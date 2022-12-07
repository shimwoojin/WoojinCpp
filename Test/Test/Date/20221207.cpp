#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	vector<int> v_int;

	for (int i = 0; i < 10; i++)
	{
		v_int.push_back(i);
		cout << v_int[i] << endl;
		cout << "Capacity : " << v_int.capacity() << endl;
	}


	return 0;
}