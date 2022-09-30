#include<iostream>
using namespace std;
const int INF = 1e9;
const int MAXN = 1000;
const int MAXM = 1000;
struct Edge {
    int u;
    int v;
    int w;
};

int n, m;
Edge edges[MAXM];
int dis[MAXN];

// s是起點
bool bellman(int s) {
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
    }
    dis[s] = 0;
    bool relax;
    // 做 n 輪
    for (int i = 0; i < n; i++) {
        relax = false;
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dis[u] == INF) {
                continue;
            }
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                relax = true;
            }
        }
        if (!relax) {
            break;
        }
    }
    return relax;
}


int main(){

}
