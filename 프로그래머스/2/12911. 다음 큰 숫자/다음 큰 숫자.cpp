#include <string>
#include <vector>

using namespace std;

int countOne(int n)
{
    int result = 0;
    while(n != 0)
    {
        result += n % 2;
        n /= 2;
    }
    return result;
}

int solution(int n) {
    int answer = n + 1;
    
    while(true)
    {
        if (countOne(n) == countOne(answer))
            break;
        answer++;
    }
    
    return answer;
}