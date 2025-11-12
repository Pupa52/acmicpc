#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](vector<int>& lhs, vector<int>& rhs){
        return lhs[0] < rhs[0];
    });
    
    int st = -30001, en = -30001;
    for(auto& route : routes)
    {
        if (en < route[0])
        {
            answer++;
            st = route[0];
            en = route[1];
        }
        
        else
        {
            st = route[0];
            en = min(en, route[1]);
        }
    }
    
    return answer;
}