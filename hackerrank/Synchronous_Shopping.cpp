#include <bits/stdc++.h>

//작성중

#define MAX_NODE 1001
#define MAX_ROAD 2001

using namespace std;

vector<vector<int>> node(MAX_NODE);
vector<pair<int,int>> graph[MAX_ROAD];
vector<int> dist(MAX_NODE);
priority_queue<pair<int, int>> qu;


void dijkstra(){
    int start = 1;
    qu.push({0, start});
    dist[start]=0;
    while(!qu.empty()){
//        int cost =-qu.top().first;
        int here=qu.top().second;
        
        qu.pop();
        
        for(int i=0;i<graph[here].size();i++){
            int next = graph[here][i].first;
            int nextcost = graph[here][i].second;
            if(dist[next]>dist[here]+nextcost){
                dist[next] = dist[here]+nextcost;
                qu.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for(int j=0;j<num;j++) {
            int data;
            cin >> data;
            node[i].push_back(data);
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    
    dist.assign(n+1, 10001);
    dijkstra();
    
    for(int i=1;i<=n;i++) cout << dist[i]; //test
    
    
    
    
    return 0;
}
