#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int N;
char r_b_blind_area[101][101];
char general_area[101][101];
bool visited[101][101];


 void bfs(int row, int col, int flag) {
    queue<pair<int ,int> > q;
    q.push(make_pair(row, col));
    visited[row][col] = true; 
    char area[101][101];

    if (flag == 1) {  
        memcpy(area, general_area, sizeof(general_area));
    } else {           
        memcpy(area, r_b_blind_area, sizeof(r_b_blind_area));
    }

    while(!q.empty()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();

        int next_row, next_col;
        for (int i = 0; i < 4; i++) {
            next_row = cur_row + dr[i];
            next_col = cur_col + dc[i];

            if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N) continue;

            if (area[next_row][next_col] == area[cur_row][cur_col] && !visited[next_row][next_col]) {
                q.push(make_pair(next_row, next_col));
                visited[next_row][next_col] = true;
            }
        }
    }

}

void reset() {
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == 'G') { 
                r_b_blind_area[i][j] = 'R';
                general_area[i][j] = str[j];
            } else {
                r_b_blind_area[i][j] = str[j];
                general_area[i][j] = str[j];
            }
        }
    }

    reset();
    int result1 = 0;
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i,j, 1);
                result1 += 1;
            }
        }
    }

    reset();
    int result2 = 0;
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i,j, 2);
                result2 += 1;
            }
        }
    }

    cout << result1 << endl;
    cout << result2 << endl;
    return 0;
}
