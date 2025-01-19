#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include<cstring>
using namespace std;

char board[1500][1500] = { '.' };
int visitwater[1500][1500] = { 0 };
int visitswan[1500][1500] = { 0 };
int R, C;
int m = 0;
int startX, startY, endX, endY;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int day = 0;

queue<pair<int, int>> waterq;  
queue<pair<int, int>> swanq;   

void watermelt() {
	while (1) {
		day++;
		queue<pair<int, int>> tmp;
		while (!waterq.empty()) {
			
			int x = waterq.front().first;
			int y = waterq.front().second;
			waterq.pop();
		
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx > C - 1 || ny < 0 || ny > R - 1)
					continue;
				if (visitwater[ny][nx])
					continue;
				if (board[ny][nx] == 'X') {
					tmp.push({ nx, ny });  
					visitwater[ny][nx] = visitwater[y][x] + 1;
					board[ny][nx] = '.';
				}
			}
		}
		waterq = tmp;
		while (!tmp.empty()) {
			tmp.pop();
		}

		while (!swanq.empty()) {
			int x = swanq.front().first;
			int y = swanq.front().second;
			swanq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx > C - 1 || ny < 0 || ny > R - 1)
					continue;
				if (visitswan[ny][nx])
					continue;
				if (board[ny][nx] == 'X') {
					tmp.push({ nx, ny });
					visitswan[ny][nx] = visitswan[y][x] + 1;
				}
				else if (board[ny][nx] == '.') {
					swanq.push({ nx, ny });
					visitswan[ny][nx] = visitswan[y][x] + 1;
				}
				else if (ny == endY && nx == endX) {

					return;
				}
				
			}
		}
		swanq = tmp;
	}
	
}

int main() {
	char symbol;
	cin >> R >> C;
	int flag = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> symbol;
			board[i][j] = symbol;
			if (symbol == 'L') {
				if (flag == 0)
				{
					startX = j;
					startY = i;
					waterq.push({ j, i });
					visitwater[i][j] = 1;
					swanq.push({ j, i });
					visitswan[i][j] = 1;
					flag = 1;
				}
				else
				{
					endX = j;
					endY = i;
					waterq.push({ j, i });
					visitwater[i][j] = 1;
				}
			}
			else if (symbol == '.') {
				waterq.push({ j, i });
				visitwater[i][j] = 1;
			}
		}
	}
	watermelt();
	cout << day;

}
