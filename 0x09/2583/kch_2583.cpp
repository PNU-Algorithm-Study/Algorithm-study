#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int arr[101][101];
int dirX[] = { 0, 0, -1, 1 };
int dirY[] = { -1, 1, 0, 0 };
int cnt = 0;
vector<int> result;

int dfs(int y, int x)
{
	arr[y][x] = 1;
	cnt++;
    
	for (int i = 0; i < 4; i++)
	{
		int _y = y + dirY[i];
		int _x = x + dirX[i];
         
		if (_y >= 0 && _y < m && _x >= 0 && _x < n)
		{ 
			if (arr[_y][_x] == 0)
				dfs(_y, _x);
		}
	}
	return cnt;
}

int main()
{
	cin >> m >> n >> k;

	int x1, x2, y1, y2;
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				arr[y][x] = 1;
			}
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{	
				result.push_back(dfs(i, j));
				cnt = 0;
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	
}
