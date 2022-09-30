#include<bits/stdc++.h>
using namespace std;

#define M 1005

int arr[M][M] = {0};
int movei[4]={1,0,-1,0};
int movej[4]={0,1,0,-1};

struct point{
	int I, J, n;
	point(){};
	point(int I, int J, int n):I(I), J(J), n(n){};
};

int main(){
	int Cas;
	cin >> Cas;
	while(Cas--){
		memset(arr, 0, sizeof(arr));
		queue<point> walk;
		queue<point> fire;
		int r, c;
		cin >> r >> c;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				char tmp;
				cin >> tmp;
				if(tmp == '#') arr[i][j] = -1;
				if(tmp == 'F'){
					arr[i][j] = 1;
					fire.push(point(i, j, 0));
				}
				if(tmp == 'J'){
					arr[i][j] = 2;
					walk.push(point(i, j, 0));
				}
			}
		}
		int ans = 0;
		while(!walk.empty()){
			point now = walk.front();
			walk.pop();
			if(now.I == r-1 || now.I == 0 || now.J == c-1 || now.J == 0){
				ans = now.n+1;
				break;
			}
			while(fire.front().n == now.n){
				point tmp = fire.front();
				fire.pop();
				for(int i = 0; i < 4; i++){
					int tmpi = tmp.I+movei[i];
					int tmpj = tmp.J+movej[i];
					if(tmpi < r && tmpi >= 0 && tmpj < c && tmpj >= 0){
						if(arr[tmpi][tmpj] == 0){
							arr[tmpi][tmpj] = 1;
							fire.push(point(tmpi, tmpj, tmp.n+1));
						}
					}
				}
			}
			for(int i = 0; i < 4; i++){
				int tmpi = now.I+movei[i];
				int tmpj = now.J+movej[i];
				if(tmpi < r && tmpi >= 0 && tmpj < c && tmpj >= 0){
					if(arr[tmpi][tmpj] == 0){
						walk.push(point(tmpi, tmpj, now.n+1));
					}
				}
			}
		}
		if(ans) cout << ans << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}