#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<int> result(triangle.size(), 0);
    result[0] = triangle[0][0];
    
    for(int i = 0; i < triangle.size() - 1; i++)
    {
        for(int j = triangle[i].size() - 1; j >= 0; j--)
        {
            if (result[j + 1] < result[j] + triangle[i + 1][j + 1])
                result[j + 1] = result[j] + triangle[i + 1][j + 1];
            
            if (result[j] < result[j] + triangle[i + 1][j])
                result[j] = result[j] + triangle[i + 1][j];
        }
    }
    
    for(auto iter : result)
        answer = max(iter, answer);
    
    return answer;
}