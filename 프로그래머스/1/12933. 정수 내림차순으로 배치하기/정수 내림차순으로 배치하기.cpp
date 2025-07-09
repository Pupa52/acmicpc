#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> v(10, 0);
    while(n != 0)
    {
        int index = n % 10;
        v[index]++;
        n /= 10;
    }
    
    for(int i = 9; i >= 0; i--)
    {
        for(int j = 0; j < v[i]; j++)
        {
            answer *= 10;
            answer += i;
        }
    }
    
    return answer;
}