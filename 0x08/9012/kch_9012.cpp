#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void)
{
	int n;
    cin >> n;
    while(n--)
    {
        stack<char> s;
        string input;
        bool err = false;
        cin >> input;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '(') s.push(input[i]);
            else
            {
                if(!s.empty() && s.top() == '(') s.pop();
                else
                {
                    err = true;
                    break;
                }
            }
        }
        if(s.empty() && err == false) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
