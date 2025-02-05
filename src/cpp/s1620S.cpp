#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0, m = 0;
    string tmp = "";
    
    vector<string> answer;
    unordered_map<string, string> arr;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        arr[tmp] = to_string(i);
        arr[to_string(i)] = tmp;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        answer.push_back(arr[tmp]);
    }
    for(int i = 0; i < m; i++)
    {
        cout << answer[i];
        if(i != m - 1)
               cout << "\n";
    }
    return 0;
}
