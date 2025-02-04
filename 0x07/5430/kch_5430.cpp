#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t, n;
	string p, arr;
	cin >> t;
	while(t--)
	{
		bool err = false, rev = true;
		deque<int> d;
		cin >> p >> n >> arr;
		string tmp = "";
		for(int i = 1; i < arr.size(); i++)
		{
			if((arr[i] == ',' || arr[i] == ']') && tmp != "")
			{
				d.push_back(stoi(tmp));
				tmp = "";
			}
			else tmp += arr[i];
		}
		for(int i = 0; i < p.size(); i++)
		{
			if(p[i] == 'R') rev = !rev;
			else
			{
				if(d.empty()) 
				{
					cout << "error" << '\n';
					err = true;
					break;
				}
				else
				{
					if(rev) d.pop_front();
					else d.pop_back();
				}
			}
		}
		if(err == false)
		{
			if(!rev) reverse(d.begin(), d.end());
			cout << '[';
			for(int i = 0; i < d.size(); i++) 
			{
				if(i == d.size() - 1) cout << d[i];
				else cout << d[i] << ",";
			}
			cout << ']' << '\n';
		}
	}
}
