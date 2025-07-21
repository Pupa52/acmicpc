#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i = 0; i <= t.size() - p.size(); i++)
    {
        bool isFlag = true;
        for(int j = 0; j < p.size(); j++)
        {
            if (t[i + j] != p[j])
            {
                isFlag = t[i + j] < p[j] ? true : false;
                break;
            }
            
        }
        if (isFlag)
            answer++;
    }

    return answer;
}