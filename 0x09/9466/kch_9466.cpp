#include <iostream>
#include <cstring>
#define MAX 100001

using namespace std;

int arrStudent[MAX];
bool visited[MAX]; 
bool done[MAX]; 
int result; 


void dfs(int current) {
    visited[current] = true;    

    if (!visited[arrStudent[current]]) { 
        dfs(arrStudent[current]);
    } else if (!done[arrStudent[current]]) { 
        for (int i = arrStudent[current]; i != current; i = arrStudent[i]) { 
            result += 1; 
        }
        result += 1; 
    }

    done[current] = true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> arrStudent[j];
        }

        result = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof done);


        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                dfs(j);
            }
        }
        cout << n - result << endl;
    }

    return 0;
}
