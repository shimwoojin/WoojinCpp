#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int TimeToInt(string time)
{
	int answer = 0;
	string minutes;
	string seconds;

	minutes += time[0];
	minutes += time[1];

	answer += stoi(minutes) * 60;

	seconds += time[3];
	seconds += time[4];

	answer += stoi(seconds);

	return answer;
}

string IntToTime(int n)
{
	string answer;
	string minutes;
	string seconds;

	int quotient = n / 60;
	int remainder = n % 60;

	minutes += to_string(quotient);
	seconds += to_string(remainder);

	if (minutes.size() < 2)
	{
		minutes.insert(minutes.begin(), '0');
	}
	else if (minutes.size() < 1)
	{
		minutes.insert(minutes.begin(), '0');
		minutes.insert(minutes.begin(), '0');
	}

	if (seconds.size() < 2)
	{
		seconds.insert(seconds.begin(), '0');
	}
	else if (seconds.size() < 1)
	{
		seconds.insert(seconds.begin(), '0');
		seconds.insert(seconds.begin(), '0');
	}

	answer += minutes;
	answer += ':';
	answer += seconds;

	return answer;
}

int main()
{
	//start : 17:40
	//end : 18:09

	int n;
	cin >> n;
	vector<string> goals(n);
	vector<pair<int, int>> p_goals;

	for (int i = 0; i < n; i++)
	{
		int team = 0;
		string s_time;
		int time = 0;

		cin >> team >> s_time;

		time = TimeToInt(s_time);
		p_goals.push_back(make_pair(time, team));
	}
	p_goals.push_back(make_pair(TimeToInt("48:00"), 0));

	map<int, int> score;
	int before_goal_time = 0;
	int team1_accum = 0;
	int team2_accum = 0;

	for (auto goal : p_goals)
	{
		int time = goal.first;
		int team = goal.second;
		int gap = time - before_goal_time;
		before_goal_time = time;

		if (score[1] > score[2])
		{
			team1_accum += gap;
		}
		else if (score[1] == score[2])
		{
			
		}
		else
		{
			team2_accum += gap;
		}

		score[team]++;
	}

	cout << IntToTime(team1_accum) << "\n";
	cout << IntToTime(team2_accum);

	return 0;
}