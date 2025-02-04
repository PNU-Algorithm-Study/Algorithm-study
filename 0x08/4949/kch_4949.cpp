#include <iostream>
#include <stack>
using namespace std;

int main()
{
    while(1)
    {
        stack<char> s;
        string input;
        bool err = false;
        getline(cin, input);
        if(input == ".") break;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '(' || input[i] == '[') s.push(input[i]);
            else if(input[i] == ')')
            {
                if(!s.empty() && s.top() == '(') s.pop();
                else
                {
                    err = true;
                    break;
                }
            }
            else if(input[i] == ']')
            {
                if(!s.empty() && s.top() == '[') s.pop();
                else
                {
                    err = true;
                    break;
                }
            }
        }
        if(err == false && s.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
