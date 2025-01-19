#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
 
int n, m, p;
int howmanycango[10];
int dap[10];
char graph[1001][1001];
queue<tuple<int, int, int, int>> q;
queue<tuple<int, int, int, int>> imsi;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visited[1001][1001];
 
void bfs() {
    while (!q.empty()) {
        for (int k = 1; k <= p; k++) {
            while (1) {
                int imsix, imsiy, imsinum, imsicnt;
                if (q.empty()) break;
                tie(imsix, imsiy, imsinum, imsicnt) = q.front();
                if (imsinum == k) {
                    imsi.push({ imsix, imsiy, imsinum, imsicnt });
                    q.pop();
                    
                }
                else break;
            }
            
            while (!imsi.empty()) {
                int x, y, num, cnt;
                tie(x, y, num, cnt) = imsi.front();
                imsi.pop();
 
                if (cnt == howmanycango[num]) {
                    for (int idx = 0; idx < 4; idx++) {
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if (visited[nx][ny]) continue;
                        if (graph[nx][ny] == '.') {
                            q.push({ x,y,num,0 });
                        }
                    }
                }
                else if (cnt < howmanycango[num]) {
                    for (int idx = 0; idx < 4; idx++) {
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if (visited[nx][ny]) continue;
                        if (graph[nx][ny] == '.') {
                            visited[nx][ny] = true;
                            graph[nx][ny] = num + '0';
                            int cntp = cnt + 1;
                            imsi.push({ nx,ny,num,cntp });
                        }
                    }
                }
                
                
            }
            
 
        }
 
    }
}
 
 
int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) cin >> howmanycango[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }
    
    for (int idx = 1; idx <= p; idx++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (graph[i][j] == idx + '0') {
                    q.push({ i,j,idx,0 });
                    visited[i][j] = true;
                }
            }
        }
    }
 
    bfs();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ('1' <= graph[i][j] && graph[i][j] <= '9') {
                dap[graph[i][j] - '0']++;
            }
        }
    }
 
    for (int i = 1; i <= p; i++) cout << dap[i] << ' ';
}
