const int INF = 1e9;
const int MAXN = 1000;
struct Edge {
    int v;
    int w;
};
int n, m;
vector<Edge> G[MAXN];   //向量記圖
int dis[MAXN];
void SPFA(int s) {
    // 記錄目前的點是否在 queue 中
    bool inq[n];
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        inq[i] = false;
    }
    dis[s] = 0;
    inq[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (Edge e : G[u]) {
            if (dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                if (!inq[e.v]) {
                    inq[e.v] = true;
                    q.push(e.v);
                }
            }
        }
    }
}

/*
Bellmam Ford / SPFA 偵測負環

如果有一個點被放到 queue 裡面超過V次,那麼有負環
最大負環為包含所有點的環,共有V條邊,被更新V次
,在極端的例子,被長度為1.2..3..V的路徑都
被更新一次最短距離。

比較
Floyd: ,需要計算許多點對的距離。
Dijkstra:沒有負邊且起點固定。
Bellmam Ford / SPFA:其他狀況。
*/