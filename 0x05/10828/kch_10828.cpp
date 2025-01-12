#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int main(void)
{
    int num;
    cin >> num;
    cin.ignore(); 
    for(int i = 0; i < num; i++)
    {
        string str;
        getline(cin, str); 
        if(str.length() > 5) st.push(stoi(str.substr(5)));
        else if(str == "pop")
        {
            if(st.empty()) cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(str == "size") cout << st.size() << '\n';
        else if(str == "empty")
        {
            if(st.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else
        {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }
}