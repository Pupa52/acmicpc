#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> visit(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    
    visit[0][0] = 1;
    q.push(make_pair(0, 0));
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    while(false == q.empty())
    {
        auto front = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int x = front.first + dx[i];
            int y = front.second + dy[i];
            
            if ((x < 0 || m <= x) || (y < 0 || n <= y))
                continue;
            
            if (maps[y][x] == 0 || visit[y][x] != -1)
                continue;
            
            visit[y][x] = visit[front.second][front.first] + 1;
            q.push(make_pair(x, y));
        }
    }
    
    answer = visit[n - 1][m - 1];
    
    return answer;
}