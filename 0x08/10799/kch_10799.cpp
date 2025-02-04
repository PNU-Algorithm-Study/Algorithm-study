#include <iostream>
#include <stack>
using namespace std;
stack<char> s;

int main() 
{
    string input;
    int result = 0;
    cin >> input;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '(') s.push(input[i]);
        else
        {
            if(input[i - 1] == '(') 
            {
                s.pop();
                result += s.size();
            }
            else 
            {
                s.pop();
                result++;
            }
        }
    }
    cout << result;
}
