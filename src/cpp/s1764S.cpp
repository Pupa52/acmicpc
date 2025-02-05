#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n = 0, m = 0, cnt = 0;
    string tmp;
    unordered_map<string, int> person;
    vector<string> answer;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        person[tmp]++;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        if(person[tmp] == 1)
        {
            answer.push_back(tmp);
            cnt++;
        }
    }
    sort(answer.begin(), answer.end());
    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++)
    {
        cout << answer[i];
        if(i != cnt - 1)
            cout << "\n";
    }
    return 0;
}
