#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int shk = 17;

vector<vector<pair<int, int>>> board(4);
vector<pair<int, int>> coord;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool oob(int x, int y) {
  return x >= 4 || x < 0 || y >= 4 || y < 0;
}

int solve(vector<vector<pair<int, int>>> b, vector<pair<int, int>> co) {
  for (int no = 1; no <= 16; no++) {
    auto [cx, cy] = co[no];
    if (cx == -1 || cy == -1) continue;
    int dir = b[cx][cy].Y;
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    while (oob(nx, ny) || b[nx][ny].X == shk) {
      dir = (dir + 1) % 8;
      nx = cx + dx[dir];
      ny = cy + dy[dir];
    }
    b[cx][cy].Y = dir;

    co[no] = {nx, ny};
    co[b[nx][ny].X] = {cx, cy};
    b[cx][cy] = b[nx][ny];
    b[nx][ny] = {no, dir};
  }

  int ans = 0;
  auto [cx, cy] = co[shk];
  int dir = b[cx][cy].Y;
  for (int p = 1; p <= 3; p++) {
    int nx = cx + p * dx[dir];
    int ny = cy + p * dy[dir];
    if (oob(nx, ny) || !b[nx][ny].X) continue;

    vector<vector<pair<int, int>>> tmpb = b;
    vector<pair<int, int>> tmpco = co;
    int no = tmpb[nx][ny].X;
    tmpb[nx][ny].X = shk;
    tmpco[shk] = {nx, ny};
    tmpco[no] = {-1, -1};
    tmpb[cx][cy] = {0, 0};
    ans = max(ans, no + solve(tmpb, tmpco));
  }
  return ans;
}

void setup() {
  coord.resize(19);
  for (int i = 0; i < 4; i++) {
    board[i].resize(4);
    for (int j = 0; j < 4; j++) {
      int no, dir; cin >> no >> dir;
      board[i][j] = {no, dir - 1};
      coord[no] = {i, j};
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  int no = board[0][0].X;
  board[0][0].X = shk;
  coord[no] = {-1, -1};
  coord[shk] = {0, 0};
  cout << no + solve(board, coord) << '\n';
}
