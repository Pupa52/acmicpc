#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cnt = 0;
    for(auto chr : s)
    {
        if (tolower(chr) == 'p')
            cnt++;
        else if (tolower(chr) == 'y')
            cnt--;
    }
    
    answer = cnt == 0 ? true : false;
    
    return answer;
}