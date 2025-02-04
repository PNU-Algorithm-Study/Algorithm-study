#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack<pair<int, int>> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		while(!s.empty())
		{
			if(input > s.top().second) s.pop();
			else
			{
				cout << s.top().first << ' ';
				break;
			}
		}
		if(s.empty()) cout << '0' << ' ';
		s.push(make_pair(i, input));
	}
}
