#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {0,0,1,-1};
int dy[8] = {1,-1,0,0};

queue<pair<int, int>> q;
queue<pair<int, int>> s;

char board[1002][1002];
int fire[1002][1002];
int jihun[1002][1002];

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool success = false;
        while(!q.empty()) q.pop();
        while(!s.empty()) s.pop();
        
        int r,c;
        cin >> c >> r;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> board[i][j];
                
                fire[i][j] = -1;
                jihun[i][j] = -1;
                
                if(board[i][j] == '*'){
                    q.push({i,j});
                    fire[i][j] = 0;
                }
                if(board[i][j] == '@') {
                    s.push({i,j});
                    jihun[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int, int> current = q.front();
            q.pop();
            
            for(int dir=0; dir<4; dir++){
                int x = current.first + dx[dir];
                int y = current.second + dy[dir];
                
                if(x<0 || x>=r || y<0 || y>=c) continue;
                if(fire[x][y] >= 0 || board[x][y] == '#') continue; // 이미 불이 있거나 벽이라면 패스
                
                fire[x][y] = fire[current.first][current.second] + 1;
                q.push({x,y});
            }
        }
        
        while(!s.empty() && !success) {
            pair<int, int> current = s.front();
            s.pop();
            
            for(int dir=0; dir<4; dir++){
                int x = current.first + dx[dir];
                int y = current.second + dy[dir];
                
                if(x<0 || x>=r || y<0 || y>=c) {
                    cout << jihun[current.first][current.second] + 1 << "\n";
                    success = true;
                    break;
                }
                
                if(jihun[x][y] >= 0 || board[x][y] == '#') continue;
                
                if(fire[x][y] != -1 && jihun[current.first][current.second] + 1 >= fire[x][y]) continue;
                
                jihun[x][y] = jihun[current.first][current.second] + 1;
                s.push({x,y});
            }
        }
        
        if(!success)
            cout << "IMPOSSIBLE\n";
    }
        return 0;
}
