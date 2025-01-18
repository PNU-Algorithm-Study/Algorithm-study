#include <iostream>
#include <deque>

using namespace std;

int N, K, res = 0;
bool check[100001];

void bfs() {
    deque<pair<int, int>> q;

    check[N] = true;
    q.push_back({ N,0 });

    while (!q.empty()) {
        int n = q.front().first;
        int time = q.front().second;

        q.pop_front();

        if (n == K) {
            res = time;
            break;
        }

        if (n * 2 < 100001 && !check[n * 2]) {
            check[n * 2] = true;
            q.push_front({ n * 2,time });
        }

        if (n + 1 < 100001 && !check[n + 1]) {
            check[n + 1] = true;
            q.push_back({ n + 1,time + 1 });
        }

        if (n - 1 >= 0 && !check[n - 1]) {
            check[n - 1] = true;
            q.push_back({ n - 1,time + 1 });
        }
    }
}

void solution() {
    bfs();

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    solution();

    return 0;
}
