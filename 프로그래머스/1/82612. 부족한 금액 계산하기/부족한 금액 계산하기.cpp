#include <cmath>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    for(int i = 1; i <= count; i++)
    {
        answer += price * i;
    }
    
    answer = money - answer;
    
    return answer > 0 ? 0 : answer * -1;
}