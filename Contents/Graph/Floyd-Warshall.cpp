#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define INF 1e9

int dis[M][M];
// int G[M][M];
void init(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dis[i][j] = INF;
            if(i == j) dis[i][j] = 0;
        }
    }
}
void Floyd(int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dis[i][j]= dis[j][i] = min(dis[i][k]+dis[k][j], dis[i][j]);
            }
        }
    }
}
void printarr(int r, int c){
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(dis[i][j] == INF) cout << "INF ";
            else cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
	int point, side;
    cin >> point >> side;
    init(point);
    for(int i = 0; i < side; i++){
        int s, t, w;
        cin >> s >> t >> w;
        dis[s][t] = w;
        dis[t][s] = w;
    }
    Floyd(point);
    int Cas;
    cin >> Cas;
    while(Cas--){
        int i, j;
        cin >> i >> j;
        cout << dis[i][j] << '\n';
    }
    // printarr(point, point);

}