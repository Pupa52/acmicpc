#include <string>
#include <vector>
#include <array>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    array<int, 5> first = { 1, 2, 3, 4, 5 };
    array<int, 8> second = { 2, 1, 2, 3, 2, 4, 2, 5 };
    array<int, 10> third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int score[3] = {};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if (first[i % 5] == answers[i])
            score[0]++;
        
        if (second[i % 8] == answers[i])
            score[1]++;
        
        if (third[i % 10] == answers[i])
            score[2]++;
    }
    
    int maxValue = 0;
    for(int i = 0; i < 3; i++)
        maxValue = max(score[i], maxValue);
    
    for(int i = 0; i < 3; i++)
        if (maxValue == score[i])
            answer.push_back(i + 1);
    
    return answer;
}