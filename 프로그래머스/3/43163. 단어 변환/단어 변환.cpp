#include <string>
#include <vector>
#include <queue>

using namespace std;

bool countStr(string begin, string word)
{
    int cnt = 0;
    for(int i = 0; i < begin.size(); i++)
        if (begin[i] != word[i])
            cnt++;
    return cnt == 1 ? true : false;
}

int findStr(string begin, vector<string>& words,vector<int>& visit)
{
    for(int i = 0; i < words.size(); i++)
    {
        if (visit[i] != 0)
            continue;
        
        if (true == countStr(begin, words[i]))
            return i;
    }
    return -1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool isFlag = true;
    for(auto& word : words)
    {
        if (target == word)
        {
            isFlag = false;
            break;
        }
    }
    if (isFlag)
        return answer;
    
    vector<int> visit(words.size(), 0);
    queue<int> q;

    int index = findStr(begin, words, visit);
    visit[index] = 1;
    q.push(index);
    
    while(false == q.empty())
    {
        int curr = q.front(); q.pop();
        if (words[curr] == target)
        {
            answer = visit[curr];
            break;
        }
        
        while(true)
        {
            int next = findStr(words[curr], words, visit);
            if (next == -1)
                break;
            
            visit[next] = visit[curr] + 1;
            q.push(next);
        }
    }
    
    return answer;
}