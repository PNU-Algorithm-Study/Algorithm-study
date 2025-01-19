#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> graph;
vector<vector<int> > v;
vector<tuple<int, int, int, int>> turn;
queue<pair<int,int> >q;
int answer=0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
void funct();
int main()
{
    cin >> n >> m;  
    int x, y, a, b; 
    graph.assign(n+1,vector<int>(n+1,0));
    v.assign(n+1,vector<int>(n+1,0));
    for (int test = 0; test < m; test++)
    {
        cin >> x >> y >> a >> b;
        turn.emplace_back(x, y, a, b);
    }
    funct();
    cout<<answer<<endl;
}
void funct(){    
    v[1][1]=true;
    q.push(make_pair(1,1)); 
    graph[1][1]=1;
    answer++;
    while(!q.empty()){
        int row = q.front().first,col = q.front().second;
        q.pop();
        for(auto a: turn){ 
            if(get<0>(a)==row && get<1>(a)==col){
                int mrow = get<2>(a), mcol = get<3>(a);
                if(graph[mrow][mcol]) 
                    continue;
                answer++; 
                graph[mrow][mcol]=1; 
                for(int d=0; d<4; d++){ 
                    int trow = mrow+dir[d][0], tcol = mcol+dir[d][1];
                    if(trow < 1 || trow>n || tcol<1 || tcol>n)
                        continue;
                    if(v[trow][tcol]){ 
                        q.push(make_pair(mrow,mcol)); 
                        v[mrow][mcol]=1;
                        break;
                    }
                }
            }
        }
        for(int d=0; d<4; d++){ 
            int trow = row+dir[d][0], tcol = col+dir[d][1];
            if(trow<1 || trow>n || tcol<1 || tcol>n)
                continue;
            if(!graph[trow][tcol] || v[trow][tcol]) 
                continue;
            q.push(make_pair(trow,tcol));
            v[trow][tcol]=1;
        }
    }
}
