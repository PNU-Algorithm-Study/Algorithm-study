#include <iostream>
#include <stack>
using namespace std;

int main(void) 
{
	int n, result = 0;
	cin >> n;
	while(n--)
	{
		stack<char> s;
		string input;
		cin >> input;
		for(int i = 0; i < input.size(); i++)
		{
			if(s.empty()) s.push(input[i]);
			else
			{
				if(s.top() == input[i]) s.pop();
				else s.push(input[i]);
			}
		}
		if(s.empty()) result++;
	}
	cout << result;
}
