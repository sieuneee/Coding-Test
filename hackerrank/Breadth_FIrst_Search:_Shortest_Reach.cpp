#include <bits/stdc++.h>

#define MAX_NODE 1001
#define MAX_EDGE 500000

using namespace std;

vector<vector<pair<int, int>>> graph(MAX_NODE);
vector<int> dist(MAX_NODE);
int n, m;
priority_queue<pair<int, int>> qu;

void func(int start){
    qu.push({0, start});
    dist[start]=0;
    
    while(!qu.empty()){
//        int cost=-qu.top().first;
        int here = qu.top().second;
        qu.pop();
        for(int i=0;i<graph[here].size();i++){
            int next = graph[here][i].first;
            int nextcost = graph[here][i].second;
            if(dist[next]>dist[here]+nextcost || dist[next]==-1){
                dist[next] = dist[here]+nextcost;
                qu.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    int TC;
    cin >> TC;
    for(int i=0;i<TC;i++){
        cin >> n >> m;
        dist.assign(n+1, -1);
        graph.assign(n+1, vector<pair<int, int>>());
        for(int j=0;j<m;j++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back({b, 6});
            graph[b].push_back({a, 6});
        }
        int start;
        cin >> start;
        func(start);
        
        for(int j=1;j<=n;j++) {
            if(j!=start)
                cout << dist[j] << " ";
        }
        cout << "\n";
    }
    
}
