#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void)
{
	int i,j;
	int t;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		string vps;
		stack<char>ps;
		cin >> vps;
        
		for (j = 0; j < vps.size(); j++)	
		{
			if (vps.at(j) == '(')
				ps.push('(');
			else
			{
				if (ps.empty())		
					break;
				ps.pop();
			}
		}
        
		if (j == vps.size()&&ps.empty())		//	문자열의 검사가 정상적으로 이루어지고 스택도 비어있을 때
			cout << "YES\n";
		else
			cout << "NO\n";
            
	}
	return 0;
}
