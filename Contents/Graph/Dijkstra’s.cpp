#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define INF 1e9
struct Edge{
    int v, w;
    Edge(int a, int b):v(a), w(b){};
};
struct node{
    int u, dis;
    node(){};
    node(int a, int b):u(a), dis(b){};
    bool operator<(const node &r)const{
        return dis > r.dis;
    }
};
int dis[M]; //距離
vector<Edge> G[M];
void init(){
    fill(dis, dis+M, INF);
    for(int i = 0; i < M; i++){
        G[i].clear();
    }
}
void dijkstra(int start){
    dis[start] = 0;
    priority_queue<node> pq;
    pq.push(node(start, 0));
    while(!pq.empty()){
        node now = pq.top();
        pq.pop();
        if(now.dis > dis[now.u]) continue;
        for(Edge i : G[now.u]){
            if(dis[i.v] > now.dis + i.w){
                dis[i.v] = now.dis + i.w;
                pq.push(node(i.v, dis[i.v]));
                // printf("push(%d, %d)\n", i.v, dis[i.v]);
            }
        }
    }
}

int main(){
	int point, side;
    cin >> point >> side;
    init();
    for(int i = 0; i < side; i++){
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }
    dijkstra(1);
    for(int i = 2; i <= point; i++){
        cout << dis[i] << '\n';
    }

}