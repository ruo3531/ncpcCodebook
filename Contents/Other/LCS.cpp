int n1 = s1.size(), n2 = s2.size();
    int dp[N][N] = {};
    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    }
}
#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005] = {0};

int main(){
	string a, b;
    while(getline(cin, a) && getline(cin, b)){
        memset(dp, 0, sizeof(dp));
        int asize = a.size(), bsize = b.size();
        for(int i = 1; i <= asize; i++){
            for(int j = 1; j <= bsize; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[asize][bsize] << '\n';
    }

}