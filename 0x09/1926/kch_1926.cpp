#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
    Pos(int x, int y) { 
        this->x = x;
        this->y = y;
    }
    
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> canvas(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> canvas[i][j];
        }
    }

    /* BFS */
    int max = 0;
    int count = 0;

    int dirX[4] = { -1, 1, 0, 0 };   // 좌우
    int dirY[4] = { 0, 0, -1, 1 };   // 상하

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            /* 이미 방문 했거나 그림이 없는 위치면 스킵 */
            if (visited[i][j] || canvas[i][j] != 1) continue;

            /* 시작 위치 방문 설정 */
            count++;
            queue<Pos> q;
            q.push(Pos(i, j));
            visited[i][j] = true;

            int size = 0;
            while (!q.empty()) {
                size++;
                Pos currPos = q.front();
                q.pop();

                for (int dir = 0; dir < 4; ++dir) {
                    int nextX = currPos.x + dirX[dir];
                    int nextY = currPos.y + dirY[dir];

                    if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
                    if (visited[nextX][nextY] || canvas[nextX][nextY] != 1) continue;

                    visited[nextX][nextY] = true;
                    q.push(Pos(nextX, nextY));
                }

                if (max < size) 
                    max = size;
            }
        }
    }

    cout << count << "\n" << max;
    return 0;
}
