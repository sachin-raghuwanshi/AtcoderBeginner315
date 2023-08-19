#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1000000007;
vector<vector<int>>cord;
double dp[10005][29][29];
int n;

double dis(int i, int j) {
    return sqrt((double)(cord[i][0] - cord[j][0]) * (cord[i][0] - cord[j][0]) + (double)(cord[i][1] - cord[j][1]) * (cord[i][1] - cord[j][1]));
}
double solve(int i , int skip, int lastSkip) {
    int last = i - lastSkip - 1;
    if(skip > 27) {
        return 1e9;
    }
    if(i == n - 1) {
        if(skip == 0) return dis(last, n - 1);
        return dis(last, n - 1) + (1 << (skip - 1));
    }
    if(dp[i][skip][lastSkip] >= 0) return dp[i][skip][lastSkip];
    
    double take = dis(last, i) + solve(i + 1, skip, 0 );
    double notTake = solve(i + 1, skip + 1, lastSkip + 1);
    return dp[i][skip][lastSkip] = min(take, notTake);
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 28; j++ ) {
            for(int k = 0; k <= 28; k++) {
                dp[i][j][k] = -1.0;
            }
        }
    }
    cord = vector<vector<int>>(n +1, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> cord[i][0] >> cord[i][1];
    }
    cout << setprecision(16) << solve(1, 0, 0);
    
}
