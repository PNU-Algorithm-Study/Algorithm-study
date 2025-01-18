#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    int bitLimit = 2;
    while(bitLimit <= N) bitLimit <<= 1;
    
    int dist[bitLimit];
    for(int i=0; i<bitLimit; i++) dist[i] = 0;

    queue<int> Q;
    while(M--) {
        int x; cin >> x;
        dist[x] = 1;
        Q.push(x);
    }

    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int b = 1; b < bitLimit; (b <<= 1)) {
            int nx = x ^ b;
            if(dist[nx]) continue;
            dist[nx] = dist[x] + 1;
            Q.push(nx);
        }
    }

    int ans = 0;
    for(int i=0; i<=N; i++)
        if(dist[i] > ans) ans = dist[i];
    cout << ans - 1;
}
