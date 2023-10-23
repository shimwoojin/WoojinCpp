#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    multiset<char> MS_Skill;

    for (int i = 0; i < skill.size(); i++)
    {
        MS_Skill.insert(skill[i]);
    }

    for (int i = 0; i < skill_trees.size(); i++)
    {
        multiset<char> MS_SkillCopy = MS_Skill;
        int SkillIndex = 0;
        bool GoodCharacter = true;

        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            if (skill[SkillIndex] == skill_trees[i][j])
            {
                MS_SkillCopy.erase(skill[SkillIndex++]);
            }
            else if (MS_SkillCopy.find(skill_trees[i][j]) != MS_SkillCopy.end())
            {
                GoodCharacter = false;
                break;
            }
        }

        if (GoodCharacter)
        {
            ++answer;
        }
    }

    return answer;
}