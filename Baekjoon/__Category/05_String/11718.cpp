#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    string str;
    while (true) {
        getline(cin, str);
        if (str == "")
            break;
        cout << str << endl;
    }

	return 0;
}