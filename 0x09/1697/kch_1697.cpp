#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int N, K; 
int visited[MAX] = {};

int bfs() {
    queue<int> q; 
    q.push(N);
    visited[N] = 0;
    while (!q.empty()) {
        int curPosition = q.front();
        q.pop();

        if (curPosition == K) break;

        int minusPosition = curPosition - 1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        if (minusPosition >= 0 && visited[minusPosition] == 0) {
            q.push(minusPosition);
            visited[minusPosition] = visited[curPosition] + 1;
        }

        if (plusPosition < MAX && visited[plusPosition] == 0){
            q.push(plusPosition);
            visited[plusPosition] = visited[curPosition] + 1;
        }

        if (multiPosition < MAX && visited[multiPosition] == 0) {
            q.push(multiPosition);
            visited[multiPosition] = visited[curPosition] + 1;
        }
    }

    return visited[K];
}

int main() {
    cin >> N >> K;
    cout << bfs();

    return 0;
}
 