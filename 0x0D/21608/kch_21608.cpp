#include <bits/stdc++.h>
using namespace std;

const int MX = 20;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, u, v, mx, ans;

int score[MX + 2][MX + 2];
int vctcnt[MX + 2][MX + 2];
int b[MX + 2][MX + 2];
int pref[MX*MX + 2][4];

pair<int, int> ps[MX*MX + 2];
vector<tuple<int, int, int>> cand;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

void setup() {
  cin >> n;
  for(int i = 1; i <= n*n; i++)
    ps[i] = {-1, -1};

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      vctcnt[i][j] = 4;
      if(i == 0 || i == n - 1) vctcnt[i][j]--;
      if(j == 0 || j == n - 1) vctcnt[i][j]--;
    }
}

void init() {
  for(int i = 0; i < n; i++)
    fill(score[i], score[i] + n, 0);
  mx = 0;
  cand.clear();
}

void setprefer() {
  cin >> u;
  for(int j = 0; j < 4; j++) {
    cin >> v;
    pref[u][j] = v;
    auto [cx, cy] = ps[v];
    if(cx == -1 && cy == -1) continue;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(OOB(nx, ny) || b[nx][ny]) continue;
      score[nx][ny]++;
      mx = max(mx, score[nx][ny]);
    }
  }
}

void setseat() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(mx == score[i][j] && !b[i][j])
        cand.push_back({-vctcnt[i][j], i, j});

  sort(cand.begin(), cand.end());
  auto [vcnt, x, y] = cand[0];

  ps[u] = pair<int, int>(x, y);
  b[x][y] = u;

  for(int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(OOB(nx, ny)) continue;
    vctcnt[nx][ny]--;
  }
}

void calc() {
  for(int i = 1; i <= n*n; i++) {
    int cnt = 0;
    auto [cx, cy] = ps[i];
    for(int j = 0; j < 4; j++) {
      auto [nx, ny] = ps[pref[i][j]];
      if(abs(nx - cx) + abs(ny - cy) != 1) continue;
      cnt++;
    }
    if(!cnt) continue;
    int a = 1;
    while(--cnt) a *= 10;
    ans += a;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  for (int i = 1; i <= n*n; i++) {
    init();
    setprefer();
    setseat();
  }
  calc();
  cout << ans;
}
