//#include <iostream>
//#include <vector>
//#include <string>
//#include <math.h>
//#include <stack>
//using namespace std;
//
//int main()
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	string first, second;
//	stack<int> result;
//	bool IsAlpha = false;
//	int length = 0;
//
//	cin >> first >> second;
//
//	length = first.size() >= second.size() ? first.size() : second.size();
//
//	for (int i = 0; i < length; i++)
//	{
//		int first_number = 0, second_number = 0;
//		int add_number = 0;
//
//		if (first.size() > i) first_number = (int)first[first.size() - i - 1] - 48;
//		if (second.size() > i) second_number = (int)second[second.size() - i - 1] - 48;
//		add_number = (first_number + second_number) % 10;
//
//		if (IsAlpha == true)
//		{
//			result.push(add_number + 1);
//		}
//		else
//		{
//			result.push(add_number);
//		}
//
//
//		if (first_number + second_number >= 10) IsAlpha = true;
//		else IsAlpha = false;
//
//		if (i == length - 1 && IsAlpha == true) result.push(1);
//	}
//
//	while (result.empty() == false)
//	{
//		cout << (char)(result.top() + 48);
//		result.pop();
//	}
//
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n1, n2, res, ans; // ���� ũ�� ������, ���ڿ��� �Է¹���
    cin >> n1 >> n2;
    int car = 0;  // �ø���
    int onesize = n1.size();  // ù��° ���� �ڸ���
    int twosize = n2.size();  // �ι�° ���� �ڸ���
    while (onesize > 0 || twosize > 0)
    {
        int nn1 = 0;  // ù��° ���� �ڸ��� �� �ϳ�(���� �ڸ����� ����)
        if (onesize > 0)
        {
            nn1 = n1[--onesize] - '0';  // ���� 0 �� ���ָ� �Լ��� ���� �ʰ� ���ڸ� ���ڷ� �ٲٱ� ����
        }
        int nn2 = 0;
        if (twosize > 0)
        {
            nn2 = n2[--twosize] - '0';
        }
        int cur = nn1 + nn2 + car;
        car = cur / 10; // �ø��� ����
        cur %= 10;
        char ccar = cur + '0';  // ���ڷ� ��ȯ
        res += ccar;
    }
    if (car > 0) // �ø����� ���������� �����ִٸ�
    {
        res += car + '0';
    }
    for (int i = res.length() - 1; i >= 0; i--)  // ���
    {
        cout << res[i];
    }
}