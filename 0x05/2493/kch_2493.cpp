#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack<pair<int, int>> S;

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
    {
		int tower;
		cin >> tower;
		while (!S.empty()) 
        {
			if (S.top().second > tower) 
            {
				cout << S.top().first << ' ';
				break;
			}
			S.pop();
		}
		if (S.empty()) cout << '0' << ' ';
		S.push(make_pair(i, tower));
	}
}