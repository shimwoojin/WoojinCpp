#include <bits/stdc++.h>
using namespace std;

//int ten_n[10];
//
//int WordToNumber(string word, map<char, int>& alphabet_map)
//{
//	int number = 0;
//
//	for (int i = 0; i < word.size(); i++)
//	{
//		number += alphabet_map[word[i]] * ten_n[word.size() - 1 - i];
//	}
//
//	return number;
//}
//
//int main()
//{
//	//start : 14:36
//	//end : 15:32
//
//	for (int i = 0; i < 10; i++)
//	{
//		ten_n[i] = pow(10, i);
//	}
//
//	int answer = 0;
//	int n;
//	cin >> n;
//	vector<string> words(n);
//	set<char> alphabets;
//	map<char, int> alphabet_map;
//	vector<int> numbers;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> words[i];
//
//		for (int j = 0; j < words[i].size(); j++)
//		{
//			alphabets.insert(words[i][j]);
//			alphabet_map[words[i][j]] = 0;
//		}
//	}
//
//	for (int i = 10 - alphabets.size(); i < 10; i++)
//	{
//		numbers.push_back(i);
//	}
//
//	do 
//	{
//		int index = 0;
//		int temp = 0;
//
//		for (auto& ele : alphabet_map)
//		{
//			ele.second = numbers[index++];
//		}
//
//		for (auto& word : words)
//		{
//			temp += WordToNumber(word, alphabet_map);
//		}
//
//		answer = max(temp, answer);
//
//	} while (next_permutation(numbers.begin(), numbers.end()));
//
//	cout << answer;
//
//	return 0;
//}

int main()
{
	int answer = 0;
	int n;
	cin >> n;
	int alphabets[26] = {};

	while (n--)
	{
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			alphabets[str[i] - 'A'] += pow(10, str.size() - i - 1);
		}
	}

	sort(alphabets, alphabets + 26, greater<int>());

	int number = 9;

	for (int i = 0; i < 26; i++)
	{
		if (alphabets[i] == 0) break;
		answer += number * alphabets[i];
		number--;
	}

	cout << answer;

	return 0;
}