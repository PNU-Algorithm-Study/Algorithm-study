#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;

int main(void)
{
    int num;
    cin >> num;
    cin.ignore(); 
    for(int i = 0; i < num; i++)
    {
        string str;
        getline(cin, str); 
        if(str.substr(0, 10) == "push_front") dq.push_front(stoi(str.substr(11)));
        else if(str.substr(0, 9) == "push_back") dq.push_back(stoi(str.substr(10)));
        else if(str == "pop_front")
        {
            if(dq.empty()) cout << -1 << '\n';
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(str == "pop_back")
        {
            if(dq.empty()) cout << -1 << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(str == "size") cout << dq.size() << '\n';
        else if(str == "empty")
        {
            if(dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(str == "front")
        {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else
        {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
}