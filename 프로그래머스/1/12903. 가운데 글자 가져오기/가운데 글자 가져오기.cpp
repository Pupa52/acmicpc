#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = s.size() / 2;
    if (s.size() % 2 != 0)
    {
        answer.push_back(s[index]);
    }
    
    else
    {
        answer = s.substr(index - 1, 2);
    }
    
    return answer;
}