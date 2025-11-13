#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> visit(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        if (visit[i] != 0)
            continue;
        
        answer++;
        
        queue<int> q;
        q.push(i);
        visit[i] = 1;
        
        while(false == q.empty())
        {
            int cur = q.front(); q.pop();
            
            for(int j = 0; j < n; j++)
            {
                if (computers[cur][j] == 1 && visit[j] == 0)
                {
                    q.push(j);
                    visit[j] = 1;
                }
            }
        }
    }
    
    return answer;
}