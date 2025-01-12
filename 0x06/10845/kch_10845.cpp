#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main(void)
{
    int num;
    cin >> num;
    cin.ignore(); 
    for(int i = 0; i < num; i++)
    {
        string str;
        getline(cin, str); 
        if(str.length() > 5) q.push(stoi(str.substr(5)));
        else if(str == "pop")
        {
            if(q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size") cout << q.size() << '\n';
        else if(str == "empty")
        {
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "front")
        {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else
        {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}