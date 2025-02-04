#include <iostream>
#include <stack>
using namespace std;
stack<int> s;

int main() 
{
    int n;
    long long result = 0;
    cin >> n;
    while(n--)
    {
        int input;
        cin >> input;
        if(s.empty())
        {
            s.push(input);
            continue;
        }
        while(!s.empty() && s.top() <= input) s.pop();
        result += s.size();
        s.push(input);
    }
    cout << result;
}
