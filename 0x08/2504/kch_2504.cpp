#include<iostream>
#include<stack>
using namespace std;
stack<char> s;

int main()
{
	string input;
	int result = 0, tmp = 1;
	cin >> input;
	for(int i = 0; i < input.size(); i++)
	{
		char c = input[i];
		if(c == '(') 
		{
			s.push(c);
			tmp *= 2;
		}
		else if(c == '[') 
		{
			s.push(c);
			tmp *= 3;
		}
		else if(c == ')')
		{
			if(s.empty() || s.top() != '(')
			{
				result = 0;
				break;
			}
			else
			{
				s.pop();
				if(input[i - 1] == '(')
				{
					result += tmp;
					tmp /= 2;
				}
				else tmp /= 2;
			}
		}
		else
		{
			if(s.empty() || s.top() != '[')
			{
				result = 0;
				break;
			}
			else
			{
				s.pop();
				if(input[i - 1] == '[')
				{
					result += tmp;
					tmp /= 3;
				}
				else tmp /= 3;
			}
		}
	}
	if(!s.empty()) result = 0;
	cout << result;
}
