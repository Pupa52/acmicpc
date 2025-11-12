#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](vector<int>& lhs, vector<int>& rhs){
        return lhs[1] < rhs[1];
    });
    
    int en = -30001;
    for(auto& route : routes)
    {
        if (en < route[0])
        {
            answer++;
            en = route[1];
        }
    }
    
    return answer;
}