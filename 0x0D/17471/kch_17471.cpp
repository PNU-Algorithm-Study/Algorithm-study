#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MX = 10;

int n, ans = INF;
int viscnt;

int po[MX + 2];
bool vis[MX + 2];

vector<bool> comb;
vector<int> adj[MX + 2];

queue<int> q;

void bfs(int st) {
  bool code = comb[st];
  vis[st] = 1;
  viscnt++;
  q.push(st);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(vis[nxt] || comb[nxt] != code) continue;
      vis[nxt] = 1;
      viscnt++;
      q.push(nxt);
    }
  }
}

void solve(int m) {
  fill(comb.begin(), comb.end(), 0);

  for(int i = n - m; i < n; i++)
    comb[i] = 1;
  
  do {
    viscnt = 0;
    fill(vis, vis + n, 0);

    for(int i = 0; i < n; i++)
      if(!comb[i]) { bfs(i); break; }
    for(int i = 0; i < n; i++)
      if(comb[i]) { bfs(i); break; }

    if(viscnt != n) continue;

    int tmp = 0;
    for(int i = 0; i < n; i++) {
      if(comb[i]) tmp += po[i];
      else tmp -= po[i];
    }
    tmp = abs(tmp);
    ans = min(tmp, ans);
  } while(next_permutation(comb.begin(), comb.end()));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> po[i];
  for(int i = 0; i < n; i++) {
    int m; cin >> m;
    while(m--) {
      int x; cin >> x;
      adj[i].push_back(x - 1);
    }
  }

  comb.resize(n);
  for(int i = 1; i <= n / 2; i++)
    solve(i);
  if(ans == INF) ans = -1;
  cout << ans;
}
