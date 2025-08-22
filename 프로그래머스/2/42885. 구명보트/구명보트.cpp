#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int front = 0, back = people.size() - 1;
    
    while(front <= back)
    {
        int sum = people[front] + people[back];
        if (sum <= limit)
            front++;
        
        back--;
        answer++;
    }
    
    return answer;
}