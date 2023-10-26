#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int TimeAsMinute(string word)
{
    int Minute = 0;
    Minute += (word[0] - 48) * 600;
    Minute += (word[1] - 48) * 60;
    Minute += (word[3] - 48) * 10;
    Minute += (word[4] - 48);

    return Minute;
}

int CalculateFee(const vector<int>& fees, int UseTime)
{
    int Fee = fees[1];

    if (UseTime <= fees[0])
    {
        return Fee;
    }
    else
    {
        int OverTime = UseTime -= fees[0];
        int MulNum = OverTime / fees[2];
        if (OverTime % fees[2] != 0)
        {
            ++MulNum;
        }
        Fee += MulNum * fees[3];
    }

    return Fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    //fees : 기본 시간 180, 기본 요금 5000, 단위 시간 10, 단위 요금 600
    //records : "05:34 5961 IN"

    map<string, int> InOutTime;
    map<string, int> AccumulatedTime;
    set<string> AllCarNumbers;
    int MaxTime = TimeAsMinute("23:59");

    for (int i = 0; i < records.size(); i++)
    {
        int Minute = TimeAsMinute(records[i]);
        string CarNumber = records[i].substr(6, 4);

        if (AllCarNumbers.find(CarNumber) == AllCarNumbers.end())
        {
            AllCarNumbers.insert(CarNumber);
        }

        if (records[i][11] == 'I')
        {
            InOutTime[CarNumber] = Minute;
        }
        else
        {
            int Gap = Minute - InOutTime[CarNumber];
            InOutTime.erase(CarNumber);

            if (AccumulatedTime.find(CarNumber) != AccumulatedTime.end())
            {
                AccumulatedTime[CarNumber] += Gap;
            }
            else
            {
                AccumulatedTime[CarNumber] = Gap;
            }
        }
    }

    for (auto NotOut : AllCarNumbers)
    {
        if (InOutTime.find(NotOut) != InOutTime.end())
        {
            int Gap = MaxTime - InOutTime[NotOut];

            if (AccumulatedTime.find(NotOut) != AccumulatedTime.end())
            {
                AccumulatedTime[NotOut] += Gap;
            }
            else
            {
                AccumulatedTime[NotOut] = Gap;
            }
        }
    }

    for (auto Seq : AllCarNumbers)
    {
        int UseTime = AccumulatedTime[Seq];
        int Fee = CalculateFee(fees, UseTime);
        answer.push_back(Fee);
    }

    return answer;
}